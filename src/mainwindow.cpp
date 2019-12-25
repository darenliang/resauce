#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "aboutdialog.h"
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
}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::on_actionQuit_triggered() {
    qDebug() << "Saved Folder: " << State::getFolderName();
    QApplication::quit();
}

void MainWindow::on_actionAbout_triggered() {
    AboutDialog aboutDialog;
    aboutDialog.exec();

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

void MainWindow::setFolder(const QString &folderName) {
    State::setFolderName(folderName);

    qDebug() << "Selected: " << folderName;

    QFileInfo inf{folderName};

    setItem(new QTreeWidgetItem(ui->fileTree), inf);
}

void MainWindow::on_actionOpen_triggered() {

    QString folderName = QFileDialog::getExistingDirectory(nullptr, ("Select Folder"), QDir::currentPath());

    if (folderName == nullptr) {
        return;
    }

    setFolder(folderName);

}
