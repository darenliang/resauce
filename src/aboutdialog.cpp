#include "aboutdialog.h"
#include "ui_aboutdialog.h"
#include "info.h"

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);
    QLabel* nameLabel = this->findChild<QLabel*>("nameLabel");
    nameLabel->setText(APP_NAME);
    QLabel* versionLabel = this->findChild<QLabel*>("versionLabel");
    versionLabel->setText(VERSION);
    QLabel* buildLabel = this->findChild<QLabel*>("buildLabel");
    std::string buildLabelStr("Built with Qt 5 on ");
    buildLabelStr.append(BUILD_DATE);
    buildLabel->setText(buildLabelStr.c_str());
    QLabel* authorListLabel = this->findChild<QLabel*>("authorListLabel");
    authorListLabel->setText(AUTHORS);

}

AboutDialog::~AboutDialog()
{
    delete ui;
}
