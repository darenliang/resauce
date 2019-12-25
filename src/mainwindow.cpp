#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "aboutdialog.h"
#include "fileutil.h"

#include <QFileDialog>
#include <QFileSystemModel>
#include <QFileInfo>
#include <QDateTime>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::on_actionQuit_triggered() {
    QApplication::quit();
}

void MainWindow::on_actionAbout_triggered() {
    AboutDialog aboutDialog;
    aboutDialog.exec();

}

void MainWindow::setItem(QTreeWidgetItem *item, QFileInfo &info) {

    qDebug() << info.path();

    item->setText(0, info.absoluteFilePath());
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

            setItem(new QTreeWidgetItem(item), f);

        }

    }

}

void MainWindow::on_actionOpen_triggered()
{

    QString folderName = QFileDialog::getExistingDirectory(nullptr, ("Select Folder"), QDir::currentPath());

    qDebug() << "Selected: " << folderName;

    QFileInfo inf{folderName};

    setItem(new QTreeWidgetItem(ui->tree), inf);

}
