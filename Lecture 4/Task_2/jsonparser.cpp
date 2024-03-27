#include "jsonparser.h"

void JsonParser::setFile(QString pathToFile) {
    this->pathToFile = pathToFile;
}

QString JsonParser::getKey(QString key) {
    QFile file(this->pathToFile);
    QString value;
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return "";
    }
    QByteArray jsonData = file.readAll();
    file.close();

    QJsonDocument document = QJsonDocument::fromJson(jsonData);
    if (!document.isObject()) {
        return "";
    }

    QJsonObject jsonObject = document.object();
    if (jsonObject.contains(key)) {
        QJsonValue jsonValue = jsonObject.value(key);
        if (jsonValue.isString()) {
            value = jsonValue.toString();
        }
    }
    return value;
}

void JsonParser::setKey(QString key, std::any data) {
    QFile file(this->pathToFile);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }
    QByteArray jsonData = file.readAll();
    file.close();

    QJsonDocument document = QJsonDocument::fromJson(jsonData);
    if (!document.isObject()) {
        return;
    }

    QJsonObject jsonObject = document.object();

    QJsonValue jsonValue;
    if (data.type() == typeid(QString)) {
        jsonValue = QJsonValue(QString(std::any_cast<QString>(data)));
    } else if (data.type() == typeid(int)) {
        jsonValue = QJsonValue(std::any_cast<int>(data));
    }

    jsonObject.insert(key, jsonValue);

    document.setObject(jsonObject);

    QFile outputFile(this->pathToFile);
    if (!outputFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return;
    }
    outputFile.write(document.toJson());
    outputFile.close();
}


void JsonParser::dumpToFile(QString pathToFile) {
    QFile inputFile(this->pathToFile);
    if (!inputFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }
    QByteArray jsonData = inputFile.readAll();
    inputFile.close();

    QFile outputFile(pathToFile);
    if (!outputFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return;
    }
    outputFile.write(jsonData);
    outputFile.close();
}

