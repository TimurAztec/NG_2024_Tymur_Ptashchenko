/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QPushButton *selectFileButton;
    QLineEdit *keyLineEdit;
    QPushButton *setKeyButton;
    QLineEdit *valueLineEdit;
    QPushButton *setValueButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(400, 300);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        selectFileButton = new QPushButton(centralwidget);
        selectFileButton->setObjectName("selectFileButton");

        verticalLayout->addWidget(selectFileButton);

        keyLineEdit = new QLineEdit(centralwidget);
        keyLineEdit->setObjectName("keyLineEdit");

        verticalLayout->addWidget(keyLineEdit);

        setKeyButton = new QPushButton(centralwidget);
        setKeyButton->setObjectName("setKeyButton");

        verticalLayout->addWidget(setKeyButton);

        valueLineEdit = new QLineEdit(centralwidget);
        valueLineEdit->setObjectName("valueLineEdit");

        verticalLayout->addWidget(valueLineEdit);

        setValueButton = new QPushButton(centralwidget);
        setValueButton->setObjectName("setValueButton");

        verticalLayout->addWidget(setValueButton);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 400, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(selectFileButton, SIGNAL(clicked()), MainWindow, SLOT(selectFile()));
        QObject::connect(setValueButton, SIGNAL(clicked()), MainWindow, SLOT(setValue()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        selectFileButton->setText(QCoreApplication::translate("MainWindow", "Select File", nullptr));
        keyLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter Key", nullptr));
        setKeyButton->setText(QCoreApplication::translate("MainWindow", "Select Key", nullptr));
        valueLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter Value", nullptr));
        setValueButton->setText(QCoreApplication::translate("MainWindow", "Set Value", nullptr));
        (void)MainWindow;
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
