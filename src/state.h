#ifndef STATE_H
#define STATE_H

#include <QtCore/QString>
#include <QtWidgets/QFileSystemModel>

class State {
    static QFileSystemModel directoryModel;
    static QFileSystemModel fileList;
public:
    static QFileSystemModel &getDirectoryModel();

    static void setDirectoryModel(const QString &fPath);

    static QFileSystemModel &getFileList();

    static void setFileList(const QString &fPath);
};

#endif //STATE_H
