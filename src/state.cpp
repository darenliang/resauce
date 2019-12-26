#include <QtCore/QString>
#include "state.h"

QFileSystemModel State::directoryModel;
QFileSystemModel State::fileList;

QFileSystemModel &State::getDirectoryModel() {
    return directoryModel;
}

QFileSystemModel &State::getFileList() {
    return fileList;
}
