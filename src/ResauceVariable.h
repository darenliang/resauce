#ifndef RESAUCEVARIABLE_H
#define RESAUCEVARIABLE_H

#include <QString>

struct ResauceVariable {

    QString name;

    double value;

    double incdec;

    int freq = 1;

    int count = 0;

};

#endif // RESAUCEVARIABLE_H
