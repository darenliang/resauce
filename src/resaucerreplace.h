#ifndef RESAUCERREPLACE_H
#define RESAUCERREPLACE_H


#include <QtCore/QRegExp>
#include "resaucerprocessor.h"

class ResaucerReplace : public ResaucerProcessor {
public:
    ResaucerReplace(QString startString, QString endString, bool caseInsensitive);

    QString execute(QString name) override;

private:
    QString startString;
    QString endString;
    bool caseInsensitive = false;
    QString templateRegex = "{{caseDisable}}{{replaceString}}{{caseEnable}}";
    QRegExp replaceRegex;

    void compile();
};

#endif // RESAUCERREPLACE_H
