#ifndef OBJECT_H
#define OBJECT_H

class Object
{
    QDomDocument RootDocument;
    //QDomElement RootElement;
public:
        ErrorList Errors;
        Object();
        Object(QString);
        Object(QFile);
        Object(QDomNode);
bool     LoadFromNode(QDomNode);
bool     LoadFromFile(QFile *);
bool     LoadFromFile(QString);};
}
#endif // OBJECT_H
