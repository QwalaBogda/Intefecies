#include "facade.h"
#include <QVBoxLayout>
#include <QDir>
#include <QDirIterator>
#include <QFile>
#include <QTextStream>
#include <vector>
#include <string>
#include <iostream>

vector<string> Facade::getLevels() {

    vector<string> level_names;
    QDir directory("C:/levels/");

    QDirIterator iterator(directory.path(), QDir::Files);
    while (iterator.hasNext()) {
        iterator.next();
        QString levelName = iterator.fileInfo().completeBaseName();
        level_names.push_back(levelName.toStdString());
    }
    return level_names;

}

Level Facade::get_level_data(QString path)
{
    Level level;
    QFile file(QString("C:/levels/%1.txt").arg(path));
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Не удается открыть файл!";
    }
    QTextStream in(&file);

    in >> level. h >> level.w;
    in.readLine();

    while (!in.atEnd()) {
        QString line = in.readLine();
        level.leveldata.push_back(line);
    }

    return level;

}
