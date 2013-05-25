#include "dbmapping.h"

DBMapping::DBMapping()
{
}

DBMapping::DBMapping(QFile File)
{
    this->LoadFromFile(&File);
}

DBMapping::DBMapping(QString FileName)
{
    this->LoadFromFile(FileName);
}


DBMapping::DBMapping(QDomNode Node)
{
    DBMapping::LoadFromNode(Node);
}

bool DBMapping::LoadFromFile(QString FileName)
{
    QFile file(FileName);
    bool status=this->LoadFromFile(&file);
    file.close();
    return status;
}

bool DBMapping::LoadFromFile(QFile *File)
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
    return DBMapping::LoadFromNode(RootDocument.documentElement());

}

bool DBMapping::LoadFromNode(QDomNode Node)
{
    
    return true;
}
