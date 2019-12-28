#include "resaucefileinfo.h"

ResauceFileInfo::ResauceFileInfo(const QString &file, const QString new_name) : QFileInfo(file) {

    this->new_name = new_name;

}

ResauceFileInfo::ResauceFileInfo(): QFileInfo() {}

QString ResauceFileInfo::fileNameWithoutExtension() {

    if (!fileName().contains('.')) {
        return "";
    }

    return fileName().left(fileName().lastIndexOf("."));

}

QString ResauceFileInfo::fileExtension() {

    if (fileName().contains('.')) {
        return fileName().right(fileName().length() - fileName().lastIndexOf("."));
    } else {
        return fileName();
    }

}

