#ifndef RESAUCERREPLACE_H
#define RESAUCERREPLACE_H


#include <QtCore/QRegExp>
#include "resaucerprocessor.h"

class ResaucerReplace : public ResaucerProcessor {
public:
    ResaucerReplace(QString start, QString end);

    QString execute(QString name) override;

private:
    QString startString;
    QString endString;
};

#endif // RESAUCERREPLACE_H
