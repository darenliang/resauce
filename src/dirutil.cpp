#include <QtCore/QString>
#include <QtCore/QDir>
#include "dirutil.h"


QString DirUtil::moveUpDir(const QString &folderPath) {
    QDir currDir = QDir(folderPath);
    currDir.cdUp();
    return currDir.canonicalPath();
}