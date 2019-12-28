#include "state.h"

QFileSystemModel State::directoryModel;
ResauceFileModel State::fileList;

QFileSystemModel &State::getDirectoryModel() {
    return directoryModel;
}

ResauceFileModel &State::getFileList() {
    return fileList;
}