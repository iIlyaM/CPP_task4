#include "service.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <qmessagebox.h>

Service::Service()
{

}

QStringList Service::getFileData(QString fileName)
{
    QMessageBox msgBox;
    msgBox.setText("file not open");

    QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            msgBox.exec();
        }

        QString content = file.readAll();
        QStringList sList = content.split(QRegExp("(\\r\\n)|(\\n\\r)|\\r|\\n"), QString::SkipEmptyParts);
        return sList;
}

QString Service::getFinalString(QStringList data, Table table)
{
    QString finalString;
    QStringList tempList;
    for(int i = 0; i < data.size(); i++)
    {
        tempList = data[i].split(QRegExp(" | ,"), QString::SkipEmptyParts);
        for (int j = 0; j < tempList.size(); j++)
        {
            finalString += tempList[j] + " (" + table.getKey(tempList[j]) + ") " + "\n";
        }
    }
    return finalString;
}

void Service::writeFile(QString data, QString targetSource)
{
        QFile file(targetSource);
        if (file.open(QIODevice::ReadWrite)) {
            QTextStream stream(&file);
            stream << data << endl;
        }
}
