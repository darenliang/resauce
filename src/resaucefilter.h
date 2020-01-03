#ifndef RESAUCEFILTER_H
#define RESAUCEFILTER_H

#include "resaucefileinfo.h"

#include <QString>

class ResauceFilter
{
public:

    virtual bool predicate(ResauceFileInfo name) = 0;

};

#endif // RESAUCEFILTER_H
