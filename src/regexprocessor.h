#ifndef RESAUCERREPLACE_H
#define RESAUCERREPLACE_H


#include <QtCore/QRegularExpression>
#include "resaucerprocessor.h"

class RegexProcessor : public ResaucerProcessor {
public:
    RegexProcessor(QString &pattern, QString &repl, bool caseInsensitive);

    QString execute(QString name) override;

    void setCaseInsensitive(bool caseBool) {
        caseInsensitive = caseBool;
        if (caseInsensitive) {
            regex.setPatternOptions(QRegularExpression::CaseInsensitiveOption);
        }
    }

    void setPattern(const QString &pat) {
        pattern = pat;
        regex.setPattern(pattern);
    }

    void setReplace(const QString &repl) {
        replace = repl;
    }

private:
    QString pattern;
    QString replace;
    bool caseInsensitive = false;
    QRegularExpression regex;
};

#endif // RESAUCERREPLACE_H
