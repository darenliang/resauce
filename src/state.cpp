#include <QtCore/QString>
#include "state.h"

QString State::folderName;

void State::setFolderName(QString &fName) {
    folderName = fName;
}

const QString State::getFolderName() {
    return folderName;
}
