#include <QtCore/QString>
#include <QtCore/QDir>
#include "dirutil.h"

// Return parent directory folder.
// If at root, no change is made.
QString DirUtil::moveUpDir(const QString &folderPath) {
    QDir currDir = QDir(folderPath);
    currDir.cdUp();
    return currDir.canonicalPath();
}