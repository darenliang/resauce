#ifndef REGEXFILTER_H
#define REGEXFILTER_H

#include "resaucefilter.h"
#include <QRegularExpression>

class RegexFilter : public ResauceFilter
{

    QRegularExpression regex;

public:
    RegexFilter(QString& regex, bool caseInsensitive);
    RegexFilter(QRegularExpression& regex);
    bool predicate(QString& name) override;
};

#endif // REGEXFILTER_H
