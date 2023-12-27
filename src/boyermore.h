#ifndef BOYERMORE_H
#define BOYERMORE_H

#include <QString>
#include <QVector>

class BoyerMore
{
public:
    static QVector<int> boyerMooreSearch(const QString &text, const QString &pattern);
};

#endif // BOYERMORE_H
