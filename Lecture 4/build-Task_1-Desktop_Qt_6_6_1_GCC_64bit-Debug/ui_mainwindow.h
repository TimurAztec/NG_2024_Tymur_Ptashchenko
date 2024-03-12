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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *b_select;
    QLabel *l_songName;
    QProgressBar *p_position;
    QHBoxLayout *horizontalLayout;
    QPushButton *b_previous;
    QPushButton *b_playPause;
    QPushButton *b_next;
    QSlider *s_position;
    QSlider *s_volume;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QListWidget *ls_listWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(489, 224);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        b_select = new QPushButton(centralwidget);
        b_select->setObjectName("b_select");

        verticalLayout_2->addWidget(b_select);

        l_songName = new QLabel(centralwidget);
        l_songName->setObjectName("l_songName");

        verticalLayout_2->addWidget(l_songName);

        p_position = new QProgressBar(centralwidget);
        p_position->setObjectName("p_position");
        p_position->setValue(24);

        verticalLayout_2->addWidget(p_position);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        b_previous = new QPushButton(centralwidget);
        b_previous->setObjectName("b_previous");
        b_previous->setMinimumSize(QSize(50, 50));
        b_previous->setMaximumSize(QSize(50, 50));

        horizontalLayout->addWidget(b_previous);

        b_playPause = new QPushButton(centralwidget);
        b_playPause->setObjectName("b_playPause");
        b_playPause->setMinimumSize(QSize(50, 50));
        b_playPause->setMaximumSize(QSize(50, 50));

        horizontalLayout->addWidget(b_playPause);

        b_next = new QPushButton(centralwidget);
        b_next->setObjectName("b_next");
        b_next->setMinimumSize(QSize(50, 50));
        b_next->setMaximumSize(QSize(50, 50));

        horizontalLayout->addWidget(b_next);


        verticalLayout_2->addLayout(horizontalLayout);

        s_position = new QSlider(centralwidget);
        s_position->setObjectName("s_position");
        s_position->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(s_position);


        horizontalLayout_2->addLayout(verticalLayout_2);

        s_volume = new QSlider(centralwidget);
        s_volume->setObjectName("s_volume");
        s_volume->setOrientation(Qt::Vertical);

        horizontalLayout_2->addWidget(s_volume);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(centralwidget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        ls_listWidget = new QListWidget(centralwidget);
        ls_listWidget->setObjectName("ls_listWidget");

        verticalLayout->addWidget(ls_listWidget);


        horizontalLayout_2->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 489, 21));
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
        b_select->setText(QCoreApplication::translate("MainWindow", "Add Song", nullptr));
        l_songName->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        b_previous->setText(QCoreApplication::translate("MainWindow", "|<", nullptr));
        b_playPause->setText(QCoreApplication::translate("MainWindow", ">", nullptr));
        b_next->setText(QCoreApplication::translate("MainWindow", ">|", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Playlist:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
