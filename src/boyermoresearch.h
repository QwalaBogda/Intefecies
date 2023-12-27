#ifndef BOYERMORESEARCH_H
#define BOYERMORESEARCH_H

#include <QString>
#include <QVector>

class BoyerMooreSearch
{
public:
    BoyerMooreSearch();
    QVector<int> search(const QString &text, const QString &pattern);

private:
    QVector<int> badChar;
};

#endif // BOYERMORESEARCH_H
