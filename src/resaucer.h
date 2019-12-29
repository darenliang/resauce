#ifndef RESAUCER_H
#define RESAUCER_H

#include "resaucefileinfo.h"
#include "ResauceVariable.h"

#include <QRegularExpression>
#include <QVector>

class Resaucer
{

public:

    QVector<ResauceFileInfo> files;
    QVector<ResauceVariable> vars;
    QVector<QRegularExpression> extractors;
    QVector<QRegularExpression> ignore;
    QVector<QRegularExpression> matchers;
    QString _template;

    Resaucer();

    void process();

};

#endif // RESAUCER_H
