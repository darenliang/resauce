#include <QtCore/QString>
#include "state.h"

void State::setFolderName(QString &fName) {
    folderName = fName;
}

QString State::getFolderName() {
    return folderName;
}