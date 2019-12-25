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

    qDebug() << info.path();

    auto path = (parent == nullptr) ? info.absoluteFilePath() : info.absoluteFilePath().remove(
            parent->absoluteFilePath());

    item->setText(0, path);
    item->setIcon(0, FileUtil::getIcon(info.absoluteFilePath()));

    item->setText(2, QString::number(info.size()) + " bytes");
    item->setText(3, info.birthTime().toLocalTime().toString(Qt::DateFormat::TextDate));
    item->setText(4, info.lastModified().toLocalTime().toString(Qt::DateFormat::TextDate));

    if (info.isDir()) {

        QDirIterator it(info.absoluteFilePath());

        while (it.hasNext()) {

            QFileInfo f{it.next()};

            if (f.isDir()) {
                continue;
            }

            setItem(new QTreeWidgetItem(item), f, &info);

        }

    }

}

void MainWindow::on_actionOpen_triggered() {

    QString folderName = QFileDialog::getExistingDirectory(nullptr, ("Select Folder"), QDir::currentPath());

    State::setFolderName(folderName);

    qDebug() << "Selected: " << folderName;

    QFileInfo inf{folderName};

    setItem(new QTreeWidgetItem(ui->tree), inf);

}
