#include "eapropertytypelist.h"

EAPropertyTypeList::EAPropertyTypeList()
{
}

EAPropertyTypeList::EAPropertyTypeList(QFile *File)
{
    this->LoadFromFile(File);
}

EAPropertyTypeList::EAPropertyTypeList(QString FileName)
{
    this->LoadFromFile(FileName);
}


EAPropertyTypeList::EAPropertyTypeList(QDomNode *Node)
{
    EAPropertyTypeList::LoadFromNode(Node);
}

bool EAPropertyTypeList::LoadFromFile(QString FileName)
{
    QFile file(FileName);
    bool status=this->LoadFromFile(&file);
    file.close();
    return status;
}

bool EAPropertyTypeList::LoadFromFile(QFile *File)
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
    return EAPropertyTypeList::LoadFromNode(&Node);

}

bool EAPropertyTypeList::LoadFromNode(QDomNode *Node)
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
        QString propertyName=child.nodeName();
        for(int n=0;n<child.attributes().count();++n){
            QDomNode parameter=child.attributes().item(n);
            QString parameterName=parameter.nodeName();
            QString parameterValue=parameter.nodeValue();
            if(PropertyParameterList.indexOf(parameterName)<0){

            }

        }

        child=child.nextSibling();
    };
    return true;
}
