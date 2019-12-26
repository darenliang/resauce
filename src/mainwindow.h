#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "aboutdialog.h"

#include <QMainWindow>
#include <QTreeWidgetItem>
#include <QFileInfo>
#include <QtWidgets/QMenu>

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

    void on_dirView_clicked(const QModelIndex &index);

    void on_openFolderButton_clicked();

    void on_rootFolderSearch_textEdited(const QString &arg1);

    void on_dirView_customContextMenuRequested(const QPoint &pos);

    void on_actionBack_triggered();

private:
    Ui::MainWindow *ui;

    AboutDialog about;

    QMenu folderContextMenu;

    void setItem(QTreeWidgetItem* item, QFileInfo& info, QFileInfo* parent);

    bool setDirectory(const QString &folderPath, bool manual);

    bool visitFolder(const QModelIndex &index);
};
#endif // MAINWINDOW_H
