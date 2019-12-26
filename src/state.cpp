#include <QtCore/QString>
#include "state.h"

QFileSystemModel State::directoryModel;
QFileSystemModel State::fileList;

const QFileSystemModel &State::getDirectoryModel() {
    return directoryModel;
}

const QFileSystemModel &State::getFileList() {
    return fileList;
}
