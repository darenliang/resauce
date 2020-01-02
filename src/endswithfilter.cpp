#include "endswithfilter.h"

EndsWithFilter::EndsWithFilter(QVector<QString> ends): ResauceFilter(), ends(ends) {}

bool EndsWithFilter::predicate(QString &name) {

    for (auto en : ends) {

        if (name.endsWith(en)) {

            return true;

        }

    }

    return false;

}
