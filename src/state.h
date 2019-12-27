#ifndef STATE_H
#define STATE_H

#include <QtCore/QString>
#include <QtWidgets/QFileSystemModel>

class State {
    static QFileSystemModel directoryModel;
    static QFileSystemModel fileList;
public:
    static QFileSystemModel &getDirectoryModel();

    static QFileSystemModel &getFileList();
};

#endif //STATE_H
