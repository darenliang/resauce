#ifndef RESAUCEVARIABLE_H
#define RESAUCEVARIABLE_H

#include <QString>

struct ResauceVariable {

    QString name;

    double initial = 0;

    double value = 0;

    void init(double val) { initial = val; value = val; }

    double incdec = 1;

    int freq = 1;

    int count = 0;

    double _limit;

    bool lim;

    void limit(double lim) { _limit = lim; this->lim = lim; }

};

#endif // RESAUCEVARIABLE_H
