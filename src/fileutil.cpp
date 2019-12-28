#include "fileutil.h"

#include <QDebug>

// Instantiate
QFileSystemModel FileUtil::model;

const QString FileUtil::sizes[] = { "B", "KB", "MB", "GB", "TB" };

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

QPair<double, qint8> FileUtil::size(double s, qint8 index) {

    if (s >= 1000) {
        return size(s / 1000, index + 1);
    } else {
        return QPair<double, qint8>(s, index);
    }

}

QString FileUtil::sizeStr(QFileInfo& info) {

    auto p = size(info.size(), 0);

    return QString::number(p.first, 'f', 2) + " " + sizes[p.second];

}
