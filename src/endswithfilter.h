#ifndef ENDSWITHFILTER_H
#define ENDSWITHFILTER_H

#include "resaucefilter.h"

#include <QVector>
#include <QString>

class EndsWithFilter : public ResauceFilter
{

    QVector<QString> ends;

public:
    EndsWithFilter(QVector<QString> ends);
    bool predicate(ResauceFileInfo info) override;
};

#endif // ENDSWITHFILTER_H
