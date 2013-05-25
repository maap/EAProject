#include "eaobject.h"

EAObject::EAObject()
{
}

EAObject::EAObject(QFile *File)
{
    this->LoadFromFile(File);
}

EAObject::EAObject(QString FileName)
{
    this->LoadFromFile(FileName);
}


EAObject::EAObject(QDomNode *Node)
{
    EAObject::LoadFromNode(Node);
}

bool EAObject::LoadFromFile(QString FileName)
{
    QFile file(FileName);
    bool status=this->LoadFromFile(&file);
    file.close();
    return status;
}

bool EAObject::LoadFromFile(QFile *File)
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

    QDomNode Node= RootDocument.documentElement();
    return EAObject::LoadFromNode(&Node);

}

bool EAObject::LoadFromNode(QDomNode *Node)
{
    
    return true;
}
