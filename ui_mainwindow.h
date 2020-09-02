/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionload_last_session;
    QAction *actionsave_session;
    QAction *actionLoad_from_FILE;
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *label;
    QPushButton *startProgram;
    QPushButton *searchArduino;
    QLabel *welcomeLabel;
    QWidget *page_2;
    QLineEdit *currentLine;
    QLabel *currentLabel;
    QPushButton *clearAllPushButton;
    QPushButton *validatePushButton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *sampLabel;
    QLabel *cycLabel;
    QLabel *ampLabel;
    QLabel *perLabel;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *samplingLine;
    QLineEdit *cyclesLine;
    QLineEdit *amplitudeLine;
    QLineEdit *periodLine;
    QListWidget *listWidget;
    QPushButton *addCurrentButton;
    QPushButton *replacePushButton;
    QPushButton *deletePushButton;
    QLabel *warningDataLabel;
    QPushButton *sendDataButton;
    QPushButton *playButton;
    QCustomPlot *plot;
    QLabel *cycleLabel;
    QLabel *labelToggle;
    QLabel *labelMarginL;
    QLabel *labelSignal;
    QLabel *labelMarginR;
    QLabel *labelMarginUp;
    QLabel *labelMarginDown;
    QLabel *labelSignal_2;
    QLabel *labelMarginR_2;
    QLabel *labelMarginL_2;
    QLabel *labelToggle_2;
    QLabel *labelMarginUp_2;
    QLabel *labelMarginDown_2;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QMenu *menufile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 480);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        actionload_last_session = new QAction(MainWindow);
        actionload_last_session->setObjectName(QStringLiteral("actionload_last_session"));
        QFont font;
        font.setPointSize(14);
        actionload_last_session->setFont(font);
        actionsave_session = new QAction(MainWindow);
        actionsave_session->setObjectName(QStringLiteral("actionsave_session"));
        actionsave_session->setFont(font);
        actionLoad_from_FILE = new QAction(MainWindow);
        actionLoad_from_FILE->setObjectName(QStringLiteral("actionLoad_from_FILE"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 781, 441));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        label = new QLabel(page);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 30, 701, 51));
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setWeight(75);
        label->setFont(font1);
        startProgram = new QPushButton(page);
        startProgram->setObjectName(QStringLiteral("startProgram"));
        startProgram->setGeometry(QRect(180, 120, 371, 141));
        QFont font2;
        font2.setPointSize(18);
        font2.setBold(true);
        font2.setItalic(true);
        font2.setWeight(75);
        startProgram->setFont(font2);
        searchArduino = new QPushButton(page);
        searchArduino->setObjectName(QStringLiteral("searchArduino"));
        searchArduino->setGeometry(QRect(600, 210, 151, 81));
        QFont font3;
        font3.setFamily(QStringLiteral("Lato Black"));
        font3.setPointSize(14);
        font3.setBold(true);
        font3.setWeight(75);
        searchArduino->setFont(font3);
        welcomeLabel = new QLabel(page);
        welcomeLabel->setObjectName(QStringLiteral("welcomeLabel"));
        welcomeLabel->setGeometry(QRect(110, 100, 651, 121));
        QFont font4;
        font4.setPointSize(22);
        font4.setBold(true);
        font4.setItalic(true);
        font4.setWeight(75);
        welcomeLabel->setFont(font4);
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        currentLine = new QLineEdit(page_2);
        currentLine->setObjectName(QStringLiteral("currentLine"));
        currentLine->setGeometry(QRect(140, 240, 89, 37));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(currentLine->sizePolicy().hasHeightForWidth());
        currentLine->setSizePolicy(sizePolicy1);
        currentLine->setMaximumSize(QSize(89, 37));
        currentLine->setFont(font);
        currentLabel = new QLabel(page_2);
        currentLabel->setObjectName(QStringLiteral("currentLabel"));
        currentLabel->setGeometry(QRect(10, 240, 131, 31));
        QFont font5;
        font5.setFamily(QStringLiteral("Bitstream Vera Serif"));
        font5.setPointSize(11);
        font5.setBold(true);
        font5.setWeight(75);
        currentLabel->setFont(font5);
        currentLabel->setStyleSheet(QStringLiteral("color: rgb(170, 0, 0);"));
        clearAllPushButton = new QPushButton(page_2);
        clearAllPushButton->setObjectName(QStringLiteral("clearAllPushButton"));
        clearAllPushButton->setGeometry(QRect(240, 320, 71, 41));
        QFont font6;
        font6.setFamily(QStringLiteral("Quicksand"));
        font6.setBold(true);
        font6.setWeight(75);
        clearAllPushButton->setFont(font6);
        validatePushButton = new QPushButton(page_2);
        validatePushButton->setObjectName(QStringLiteral("validatePushButton"));
        validatePushButton->setGeometry(QRect(240, 80, 91, 51));
        QFont font7;
        font7.setFamily(QStringLiteral("Quicksand"));
        font7.setPointSize(12);
        font7.setBold(true);
        font7.setWeight(75);
        validatePushButton->setFont(font7);
        layoutWidget = new QWidget(page_2);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(60, 30, 171, 201));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(9);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        sampLabel = new QLabel(layoutWidget);
        sampLabel->setObjectName(QStringLiteral("sampLabel"));
        QFont font8;
        font8.setFamily(QStringLiteral("Bitstream Vera Serif"));
        font8.setPointSize(10);
        font8.setBold(true);
        font8.setWeight(75);
        sampLabel->setFont(font8);
        sampLabel->setStyleSheet(QStringLiteral("color: rgb(170, 0, 0);"));

        verticalLayout->addWidget(sampLabel);

        cycLabel = new QLabel(layoutWidget);
        cycLabel->setObjectName(QStringLiteral("cycLabel"));
        cycLabel->setFont(font8);
        cycLabel->setStyleSheet(QStringLiteral("color: rgb(170, 0, 0);"));

        verticalLayout->addWidget(cycLabel);

        ampLabel = new QLabel(layoutWidget);
        ampLabel->setObjectName(QStringLiteral("ampLabel"));
        ampLabel->setFont(font8);
        ampLabel->setStyleSheet(QStringLiteral("color: rgb(0, 0, 255);"));

        verticalLayout->addWidget(ampLabel);

        perLabel = new QLabel(layoutWidget);
        perLabel->setObjectName(QStringLiteral("perLabel"));
        perLabel->setFont(font8);
        perLabel->setStyleSheet(QStringLiteral("color: rgb(0, 0, 255);"));

        verticalLayout->addWidget(perLabel);

        layoutWidget1 = new QWidget(page_2);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(140, 30, 91, 211));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setSpacing(8);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        samplingLine = new QLineEdit(layoutWidget1);
        samplingLine->setObjectName(QStringLiteral("samplingLine"));
        samplingLine->setMaximumSize(QSize(89, 37));
        samplingLine->setFont(font);

        verticalLayout_2->addWidget(samplingLine);

        cyclesLine = new QLineEdit(layoutWidget1);
        cyclesLine->setObjectName(QStringLiteral("cyclesLine"));
        cyclesLine->setMaximumSize(QSize(89, 37));
        cyclesLine->setFont(font);

        verticalLayout_2->addWidget(cyclesLine);

        amplitudeLine = new QLineEdit(layoutWidget1);
        amplitudeLine->setObjectName(QStringLiteral("amplitudeLine"));
        amplitudeLine->setMaximumSize(QSize(89, 37));
        amplitudeLine->setFont(font);

        verticalLayout_2->addWidget(amplitudeLine);

        periodLine = new QLineEdit(layoutWidget1);
        periodLine->setObjectName(QStringLiteral("periodLine"));
        periodLine->setMaximumSize(QSize(89, 37));
        periodLine->setFont(font);

        verticalLayout_2->addWidget(periodLine);

        listWidget = new QListWidget(page_2);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(240, 140, 71, 171));
        QFont font9;
        font9.setPointSize(12);
        listWidget->setFont(font9);
        addCurrentButton = new QPushButton(page_2);
        addCurrentButton->setObjectName(QStringLiteral("addCurrentButton"));
        addCurrentButton->setGeometry(QRect(160, 300, 51, 41));
        addCurrentButton->setFont(font6);
        replacePushButton = new QPushButton(page_2);
        replacePushButton->setObjectName(QStringLiteral("replacePushButton"));
        replacePushButton->setGeometry(QRect(90, 300, 51, 41));
        replacePushButton->setFont(font6);
        deletePushButton = new QPushButton(page_2);
        deletePushButton->setObjectName(QStringLiteral("deletePushButton"));
        deletePushButton->setGeometry(QRect(130, 360, 51, 41));
        deletePushButton->setFont(font6);
        warningDataLabel = new QLabel(page_2);
        warningDataLabel->setObjectName(QStringLiteral("warningDataLabel"));
        warningDataLabel->setGeometry(QRect(110, 0, 131, 22));
        sendDataButton = new QPushButton(page_2);
        sendDataButton->setObjectName(QStringLiteral("sendDataButton"));
        sendDataButton->setGeometry(QRect(240, 10, 91, 51));
        QFont font10;
        font10.setFamily(QStringLiteral("Quicksand"));
        font10.setPointSize(18);
        font10.setBold(true);
        font10.setWeight(75);
        sendDataButton->setFont(font10);
        playButton = new QPushButton(page_2);
        playButton->setObjectName(QStringLiteral("playButton"));
        playButton->setGeometry(QRect(100, 310, 101, 91));
        playButton->setMinimumSize(QSize(50, 50));
        playButton->setIconSize(QSize(111, 91));
        plot = new QCustomPlot(page_2);
        plot->setObjectName(QStringLiteral("plot"));
        plot->setGeometry(QRect(340, 70, 441, 341));
        cycleLabel = new QLabel(page_2);
        cycleLabel->setObjectName(QStringLiteral("cycleLabel"));
        cycleLabel->setGeometry(QRect(430, 20, 241, 51));
        QFont font11;
        font11.setFamily(QStringLiteral("Droid Sans Fallback"));
        font11.setPointSize(18);
        cycleLabel->setFont(font11);
        labelToggle = new QLabel(page_2);
        labelToggle->setObjectName(QStringLiteral("labelToggle"));
        labelToggle->setGeometry(QRect(10, 140, 16, 91));
        QFont font12;
        font12.setFamily(QStringLiteral("Bitstream Vera Serif"));
        font12.setPointSize(8);
        font12.setBold(true);
        font12.setWeight(75);
        labelToggle->setFont(font12);
        labelToggle->setStyleSheet(QStringLiteral("color: rgb(0, 0, 255);"));
        labelMarginL = new QLabel(page_2);
        labelMarginL->setObjectName(QStringLiteral("labelMarginL"));
        labelMarginL->setGeometry(QRect(0, 130, 21, 121));
        QFont font13;
        font13.setFamily(QStringLiteral("Bitstream Vera Serif"));
        font13.setPointSize(11);
        font13.setBold(false);
        font13.setWeight(50);
        labelMarginL->setFont(font13);
        labelSignal = new QLabel(page_2);
        labelSignal->setObjectName(QStringLiteral("labelSignal"));
        labelSignal->setGeometry(QRect(30, 150, 16, 81));
        QFont font14;
        font14.setFamily(QStringLiteral("Bitstream Vera Serif"));
        font14.setPointSize(7);
        font14.setBold(true);
        font14.setWeight(75);
        labelSignal->setFont(font14);
        labelSignal->setStyleSheet(QStringLiteral("color: rgb(0, 0, 255);"));
        labelMarginR = new QLabel(page_2);
        labelMarginR->setObjectName(QStringLiteral("labelMarginR"));
        labelMarginR->setGeometry(QRect(50, 130, 21, 121));
        labelMarginR->setFont(font13);
        labelMarginUp = new QLabel(page_2);
        labelMarginUp->setObjectName(QStringLiteral("labelMarginUp"));
        labelMarginUp->setGeometry(QRect(0, 120, 231, 16));
        QFont font15;
        font15.setFamily(QStringLiteral("Bitstream Vera Serif"));
        font15.setBold(true);
        font15.setWeight(75);
        labelMarginUp->setFont(font15);
        labelMarginDown = new QLabel(page_2);
        labelMarginDown->setObjectName(QStringLiteral("labelMarginDown"));
        labelMarginDown->setGeometry(QRect(0, 220, 231, 16));
        labelMarginDown->setFont(font15);
        labelSignal_2 = new QLabel(page_2);
        labelSignal_2->setObjectName(QStringLiteral("labelSignal_2"));
        labelSignal_2->setGeometry(QRect(30, 50, 16, 81));
        labelSignal_2->setFont(font14);
        labelSignal_2->setStyleSheet(QStringLiteral("color: rgb(170, 0, 0);"));
        labelMarginR_2 = new QLabel(page_2);
        labelMarginR_2->setObjectName(QStringLiteral("labelMarginR_2"));
        labelMarginR_2->setGeometry(QRect(50, 30, 21, 121));
        labelMarginR_2->setFont(font13);
        labelMarginL_2 = new QLabel(page_2);
        labelMarginL_2->setObjectName(QStringLiteral("labelMarginL_2"));
        labelMarginL_2->setGeometry(QRect(0, 30, 21, 121));
        labelMarginL_2->setFont(font13);
        labelToggle_2 = new QLabel(page_2);
        labelToggle_2->setObjectName(QStringLiteral("labelToggle_2"));
        labelToggle_2->setGeometry(QRect(10, 30, 20, 111));
        labelToggle_2->setFont(font12);
        labelToggle_2->setStyleSheet(QStringLiteral("color: rgb(170, 0, 0);"));
        labelMarginUp_2 = new QLabel(page_2);
        labelMarginUp_2->setObjectName(QStringLiteral("labelMarginUp_2"));
        labelMarginUp_2->setGeometry(QRect(0, 10, 231, 16));
        labelMarginUp_2->setFont(font15);
        labelMarginDown_2 = new QLabel(page_2);
        labelMarginDown_2->setObjectName(QStringLiteral("labelMarginDown_2"));
        labelMarginDown_2->setGeometry(QRect(0, 270, 231, 16));
        labelMarginDown_2->setFont(font15);
        stackedWidget->addWidget(page_2);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(770, 0, 31, 21));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 20));
        menufile = new QMenu(menuBar);
        menufile->setObjectName(QStringLiteral("menufile"));
        menufile->setFont(font);
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menufile->menuAction());
        menufile->addAction(actionload_last_session);
        menufile->addAction(actionsave_session);
        menufile->addAction(actionLoad_from_FILE);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionload_last_session->setText(QApplication::translate("MainWindow", "load last session", nullptr));
        actionsave_session->setText(QApplication::translate("MainWindow", "save session", nullptr));
        actionLoad_from_FILE->setText(QApplication::translate("MainWindow", "Load from FILE", nullptr));
        label->setText(QString());
        startProgram->setText(QApplication::translate("MainWindow", "START", nullptr));
        searchArduino->setText(QApplication::translate("MainWindow", "Connecte", nullptr));
        welcomeLabel->setText(QApplication::translate("MainWindow", "Press connecte button ", nullptr));
        currentLabel->setText(QApplication::translate("MainWindow", "        Enter \n"
" Current (mA): ", nullptr));
        clearAllPushButton->setText(QApplication::translate("MainWindow", " Clear \n"
" All", nullptr));
        validatePushButton->setText(QApplication::translate("MainWindow", "Validate \n"
"data", nullptr));
        sampLabel->setText(QApplication::translate("MainWindow", " Sampling \n"
"     (ms):", nullptr));
        cycLabel->setText(QApplication::translate("MainWindow", "   Cycles \n"
"  number:", nullptr));
        ampLabel->setText(QApplication::translate("MainWindow", " Amplitude \n"
"     (mA) :", nullptr));
        perLabel->setText(QApplication::translate("MainWindow", "     Period \n"
"       (ms):", nullptr));
        addCurrentButton->setText(QApplication::translate("MainWindow", "Add", nullptr));
        replacePushButton->setText(QApplication::translate("MainWindow", "Replace", nullptr));
        deletePushButton->setText(QApplication::translate("MainWindow", "Delete", nullptr));
        warningDataLabel->setText(QApplication::translate("MainWindow", "ENTER ALL DATA", nullptr));
        sendDataButton->setText(QApplication::translate("MainWindow", "SEND", nullptr));
        playButton->setText(QString());
        cycleLabel->setText(QString());
        labelToggle->setText(QApplication::translate("MainWindow", "T\n"
"O\n"
"G\n"
"G\n"
"L\n"
"E", nullptr));
        labelMarginL->setText(QApplication::translate("MainWindow", "|\n"
"|\n"
"|\n"
"|\n"
"|\n"
"", nullptr));
        labelSignal->setText(QApplication::translate("MainWindow", "S\n"
"I\n"
"G\n"
"N\n"
"A\n"
"L", nullptr));
        labelMarginR->setText(QApplication::translate("MainWindow", "|\n"
"|\n"
"|\n"
"|\n"
"|\n"
"", nullptr));
        labelMarginUp->setText(QApplication::translate("MainWindow", "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ", nullptr));
        labelMarginDown->setText(QApplication::translate("MainWindow", "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ", nullptr));
        labelSignal_2->setText(QApplication::translate("MainWindow", "S\n"
"I\n"
"G\n"
"N\n"
"A\n"
"L", nullptr));
        labelMarginR_2->setText(QApplication::translate("MainWindow", "|\n"
"|\n"
"|\n"
"|\n"
"|\n"
"", nullptr));
        labelMarginL_2->setText(QApplication::translate("MainWindow", "|\n"
"|\n"
"|\n"
"|\n"
"|\n"
"", nullptr));
        labelToggle_2->setText(QApplication::translate("MainWindow", "C\n"
"U\n"
"R\n"
"R\n"
"E\n"
"N\n"
"T", nullptr));
        labelMarginUp_2->setText(QApplication::translate("MainWindow", "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ", nullptr));
        labelMarginDown_2->setText(QApplication::translate("MainWindow", "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "exit", nullptr));
        menufile->setTitle(QApplication::translate("MainWindow", "file", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
