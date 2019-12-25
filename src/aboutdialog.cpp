#include "aboutdialog.h"
#include "ui_aboutdialog.h"
#include "info.h"

using namespace Info;

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);
    ui->nameLabel->setText(APP_NAME);
    ui->versionLabel->setText(VERSION);

    QString build("Built with Qt 5 on ");

    // __DATE__ is a GNU compiler #define
    build.append(__DATE__);

    ui->buildLabel->setText(build);
    ui->authorLabel->setText("Authors: " + AUTHORS);
    ui->website->setText("Website: " + WEBSITE);

}

AboutDialog::~AboutDialog()
{
    delete ui;
}
