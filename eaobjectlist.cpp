#include "eaobjectlist.h"

EAObjectList::EAObjectList()
{
}

EAObjectList::EAObjectList(QFile *File)
{
    this->LoadFromFile(File);
}

EAObjectList::EAObjectList(QString FileName)
{
    this->LoadFromFile(FileName);
}


EAObjectList::EAObjectList(QDomNode *Node)
{
    EAObjectList::LoadFromNode(Node);
}

bool EAObjectList::LoadFromFile(QString FileName)
{
    QFile file(FileName);
    bool status=this->LoadFromFile(&file);
    file.close();
    return status;
}

bool EAObjectList::LoadFromFile(QFile *File)
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

    QDomNode Node=RootDocument.documentElement();
    return EAObjectList::LoadFromNode(&Node);

}

bool EAObjectList::LoadFromNode(QDomNode *Node)
{

    return true;
}
