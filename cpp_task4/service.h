#ifndef SERVICE_H
#define SERVICE_H

#include <string>
#include <QStringList>
#include <table.h>

using namespace std;

class Service
{
public:
    Service();
    QStringList getFileData(QString fileName);

    QString getFinalString(QStringList data, Table table);

    void writeFile(QString data, QString sourceTarget);
};

#endif // SERVICE_H
