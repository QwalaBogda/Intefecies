#include <QApplication>
#include <QDebug>
#include "form.h"
#include "boyermoresearch.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Form f;
    f.show();

    QString str = "Some text for searching";
    QString sub_str = "search";

    BoyerMooreSearch boyerMooreSearch;
    QVector<int> result;


    return app.exec();
}
