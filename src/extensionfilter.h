#ifndef EXTENSIONFILTER_H
#define EXTENSIONFILTER_H

#include "resaucefilter.h"

#include <QVector>

class ExtensionFilter : public ResauceFilter
{

    QVector<QString> extensions;

public:
    ExtensionFilter(QVector<QString>& extensions);
    ExtensionFilter(QString extension);
    bool predicate(ResauceFileInfo info) override;
};

#endif // EXTENSIONFILTER_H
