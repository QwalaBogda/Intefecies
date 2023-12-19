#ifndef FACADE_H
#define FACADE_H

#include <fstream>
#include <string>
#include <vector>
#include <QString>

using namespace std;

struct Level {
    int h, w;

    vector<QString> leveldata;
};

class Facade
{
public:
    static vector<string> getLevels();
    static Level get_level_data(QString levelname);

private:
    static string Filename() {
        return "my_db.csv";
    }
};

#endif // FACADE_H
