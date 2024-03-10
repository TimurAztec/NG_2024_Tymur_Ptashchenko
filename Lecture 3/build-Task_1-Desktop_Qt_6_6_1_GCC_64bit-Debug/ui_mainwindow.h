/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *t_key;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *InputLabel;
    QTextEdit *t_input;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer;
    QRadioButton *r_encode;
    QRadioButton *r_decode;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *OutputLabel;
    QTextEdit *t_output;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QButtonGroup *r_encodeStateButtonGroup;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(677, 324);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(0, 0, 671, 281));
        verticalLayout_5 = new QVBoxLayout(layoutWidget);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        t_key = new QLineEdit(layoutWidget);
        t_key->setObjectName("t_key");

        verticalLayout->addWidget(t_key);


        verticalLayout_5->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        InputLabel = new QLabel(layoutWidget);
        InputLabel->setObjectName("InputLabel");

        verticalLayout_2->addWidget(InputLabel);

        t_input = new QTextEdit(layoutWidget);
        t_input->setObjectName("t_input");
        t_input->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));

        verticalLayout_2->addWidget(t_input);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        r_encode = new QRadioButton(layoutWidget);
        r_encodeStateButtonGroup = new QButtonGroup(MainWindow);
        r_encodeStateButtonGroup->setObjectName("r_encodeStateButtonGroup");
        r_encodeStateButtonGroup->addButton(r_encode);
        r_encode->setObjectName("r_encode");

        verticalLayout_4->addWidget(r_encode);

        r_decode = new QRadioButton(layoutWidget);
        r_encodeStateButtonGroup->addButton(r_decode);
        r_decode->setObjectName("r_decode");

        verticalLayout_4->addWidget(r_decode);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);


        horizontalLayout->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        OutputLabel = new QLabel(layoutWidget);
        OutputLabel->setObjectName("OutputLabel");

        verticalLayout_3->addWidget(OutputLabel);

        t_output = new QTextEdit(layoutWidget);
        t_output->setObjectName("t_output");
        t_output->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        t_output->setReadOnly(true);

        verticalLayout_3->addWidget(t_output);


        horizontalLayout->addLayout(verticalLayout_3);


        verticalLayout_5->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 677, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Key", nullptr));
        InputLabel->setText(QCoreApplication::translate("MainWindow", "Input", nullptr));
        r_encode->setText(QCoreApplication::translate("MainWindow", "Encode", nullptr));
        r_decode->setText(QCoreApplication::translate("MainWindow", "Decode", nullptr));
        OutputLabel->setText(QCoreApplication::translate("MainWindow", "Output", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
