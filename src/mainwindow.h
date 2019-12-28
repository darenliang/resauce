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


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "aboutdialog.h"

#include <QMainWindow>
#include <QTreeWidgetItem>
#include <QFileInfo>
#include <QtWidgets/QFileSystemModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:

    void on_actionQuit_triggered();

    void on_actionAbout_triggered();

    void on_actionOpen_triggered();

    void dirView_selection_change(const QModelIndex &current);

    void on_rootFolderSearch_textEdited(const QString &folderPath);

    void on_dirView_customContextMenuRequested(const QPoint &pos);

    void on_actionBack_triggered();

private:
    Ui::MainWindow *ui;

    AboutDialog about;

    void setItem(QTreeWidgetItem *item, QFileInfo &info, QFileInfo *parent);

    bool setDirectory(const QString &folderPath, bool manual);

    void resetDirectory(bool manual);
};

#endif // MAINWINDOW_H
