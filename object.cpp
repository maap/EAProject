#include "object.h"

Object::Object()
{
}

Object::Object(QFile File)
{
    this->LoadFromFile(&File);
}

Object::Object(QString FileName)
{
    this->LoadFromFile(FileName);
}


Object::Object(QDomNode Node)
{
    Object::LoadFromNode(Node);
}

bool Object::LoadFromFile(QString FileName)
{
    QFile file(FileName);
    bool status=this->LoadFromFile(&file);
    file.close();
    return status;
}

bool Object::LoadFromFile(QFile *File)
{
    if(!File){
        this->Errors << ERROR_INCLASS_PREPEND+"File pointer is null";
        return false;
    }
    if(!File->open(QFile::ReadOnly | QFile::Text)){
        this->Errors << ERROR_INCLASS_PREPEND+"Can't open file";
        return false;
    }
    if(!RootDocument.setContent(File)){
        this->Errors << ERROR_INCLASS_PREPEND+"setContent has been failed, can't read file content";
        return false;
    }

    RootDocument.documentElement();
    return Object::LoadFromNode(RootDocument.documentElement());

}

bool Object::LoadFromNode(QDomNode Node)
{

    return true;
}
