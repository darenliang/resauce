#ifndef RESAUCE_TESTREGEXPROCESSOR_H
#define RESAUCE_TESTREGEXPROCESSOR_H

#include <QtCore/QObject>
#include "../src/regexprocessor.h"

class TestRegexProcessor : public QObject {
Q_OBJECT

public:
    TestRegexProcessor();

    ~TestRegexProcessor();

private slots:

    void test1();

};

#endif //RESAUCE_TESTREGEXPROCESSOR_H
