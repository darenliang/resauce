#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "aboutdialog.h"

#include <QMainWindow>
#include <QTreeWidgetItem>
#include <QFileInfo>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionQuit_triggered();

    void on_actionAbout_triggered();

    void on_actionOpen_triggered();

    void on_rootFolderSearchButton_clicked();

    void on_rootFolderSearch_returnPressed();

    void on_openFolderButton_clicked();

private:
    Ui::MainWindow *ui;

    AboutDialog about;

    // Used as slot
    void on_dirView_selection_change(const QModelIndex &current, const QModelIndex& previous);

    void setItem(QTreeWidgetItem* item, QFileInfo& info, QFileInfo* parent);

    bool setDirectory(const QString &folderPath);
};
#endif // MAINWINDOW_H
