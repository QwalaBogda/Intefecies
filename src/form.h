#ifndef FORM_H
#define FORM_H

#include <QWidget>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

public slots:
    void start();

private slots:
    QVector<int> boyerMooreSearch(const QString &text, const QString &pattern);

private:
    Ui::Form *ui;
};

#endif // FORM_H
