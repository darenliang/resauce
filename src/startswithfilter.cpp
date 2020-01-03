#include "startswithfilter.h"

StartsWithPredicate::StartsWithPredicate(QVector<QString> starts): ResauceFilter(), starts(starts) {}

bool StartsWithPredicate::predicate(ResauceFileInfo info) {

    for (auto st : starts) {

        if (info.fileName().startsWith(st)) {
            return true;
        }

    }

    return false;

}
