#include "endswithfilter.h"

EndsWithFilter::EndsWithFilter(QVector<QString> ends): ResauceFilter(), ends(ends) {}

bool EndsWithFilter::predicate(ResauceFileInfo info) {

    for (auto en : ends) {

        if (info.fileName().endsWith(en)) {

            return true;

        }

    }

    return false;

}
