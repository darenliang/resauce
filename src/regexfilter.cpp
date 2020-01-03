#include "regexfilter.h"

RegexFilter::RegexFilter(QString& regex, bool caseInsensitive) {

    this->regex.setPattern(regex);

    if (caseInsensitive) {
        this->regex.setPatternOptions(QRegularExpression::CaseInsensitiveOption);
    }

}

RegexFilter::RegexFilter(QRegularExpression& regex): regex(regex) {}

bool RegexFilter::predicate(ResauceFileInfo info) {

    return regex.match(info.fileName()).hasMatch();

}
