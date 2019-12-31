#include "regexfilter.h"

RegexFilter::RegexFilter(QString& regex, bool caseInsensitive) {

    this->regex.setPattern(regex);

    if (caseInsensitive) {
        this->regex.setPatternOptions(QRegularExpression::CaseInsensitiveOption);
    }

}

RegexFilter::RegexFilter(QRegularExpression& regex): regex(regex) {}

bool RegexFilter::predicate(QString &name) {

    return regex.match(name).hasMatch();

}
