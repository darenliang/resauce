#ifndef RESAUCER_H
#define RESAUCER_H

#include "resaucefileinfo.h"

#include <QVector>

class Resaucer
{

    Q_OBJECT

public:

    QVector<ResauceFileInfo> files;

    Resaucer();

};

#endif // RESAUCER_H
