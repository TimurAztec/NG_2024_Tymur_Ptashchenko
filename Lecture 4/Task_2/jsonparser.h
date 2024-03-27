#ifndef JSONPARSER_H
#define JSONPARSER_H

#include "baseparser.h"
#include <QObject>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QTextStream>
#include <any>

class JsonParser : BaseParser
{
public:
    void setFile(QString pathToFile) override;
    QString getKey(QString key) override;
    void setKey(QString key, std::any data) override;
    void dumpToFile(QString pathToFile) override;
};

#endif // JSONPARSER_H
