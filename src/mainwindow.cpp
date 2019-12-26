#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "fileutil.h"
#include "state.h"

#include <QFileDialog>
#include <QFileSystemModel>
#include <QFileInfo>
#include <QDateTime>
#include <QDebug>
#include <QStandardPaths>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    ui->rootFolderSearch->setFocus();
    // Set default directory to be the user's home
    // This call is platform independent
    setDirectory(QStandardPaths::writableLocation(QStandardPaths::HomeLocation));

    // Make ui reactive to keyboard and mouse
    connect(ui->dirView->selectionModel(), &QItemSelectionModel::currentChanged, this, &MainWindow::dirView_selection_change);
}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::on_actionQuit_triggered() {
    QApplication::quit();
}

void MainWindow::on_actionAbout_triggered() {
    about.exec();
}

bool MainWindow::setDirectory(const QString &folderPath) {
    const QDir pathDir(folderPath);
    if (!pathDir.exists()) {
        return false;
    }
    QFileSystemModel &directoryModel = State::getDirectoryModel();
    directoryModel.setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
    ui->dirView->setModel(&directoryModel);
    QString path = pathDir.canonicalPath();
    ui->dirView->setRootIndex(directoryModel.setRootPath(path));
    ui->rootFolderSearch->setText(path);
    for (int i = 1; i < directoryModel.columnCount(); i++) {
        ui->dirView->hideColumn(i);
    }
    return true;
}

void MainWindow::on_actionOpen_triggered() {
    QString folderPath = QFileDialog::getExistingDirectory(nullptr, ("Select Folder"), QDir::homePath());
    if (folderPath == nullptr) {
        return;
    }
    setDirectory(folderPath);
}

void MainWindow::dirView_selection_change(const QModelIndex &current, const QModelIndex &previous) {
    QFileSystemModel &fileList = State::getFileList();
    fileList.setFilter(QDir::NoDotAndDotDot | QDir::Files);
    ui->fileView->setModel(&fileList);
    qDebug() << State::getDirectoryModel().fileInfo(current).canonicalFilePath();
    ui->fileView->setRootIndex(fileList.setRootPath(State::getDirectoryModel().fileInfo(current).canonicalFilePath()));
}



void MainWindow::on_rootFolderSearchButton_clicked() {
    QString folderPath = ui->rootFolderSearch->text();
    if (folderPath.length() == 0) {
        return;
    }
    setDirectory(folderPath);
}

void MainWindow::on_rootFolderSearch_returnPressed() {
    ui->rootFolderSearchButton->click();
}

void MainWindow::on_openFolderButton_clicked() {
    ui->actionOpen->trigger();
}
