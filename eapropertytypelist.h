#ifndef EAPROPERTYTYPELIST_H
#define EAPROPERTYTYPELIST_H

#include <QDomDocument>
#include <QDomNode>
#include <QFile>
#include <QMap>
#include <QList>

#include "errorlist.h"

typedef QList<QString> EAPropertyRecord;

class EAPropertyTypeList
{
private:
        QDomDocument RootDocument;
        ErrorList Errors;
        QMap<QString,EAPropertyRecord *> PropertyList;
        QList<QString> PropertyParameterList;
public:

        EAPropertyTypeList();
        EAPropertyTypeList(QString);
        EAPropertyTypeList(QFile *);
        EAPropertyTypeList(QDomNode *);

bool     LoadFromNode(QDomNode *);
bool     LoadFromFile(QFile *);
bool     LoadFromFile(QString);

};



#endif // EAPROPERTYTYPELIST_H
