#ifndef RESAUCERREPLACE_H
#define RESAUCERREPLACE_H


#include <QtCore/QRegularExpression>
#include "resaucerprocessor.h"

class ResaucerReplace : public ResaucerProcessor {
public:
    ResaucerReplace(QString &startString, QString &endString, bool caseInsensitive);

    QString execute(QString name) override;

private:
    QString startString;
    QString endString;
    bool caseInsensitive = false;
    QRegularExpression replaceRegex;

    void compile();
};

#endif // RESAUCERREPLACE_H
