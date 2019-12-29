#ifndef RESAUCEVARIABLE_H
#define RESAUCEVARIABLE_H

#include <QString>

struct ResauceVariable {

    QString name;

    double value = 0;

    double incdec = 1;

    int freq = 1;

    int count = 0;

};

#endif // RESAUCEVARIABLE_H
