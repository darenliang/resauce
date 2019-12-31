#ifndef RESAUCEFILTER_H
#define RESAUCEFILTER_H

#include <QString>

class ResauceFilter
{
public:

    virtual bool predicate(QString& name) = 0;

};

#endif // RESAUCEFILTER_H
