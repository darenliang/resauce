#ifndef STATE_H
#define STATE_H

#include "resaucefilemodel.h"

#include <QtCore/QString>
#include <QtWidgets/QFileSystemModel>

class State {
    static QFileSystemModel directoryModel;
    static ResauceFileModel fileList;
public:
    static QFileSystemModel &getDirectoryModel();

    static void setDirectoryModel(const QString &fPath);

    static ResauceFileModel &getFileList();

    static void setFileList(const QString &fPath);
};

#endif //STATE_H
