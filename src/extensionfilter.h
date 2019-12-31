#ifndef EXTENSIONFILTER_H
#define EXTENSIONFILTER_H

#include "resaucefilter.h"

#include <QVector>

class ExtensionFilter : public ResauceFilter
{

    QVector<QString> extensions;

    static QString ext(QString& name);

public:
    ExtensionFilter(QVector<QString>& extensions);
    ExtensionFilter(QString& extension);
    bool predicate(QString& name) override;
};

#endif // EXTENSIONFILTER_H
