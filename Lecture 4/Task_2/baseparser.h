#ifndef BASEPARSER_H
#define BASEPARSER_H

#include <QObject>
#include <any>

class BaseParser
{
public:
    virtual void setFile(QString pathToFile) { };
    virtual QString getKey(QString key) { };
    virtual void setKey(QString key, std::any data) { };
    virtual void dumpToFile(QString pathToFile) { };
protected:
    QString pathToFile;
};

#endif // BASEPARSER_H
