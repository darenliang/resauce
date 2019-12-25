#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "aboutdialog.h"
#include "fileutil.h"

#include <QFileDialog>
#include <QFileSystemModel>
#include <QFileInfo>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionQuit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionAbout_triggered()
{
    AboutDialog aboutDialog;
    aboutDialog.exec();

}

void MainWindow::on_actionOpen_triggered()
{

    QString folderName = QFileDialog::getExistingDirectory(nullptr, ("Select Folder"), QDir::currentPath());

    QFileInfo inf{folderName};

    auto item = new QTreeWidgetItem(ui->tree);
    item->setText(0, folderName);
    item->setIcon(0, FileUtil::getIcon(folderName));
    item->setText(2, QString::number(inf.size()) + " bytes");
    item->setText(3, inf.created().toLocalTime().toString(Qt::DateFormat::TextDate));
    item->setText(4, inf.lastModified().toLocalTime().toString(Qt::DateFormat::TextDate));

}
