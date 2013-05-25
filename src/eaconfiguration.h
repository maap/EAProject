#ifndef EACONFIGURATION_H
#define EACONFIGURATION_H

#include <QDomDocument>
#include <QDomNode>
#include <QFile>

#include "eaobjectlist.h"
#include "eapropertytypelist.h"
#include "errorlist.h"

class EAConfiguration
{
private:
        QDomDocument RootDocument;
        EAObjectList ObjectList;
        EAPropertyTypeList PropertyTypeList;
public:
        ErrorList Errors;
        EAConfiguration();
        EAConfiguration(QString);
        EAConfiguration(QFile *);
        EAConfiguration(QDomNode *);

bool    LoadFromNode(QDomNode *);
bool    LoadFromFile(QFile *);
bool    LoadFromFile(QString);

};

#endif // EACONFIGURATION_H
