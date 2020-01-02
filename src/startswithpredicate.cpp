#include "startswithpredicate.h"

StartsWithPredicate::StartsWithPredicate(QVector<QString> starts): ResauceFilter(), starts(starts) {}

bool StartsWithPredicate::predicate(QString &name) {

    for (auto st : starts) {

        if (name.startsWith(st)) {
            return true;
        }

    }

    return false;

}
