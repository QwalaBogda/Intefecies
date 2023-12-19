#ifndef TEST_FORM_H
#define TEST_FORM_H

#include <QtTest/QtTest>
#include <QObject>

class test_form : public QObject
{
    Q_OBJECT

private slots:
    void testBoyerMooreSearch_data();
    void testBoyerMooreSearch();
};

#endif // TEST_FORM_H
