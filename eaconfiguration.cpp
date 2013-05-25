#include "eaconfiguration.h"

EAConfiguration::EAConfiguration()
{
}

EAConfiguration::EAConfiguration(QFile *File)
{
    this->LoadFromFile(File);
}

EAConfiguration::EAConfiguration(QString FileName)
{
    this->LoadFromFile(FileName);
}


EAConfiguration::EAConfiguration(QDomNode *Node)
{
    EAConfiguration::LoadFromNode(Node);
}

bool EAConfiguration::LoadFromFile(QString FileName)
{
    QFile file(FileName);
    bool status=this->LoadFromFile(&file);
    file.close();
    return status;
}

bool EAConfiguration::LoadFromFile(QFile *File)
{
    if(!File){
        this->Errors << ERROR_INCLASS_PREPEND+"File pointer is null";
        return false;
    }
    if(!File->open(QFile::ReadOnly | QFile::Text)){
        this->Errors << ERROR_INCLASS_PREPEND+"Can't open file "+File->fileName();
        return false;
    }
    QString Errors;
    int ErrorLine;
    int ErrorColumn;
    if(!RootDocument.setContent(File,true,&Errors,&ErrorLine,&ErrorColumn)){
        this->Errors << ERROR_INCLASS_PREPEND+"setContent has been failed, can't read file content at Line "+
                        QString::number(ErrorLine)+" column "+QString::number(ErrorColumn)+" .\n"+Errors;
        return false;
    }

    QDomNode Node=RootDocument.documentElement();
    return EAConfiguration::LoadFromNode(&Node);

}

bool EAConfiguration::LoadFromNode(QDomNode *Node)
{
    if(!Node){
        this->Errors << ERROR_INCLASS_PREPEND+"Node pointer is null";
        return false;
    }
    if(!Node->hasChildNodes()){
        this->Errors << ERROR_INCLASS_PREPEND+"Node has no childs";
        return false;
    }
    QDomNode child=Node->firstChild();
    while(!child.isNull()){
        if(child.nodeName() == "PropertyTypeList" ){
            if(!this->PropertyTypeList.LoadFromNode(&child)){
                this->Errors << ERROR_INCLASS_PREPEND+"PropertyTypeList loading has been failed";
            } else
                this->Errors << ERROR_INCLASS_PREPEND+"PropertyTypeList has been loaded";

        }
        else if(child.nodeName() == "EAObjectList" ){
            if(!this->ObjectList.LoadFromNode(&child)){
                this->Errors << ERROR_INCLASS_PREPEND+"EAObjectList loading has been failed";
            } else
                this->Errors << ERROR_INCLASS_PREPEND+"EAObjectList has been loaded";
        }
        else{

        }
        child=child.nextSibling();
    };
    return true;
}
