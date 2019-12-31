#include <QTest>
#include "testregexprocessor.h"


int main(int argc, char *argv[]) {
    int status = 0;

    {
        TestRegexProcessor testRP;
        status |= QTest::qExec(&testRP, argc, argv);
    }

    return status;
}
