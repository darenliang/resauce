#ifndef RESAUCEFILEINFO_H
#define RESAUCEFILEINFO_H

#include <QFileInfo>

// Same as QFileInfo except holds information
// About the file's new name
struct ResauceFileInfo : public QFileInfo {

    QString new_name;

    ResauceFileInfo(const QString &file, const QString new_name = QString());

    ResauceFileInfo();

};

#endif // RESAUCEFILEINFO_H
