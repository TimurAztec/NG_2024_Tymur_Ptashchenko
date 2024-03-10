#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    encodeState = true;
    key = "";
    ui->setupUi(this);
    ui->r_encode->setChecked(true);
    connect(ui->r_encodeStateButtonGroup, &QButtonGroup::buttonClicked, this, &MainWindow::switchState);
    connect(ui->t_key, &QLineEdit::textChanged, this, &MainWindow::keyTextChanged);
    connect(ui->t_input, &QTextEdit::textChanged, this, &MainWindow::processChange);
}

void MainWindow::switchState(QAbstractButton *button)
{
    encodeState = button == ui->r_encode;
    processChange();
}

void MainWindow::keyTextChanged(const QString &key)
{
    this->key = key;
    processChange();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::processChange()
{
    const QString text = ui->t_input->toPlainText();
    QString processedText;
    if (encodeState) {
        processedText = encode(text, this->key);
    } else {
        processedText = decode(text, this->key);
    }
    qDebug() << processedText;
    ui->t_output->setText(processedText);
}

QString MainWindow::encode(QString text, QString key)
{
    QString encodedText;
    text = text.toUpper();
    key = key.toUpper();
    int keyLength = key.length();
    int j = 0;

    for (int i = 0; i < text.length(); ++i) {
        QChar currentChar = text.at(i);

        if (currentChar.isLetter()) {
            QChar shiftedChar = QChar((currentChar.toLatin1() + key.at(j).toLatin1() - 2 * 'A') % 26 + 'A');
            encodedText.append(shiftedChar);
            j = (j + 1) % keyLength; // Move to the next key character
        } else {
            encodedText.append(currentChar);
        }
    }

    return encodedText;
}

QString MainWindow::decode(QString text, QString key) {
    QString decodedText;
    text = text.toUpper();
    key = key.toUpper();
    int keyLength = key.length();
    int j = 0;

    for (int i = 0; i < text.length(); ++i) {
        QChar currentChar = text.at(i);

        if (currentChar.isLetter()) {
            QChar shiftedChar = QChar((currentChar.toLatin1() - key.at(j).toLatin1() + 26) % 26 + 'A');
            decodedText.append(shiftedChar);
            j = (j + 1) % keyLength;
        } else {
            decodedText.append(currentChar);
        }
    }

    return decodedText;
}
