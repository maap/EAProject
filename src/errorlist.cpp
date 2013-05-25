#include "errorlist.h"

void ErrorList::Add(const QString ErrorMsg){
    this->List.append(IT_Error(ErrorMsg));
    this->hasErrors=true;
}

void ErrorList::Clear(){
    this->List.clear();
    this->hasErrors=false;
}

// Conversions

QString ErrorList::toQString(){
    QString output;
    for(int i=0;i < this->List.size(); ++i ){
        output.append(this->List.at(i)+"\n");
    }
    return output;
}

// Operators

ErrorList::operator QString(){
    return ErrorList::toQString();
}

void ErrorList::operator<<(const QString ErrorMsg){
    ErrorList::Add(IT_Error(ErrorMsg));
}
