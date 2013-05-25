#ifndef EAOBJECT_H
#define EAOBJECT_H

#include <QDomDocument>
#include <QDomNode>
#include <QFile>

#include "errorlist.h"

class EAObject
{
private:
        QDomDocument RootDocument;
        ErrorList Errors;
public:
        EAObject();
        EAObject(QString);
        EAObject(QFile *);
        EAObject(QDomNode *);
bool     LoadFromNode(QDomNode* );
bool     LoadFromFile(QFile *);
bool     LoadFromFile(QString);

};

#endif // EAOBJECT_H
