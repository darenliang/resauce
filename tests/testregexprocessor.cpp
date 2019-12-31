#include <QtTest>
#include "testregexprocessor.h"
#include "../src/regexprocessor.h"

TestRegexProcessor::TestRegexProcessor() {};


TestRegexProcessor::~TestRegexProcessor() = default;


void TestRegexProcessor::test1() {
    QString pattern = "find";
    QString replace = "replace";
    RegexProcessor processor = RegexProcessor(pattern, replace, true);
    QCOMPARE(processor.execute("somethingFiNdsomething"), QString("somethingreplacesomething"));
    processor = RegexProcessor(pattern, replace, false);
    QCOMPARE(processor.execute("somethingFiNdsomething"), QString("somethingFiNdsomething"));
}
