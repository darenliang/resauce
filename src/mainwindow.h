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

    void on_toolButton_clicked();

    void on_dirView_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;

    AboutDialog about;

    void setItem(QTreeWidgetItem* item, QFileInfo& info, QFileInfo* parent);

    void setFolder(const QString& folderName);

    bool setDirectory(const QString &folderPath);
};
#endif // MAINWINDOW_H
