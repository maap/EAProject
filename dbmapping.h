#ifndef DBMAPPING_H
#define DBMAPPING_H

#include <QtXml>
#include "errorlist.h"

class DBMapping
{
private:
        QDomDocument RootDocument;
        ErrorList Errors;
    //QDomElement RootElement;
public:
        DBMapping();
        DBMapping(QString);
        DBMapping(QFile);
        DBMapping(QDomNode);

bool     LoadFromNode(QDomNode);
bool     LoadFromFile(QFile *);
bool     LoadFromFile(QString);

};

#endif // DBMAPPING_H
