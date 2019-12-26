#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "fileutil.h"
#include "state.h"

#include <QFileDialog>
#include <QFileSystemModel>
#include <QFileInfo>
#include <QDateTime>
#include <QDebug>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->rootFolderSearch->setFocus();
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

void MainWindow::setItem(QTreeWidgetItem *item, QFileInfo &info, QFileInfo *parent = nullptr) {

    qDebug() << info.absoluteFilePath();

    auto path = (parent == nullptr) ? info.absoluteFilePath() : info.absoluteFilePath().remove(
            parent->absoluteFilePath());

    item->setText(0, path);
    item->setIcon(0, FileUtil::getIcon(info));

    auto size = (info.size() == 0) ? "Unavailable" : QString::number(FileUtil::getDirSize(info) / 1000000.0, 'f', 2) +
                                                     " MB"; // Bytes to MB, round to two places

    item->setText(2, size);
    item->setText(3, (info.birthTime().isValid()) ? info.birthTime().toLocalTime().toString(Qt::DateFormat::TextDate)
                                                  : "Unavailable");
    item->setText(4, info.lastModified().toLocalTime().toString(Qt::DateFormat::TextDate));

    if (info.isDir()) {

        QDirIterator it{info.absoluteFilePath(), QDir::NoDotAndDotDot | QDir::AllEntries};

        while (it.hasNext()) {

            QFileInfo f{it.next()};

            if (f.isDir()) {
                continue;
            }

            setItem(new QTreeWidgetItem(item), f, &info);

        }

    }

}

/*
void MainWindow::setFolder(const QString &folderName) {
    State::setFolderPath(folderName);

    qDebug() << "Selected: " << folderName;

    QFileInfo inf{folderName};

    setItem(new QTreeWidgetItem(ui->fileTree), inf);
}
 */

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

void MainWindow::on_dirView_clicked(const QModelIndex &index) {
    QFileSystemModel &fileList = State::getFileList();
    fileList.setFilter(QDir::NoDotAndDotDot | QDir::Files);
    ui->fileView->setModel(&fileList);
    qDebug() << State::getDirectoryModel().fileInfo(index).canonicalFilePath();
    ui->fileView->setRootIndex(fileList.setRootPath(State::getDirectoryModel().fileInfo(index).canonicalFilePath()));
}

void MainWindow::on_rootFolderSearchButton_clicked()
{
    QString folderPath = ui->rootFolderSearch->text();
    setDirectory(folderPath);
}

void MainWindow::on_rootFolderSearch_returnPressed()
{
    ui->rootFolderSearchButton->click();
}

void MainWindow::on_openFolderButton_clicked()
{
    ui->actionOpen->trigger();
}
