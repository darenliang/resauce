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


#include "aboutdialog.h"
#include "ui_aboutdialog.h"
#include "info.h"

using namespace Info;

AboutDialog::AboutDialog(QWidget *parent) : QDialog(parent), ui(new Ui::AboutDialog) {
    ui->setupUi(this);
    ui->nameLabel->setText(APP_NAME);
    ui->versionLabel->setText(VERSION);
    ui->license->setText(LICENSE);

    QString build("Built with Qt 5 on ");

    // __DATE__ is a GNU compiler #define
    build.append(__DATE__);

    ui->buildLabel->setText(build);
    ui->authorLabel->setText("Authors: " + AUTHORS);

    // Make website clickable
    ui->website->setText("Website: <a href=\"" + WEBSITE + "\">" + WEBSITE + "</a>");
}

AboutDialog::~AboutDialog() {
    delete ui;
}
