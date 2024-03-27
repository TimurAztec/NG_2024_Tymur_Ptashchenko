#ifndef XMLPARSER_H
#define XMLPARSER_H

#include "baseparser.h"
#include <QObject>

class XmlParser : BaseParser
{
public:
    void setFile(QString pathToFile) override;
    QString getKey(QString key) override;
    void setKey(QString key, std::any data) override;
    void dumpToFile(QString pathToFile) override;
};

#endif // XMLPARSER_H
