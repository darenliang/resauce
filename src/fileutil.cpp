#include "fileutil.h"

// Instantiate
QFileSystemModel FileUtil::model;

QIcon FileUtil::getIcon(QString file) {

    auto dex = model.index(file);

    return model.fileIcon(dex);

}

QIcon FileUtil::getIcon(QFileInfo file) { return getIcon(file.filePath()); }
