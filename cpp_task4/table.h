#define TABLE_H

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <qstring.h>

using namespace std;


//struct CasesEnum
//{
//    const QString NOMINATIVE ="Именительный";
//    const QString GENITIVE = "Родительный";
//    const QString DATIVE = "Дательный";
//    const QString ACCUSATIVE = "Винительный";
//    const QString INSTRUMENTAL = "Творительный";
//    const QString PREPOSITIONAL = "Предложный";
//};

class Table
{

public:
    Table() = default;

    ~Table() = default;
    void set(const QString& key, const vector<QString>& values) {
        mp[key] = values;
    }

    const vector<QString>& get(const QString& key) const {
        return mp.at(key);
    }

    vector<QString>& operator[](const QString& key) {
        return mp[key];
    }

    const vector<QString>& operator[](const QString& key) const {
        return mp.at(key);
    }

    const QString getKey(const QString& word) const {
        for (const auto& [key, values] : mp) {
            if (find(values.begin(), values.end(), word) != values.end()) {
                return key;
            }
        }
        return "";
    }


private:
    map <QString, vector<QString>> mp;
};
