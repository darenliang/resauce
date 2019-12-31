#ifndef RESAUCERREPLACE_H
#define RESAUCERREPLACE_H


#include <QtCore/QRegExp>
#include "resaucerprocessor.h"

class RegexProcessor : public ResaucerProcessor {
public:
    RegexProcessor(QString startString, QString endString, bool caseInsensitive);

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
