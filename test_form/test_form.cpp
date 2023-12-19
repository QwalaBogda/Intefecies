#include "test_form.h"
#include "../src/form.h"

#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

void test_form::testBoyerMooreSearch_data() {
    QTest::addColumn<QString>("text");
    QTest::addColumn<QString>("pattern");
    QTest::addColumn<QVector<int>>("expectedResult");

    QTest::newRow("Test Case 1") << "ababcababcabc" << "abc" << QVector<int>{2, 7, 10};
    QTest::newRow("Test Case 2") << "abcdefg" << "xyz" << QVector<int>{};
}

void test_form::testBoyerMooreSearch() {
    QFETCH(QString, text);
    QFETCH(QString, pattern);
    QFETCH(QVector<int>, expectedResult);

    Form form;
    QVector<int> result = boyerMooreSearch(text, pattern);

    QCOMPARE(result, expectedResult);
}
QTEST_MAIN(test_form)
//QTEST_APPLESS_MAIN(test_form)
