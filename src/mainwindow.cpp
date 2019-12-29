/*
 * Copyright (C) 2019 Daren Liang, George Lewis
 *
 * This file is part of Resauce.
 *
 * Resauce is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Resauce is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Resauce.  If not, see <https://www.gnu.org/licenses/>.
 */


#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "state.h"
#include "dirutil.h"
#include "resaucer.h"

#include <QFileDialog>
#include <QFileSystemModel>
#include <QDateTime>
#include <QDebug>
#include <QStandardPaths>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    ui->rootFolderSearch->setFocus();
    // Set default directory to be the user's home
    // This call is platform independent
    resetDirectory(false);

    // Make ui reactive to keyboard and mouse
    connect(ui->dirView->selectionModel(), &QItemSelectionModel::currentChanged, this,
            &MainWindow::dirView_selection_change);
}

MainWindow::~MainWindow() {
    delete ui;
}

// Reset root directory to home path
void MainWindow::resetDirectory(bool manual = false) {
    MainWindow::setDirectory(QStandardPaths::writableLocation(QStandardPaths::HomeLocation), manual);
}

// Quite application on quit action
void MainWindow::on_actionQuit_triggered() {
    QApplication::quit();
}

// Open about dialog on about action
void MainWindow::on_actionAbout_triggered() {
    about.exec();
}

// Set root directory. Returns true for successful action and false for unsuccessful action.
bool MainWindow::setDirectory(const QString &folderPath, bool manual = false) {
    const QDir pathDir(folderPath);
    if (!pathDir.exists()) {
        return false;
    }
    // Copy!
    QFileSystemModel &directoryModel = State::getDirectoryModel();
    directoryModel.setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
    ui->dirView->setModel(&directoryModel);
    QString path = pathDir.canonicalPath();
    ui->dirView->setRootIndex(directoryModel.setRootPath(path));
    if (!manual) {
        ui->rootFolderSearch->setText(path);
    }
    for (int i = 1; i < directoryModel.columnCount(); i++) {
        ui->dirView->hideColumn(i);
    }
    return true;
}

// Open folder selection dialog and set directory to root
void MainWindow::on_actionOpen_triggered() {
    QString folderPath = QFileDialog::getExistingDirectory(nullptr, ("Select Folder"), QDir::homePath());
    if (folderPath == nullptr) {
        return;
    }
    setDirectory(folderPath);
}

// Handle folder selection in folder selection pane
void MainWindow::dirView_selection_change(const QModelIndex &current) {
    auto &fileList = State::getFileList();
    ui->fileView->setModel(&fileList);
    auto file = State::getDirectoryModel().fileInfo(current);
    qDebug() << file.absoluteFilePath();
    fileList.names().clear();

    Resaucer r;

    r.vars.append({"x", 0.0, 1.0});

    QDirIterator iter{file.absoluteFilePath(),
                      QDir::NoDotAndDotDot | QDir::Files}; // Create a dir iterator for the selected folder
    while (iter.hasNext()) {
        auto x = ResauceFileInfo(iter.next()); // Create file info
//        x.new_name = x.fileNameWithoutExtension().toUpper() +
//                     x.fileExtension(); // Assign new name, just making it all uppercase in the abscence of our renaming logic
//        fileList.put(x); // Add it to the model
        r.files.append(x);
    }

    r.process();

    for (auto rfi : r.files) {
        fileList.put(rfi);
    }

    fileList.updateLayout();
}

// Handle folder search on text edit
void MainWindow::on_rootFolderSearch_textEdited(const QString &folderPath) {
    if (folderPath.isEmpty()) {
        resetDirectory(true);
        return;
    }
    setDirectory(folderPath, true);
}

// Handles custom context menu in folder selection pane
void MainWindow::on_dirView_customContextMenuRequested(const QPoint &pos) {
    QModelIndex index = ui->dirView->indexAt(pos);
    if (!index.isValid()) {
        return;
    }

    // Create context menu
    QMenu contextMenu;
    contextMenu.addAction("Set Root");
    QAction *contextAction = contextMenu.exec(ui->dirView->mapToGlobal(pos));

    // Match selection with action
    if (contextAction) {
        if (contextAction->text().contains("Set Root")) {
            setDirectory(State::getDirectoryModel().fileInfo(index).canonicalFilePath());
        }
    }
}

// Handles back button trigger
void MainWindow::on_actionBack_triggered() {
    setDirectory(DirUtil::moveUpDir(State::getDirectoryModel().rootPath()));
}
