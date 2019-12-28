#ifndef RESAUCEFILEINFO_H
#define RESAUCEFILEINFO_H

#include <QFileInfo>

struct ResauceFileInfo : public QFileInfo
{

    QString new_name;

    ResauceFileInfo(const QString& file, const QString new_name = QString());

};

#endif // RESAUCEFILEINFO_H
