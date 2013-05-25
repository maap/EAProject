#include <QCoreApplication>

#include <iostream>
#include <QDebug>
#include <QDir>

#include "dbmapping.h"
#include "eaconfiguration.h"
#include "eaobject.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    std::cout << "\nStarted !!!\n";
    QString FileName=QDir::currentPath();
    EAConfiguration Config(FileName+"/EAConfiguration.xml");
    QString test = Config.Errors;
    std::cout << Config.Errors.toQString().toStdString()<<std::endl;
    return a.exec();

}
