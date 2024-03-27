#include "xmlparser.h"
#include <QString>
#include <any>
#include <QFile>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QTextStream>
#include <QDebug>

void XmlParser::setFile(QString pathToFile) {
    this->pathToFile = pathToFile;
}

QString XmlParser::getKey(QString key) {
    QFile file(this->pathToFile);
    QString value;
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return "";
    }
    QXmlStreamReader xmlReader(&file);
    while (!xmlReader.atEnd()) {
        if (xmlReader.isStartElement() && xmlReader.name() == key) {
            value = xmlReader.readElementText();
            break;
        }
        xmlReader.readNext();
    }
    file.close();
    return value;
}

void XmlParser::setKey(QString key, std::any data) {
    QFile file(this->pathToFile);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }
    QString content;
    QTextStream stream(&file);
    content = stream.readAll();
    file.close();

    QXmlStreamWriter xmlWriter(&file);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return;
    }
    QXmlStreamReader xmlReader(content);
    xmlWriter.setAutoFormatting(true);
    while (!xmlReader.atEnd()) {
        xmlReader.readNext();
        if (xmlReader.isStartElement() && xmlReader.name() == key) {
            xmlWriter.writeStartElement(xmlReader.name().toString());
            xmlWriter.writeCharacters(std::any_cast<QString>(data));
            xmlWriter.writeEndElement();
        } else {
            xmlWriter.writeCurrentToken(xmlReader);
        }
    }
    file.close();
}

void XmlParser::dumpToFile(QString pathToFile) {
    QFile file(this->pathToFile);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }
    QString content;
    QTextStream stream(&file);
    content = stream.readAll();
    file.close();

    QFile outputFile(pathToFile);
    if (!outputFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return;
    }
    QTextStream outputStream(&outputFile);
    outputStream << content;
    outputFile.close();
}
