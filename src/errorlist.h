#ifndef ERRORLIST_H
#define ERRORLIST_H

#include <iostream>
#include <typeinfo>

#define ERROR_INCLASS_PREPEND QString("ERROR into ")+__FILE__+" at line "+QString::number(__LINE__)+" > Fn: "+__FUNCTION__+" , "

#include <QList>
#include <QString>

typedef QString IT_Error;

class ErrorList
{
private:
    QList<IT_Error> List;
public:
    void Add(const QString);
    void Clear();
    bool hasErrors;
// Conversions
    QString toQString();
// Operators
    void operator<<(const QString);
    operator QString();
};

#endif // ERRORLIST_H
