#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <service.h>

#include <QDir>
#include <QFileDialog>
#include <QFileSystemModel>
#include <QMessageBox>
#include <QStringListModel>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    const QString sourceFile = "/home/ilya/CLionProjects/cpp_task4/*";
    const QString targetFile = "/home/ilya/CLionProjects/cpp_task4/data.txt";

    QString fileName = QFileDialog::getOpenFileName(this, "Open file", sourceFile, "*.txt");
    Service service;
    QStringList data = service.getFileData(fileName);

    Table table;
    table.set("Именительный", {"яблоко", "стол", "город"});
    table["Родительный"] = {"яблока", "стола", "города"};
    table["Дательный"] = {"яблоку", "столу", "городу"};
    table["Творительный"] = {"яблоком", "столом", "городом"};
    table["Предложный"] = {"яблоке", "столе", "городе"};

    QString str = service.getFinalString(data, table);
    service.writeFile(str, targetFile);
    ui->textEdit->setText(str);
}

