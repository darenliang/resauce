#ifndef FILEUTIL_H
#define FILEUTIL_H

#include <QFileInfo>
#include <QFileSystemModel>
#include <QPair>

class FileUtil
{

    static QFileSystemModel model;

    static const QString sizes[];

    static QPair<double, qint8> size(double size, qint8 index = 0);

    public:

    static QIcon getIcon(QString file);

    static QIcon getIcon(QFileInfo& file);

    static qint64 getDirSize(QFileInfo& file);

    static QString sizeStr(QFileInfo& info);

};

#endif // FILEUTIL_H
