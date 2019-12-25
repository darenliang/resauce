#ifndef FILEUTIL_H
#define FILEUTIL_H

#include <QFileInfo>
#include <QFileSystemModel>

class FileUtil
{

    static QFileSystemModel model;

    public:

    static QIcon getIcon(QString file);

    static QIcon getIcon(QFileInfo& file);

    static qint64 getDirSize(QFileInfo& file);

};

#endif // FILEUTIL_H
