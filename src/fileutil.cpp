#include "fileutil.h"

#include <QDebug>

// Instantiate
QFileSystemModel FileUtil::model;

QIcon FileUtil::getIcon(QString file) {

    auto dex = model.index(file);

    return model.fileIcon(dex);

}

QIcon FileUtil::getIcon(QFileInfo& file) { return getIcon(file.filePath()); }

qint64 FileUtil::getDirSize(QFileInfo& file) {

    qint64 total = 0;

    if (file.isDir()) {

        QDirIterator iter{file.absoluteFilePath(), QDir::NoDotAndDotDot|QDir::AllEntries};

        while (iter.hasNext()) {

            QFileInfo info{iter.next()};

            qDebug() << "Cur: " << file.absoluteFilePath() << " Scan: " << iter.next();

            total = total + getDirSize(info);

        }

    } else {
        total = file.size();
    }

    return total;

}
