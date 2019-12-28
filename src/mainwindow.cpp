#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "state.h"
#include "dirutil.h"

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

void MainWindow::resetDirectory(bool manual = false) {
    MainWindow::setDirectory(QStandardPaths::writableLocation(QStandardPaths::HomeLocation), manual);
}


void MainWindow::on_actionQuit_triggered() {
    QApplication::quit();
}

void MainWindow::on_actionAbout_triggered() {
    about.exec();
}

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

void MainWindow::on_actionOpen_triggered() {
    QString folderPath = QFileDialog::getExistingDirectory(nullptr, ("Select Folder"), QDir::homePath());
    if (folderPath == nullptr) {
        return;
    }
    setDirectory(folderPath);
}

void MainWindow::dirView_selection_change(const QModelIndex &current) {
    auto &fileList = State::getFileList();
    ui->fileView->setModel(&fileList);
    auto file = State::getDirectoryModel().fileInfo(current);
    qDebug() << file.absoluteFilePath();
    fileList.names().clear();
    QDirIterator iter{file.absoluteFilePath(), QDir::NoDotAndDotDot | QDir::Files};
    while (iter.hasNext()) {
        auto x = ResauceFileInfo(iter.next());
        x.new_name = x.fileName().toUpper();
        fileList.put(x);
    }
}

void MainWindow::on_rootFolderSearch_textEdited(const QString &folderPath) {
    if (folderPath.isEmpty()) {
        resetDirectory(true);
        return;
    }
    setDirectory(folderPath, true);
}

void MainWindow::on_dirView_customContextMenuRequested(const QPoint &pos) {
    QModelIndex index = ui->dirView->indexAt(pos);
    if (!index.isValid()) {
        return;
    }
    QMenu contextMenu;
    contextMenu.addAction("Set Root");
    QAction *contextAction = contextMenu.exec(ui->dirView->mapToGlobal(pos));

    if (contextAction) {
        if (contextAction->text().contains("Set Root")) {
            setDirectory(State::getDirectoryModel().fileInfo(index).canonicalFilePath());
        }
    }
}

void MainWindow::on_actionBack_triggered() {
    setDirectory(DirUtil::moveUpDir(State::getDirectoryModel().rootPath()));
}
