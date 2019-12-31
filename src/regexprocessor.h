#ifndef RESAUCERREPLACE_H
#define RESAUCERREPLACE_H


#include <QtCore/QRegularExpression>
#include "resaucerprocessor.h"

class RegexProcessor : public ResaucerProcessor {
public:
    RegexProcessor(QString &pattern, QString &repl, bool caseInsensitive);

    QString execute(QString name) override;

private:
    QString replace;
    QRegularExpression regex;

};

#endif // RESAUCERREPLACE_H
