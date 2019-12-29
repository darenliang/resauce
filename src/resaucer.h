#ifndef RESAUCER_H
#define RESAUCER_H

#include "resaucefileinfo.h"
#include "ResauceVariable.h"

#include <QRegularExpression>
#include <QVector>

class Resaucer
{

    Q_OBJECT

public:

    QVector<ResauceFileInfo> files;
    QVector<ResauceVariable> vars;
    QVector<QRegularExpression> extractors;
    QString _template;

    Resaucer();

    void process();

};

#endif // RESAUCER_H
