#include "form.h"
#include "ui_form.h"


Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked()),
            this, SLOT(start()));
}

Form::~Form()
{
    delete ui;
}

void Form::start() {
    QString str = ui->str->text();
    QString sub_str = ui->sub_str->text();

    QVector<int> result = boyerMooreSearch(str, sub_str);

    if (result.isEmpty()) {
        ui->result->setText("Substring not found");
    } else {
        QString resultString;
        for (int i : result) {
            resultString.append(QString::number(i) + " ");
        }
        ui->result->setText(resultString);
    }
}

QVector<int> boyerMooreSearch(const QString &text, const QString &pattern) {
    QVector<int> indices;
    int n = text.length();
    int m = pattern.length();

    if (m == 0 || m > n) {
        return indices;
    }

    QVector<int> badChar(256, -1);

    for (int i = 0; i < m; ++i) {
        badChar[pattern[i].toLatin1()] = i;
    }

    int s = 0;
    while (s <= n - m) {
        int j = m - 1;

        while (j >= 0 && pattern[j] == text[s + j]) {
            --j;
        }

        if (j < 0) {
            indices.append(s);
            s += m;
        } else {
            s += std::max(1, j - badChar[text[s + j].toLatin1()]);
        }
    }

    return indices;
}

QLineEdit* Form::getTextLineEdit() const {
    return ui->str;
}

QLineEdit* Form::getSubStringLineEdit() const {
    return ui->sub_str;
}

QPushButton* Form::getSearchButton() const {
    return ui->pushButton;
}

QLabel* Form::getResultLabel() const {
    return ui->result;
}
