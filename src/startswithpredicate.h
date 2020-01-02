#ifndef STARTSWITHPREDICATE_H
#define STARTSWITHPREDICATE_H

#include "resaucefilter.h"

#include <QVector>
#include <QString>

class StartsWithPredicate : public ResauceFilter
{
    
    QVector<QString> starts;
    
public:
    StartsWithPredicate(QVector<QString> starts);
    bool predicate(QString& name) override;
};

#endif // STARTSWITHPREDICATE_H
