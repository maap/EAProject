#ifndef EAOBJECTLIST_H
#define EAOBJECTLIST_H

#include <QDomDocument>
#include <QDomNode>
#include <QFile>

#include "eaobject.h"
#include "errorlist.h"

class EAObjectList
{
private:
        QDomDocument RootDocument;
        ErrorList Errors;

public:

        EAObjectList();
        EAObjectList(QString);
        EAObjectList(QFile *);
        EAObjectList(QDomNode *);
bool     LoadFromNode(QDomNode *);
bool     LoadFromFile(QFile *);
bool     LoadFromFile(QString);
};

#endif // EAOBJECTLIST_H
