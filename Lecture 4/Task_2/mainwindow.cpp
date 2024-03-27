#include "mainwindow.h"
#include "jsonparser.h"
#include "ui_mainwindow.h"
#include "xmlparser.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    connect(ui->selectFileButton, &QPushButton::clicked, this, &MainWindow::selectFile);
    connect(ui->setKeyButton, &QPushButton::clicked, this, &MainWindow::setKey);
    connect(ui->setValueButton, &QPushButton::clicked, this, &MainWindow::setValue);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::selectFile() {
    QString filePath = QFileDialog::getOpenFileName(this, "Select File", QDir::homePath(), "XML files (*.xml);;JSON files (*.json)");

    if (!filePath.isEmpty()) {
        selectedFilePath = filePath;
        QMessageBox::information(this, "File Selected", "Selected file: " + selectedFilePath);
    }
}

void MainWindow::setKey() {
    if (selectedFilePath.isEmpty()) {
        QMessageBox::warning(this, "Error", "No file selected.");
        return;
    }

    QString key = ui->keyLineEdit->text();
    if (key.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please enter a key.");
        return;
    }

    if (selectedFilePath.endsWith(".xml", Qt::CaseInsensitive)) {
        XmlParser xmlHandler;
        xmlHandler.setFile(selectedFilePath);
        const QString value = xmlHandler.getKey(key);
        if (!value.isEmpty()) {
            ui->valueLineEdit->setText(xmlHandler.getKey(key));
        } else {
            QMessageBox::warning(this, "Error", "No such key.");
        }
    } else if (selectedFilePath.endsWith(".json", Qt::CaseInsensitive)) {
        JsonParser jsonHandler;
        jsonHandler.setFile(selectedFilePath);
        const QString value = jsonHandler.getKey(key);
        if (!value.isEmpty()) {
            ui->valueLineEdit->setText(jsonHandler.getKey(key));
        } else {
            QMessageBox::warning(this, "Error", "No such key.");
        }
    } else {
        QMessageBox::warning(this, "Error", "Unsupported file format.");
    }
}

void MainWindow::setValue() {
    if (selectedFilePath.isEmpty()) {
        QMessageBox::warning(this, "Error", "No file selected.");
        return;
    }

    QString key = ui->keyLineEdit->text();
    if (key.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please enter a key.");
        return;
    }

    if (selectedFilePath.endsWith(".xml", Qt::CaseInsensitive)) {
        XmlParser xmlHandler;
        xmlHandler.setFile(selectedFilePath);
        xmlHandler.setKey(key, std::any(ui->valueLineEdit->text()));
        xmlHandler.dumpToFile(selectedFilePath);
    } else if (selectedFilePath.endsWith(".json", Qt::CaseInsensitive)) {
        JsonParser jsonHandler;
        jsonHandler.setFile(selectedFilePath);
        jsonHandler.setKey(key, std::any(ui->valueLineEdit->text()));
        jsonHandler.dumpToFile(selectedFilePath);
    } else {
        QMessageBox::warning(this, "Error", "Unsupported file format.");
    }

    QMessageBox::information(this, "Key Set", "Key: " + key + " Set to: " + ui->valueLineEdit->text());
}
