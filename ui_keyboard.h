/********************************************************************************
** Form generated from reading UI file 'keyboard.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KEYBOARD_H
#define UI_KEYBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Keyboard
{
public:
    QLineEdit *lineEdit;
    QPushButton *backButton;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *Button7;
    QPushButton *Button8;
    QPushButton *Button9;
    QPushButton *Button4;
    QPushButton *Button5;
    QPushButton *Button6;
    QPushButton *Button1;
    QPushButton *Button2;
    QPushButton *Button3;
    QPushButton *clear;
    QPushButton *Button0;
    QPushButton *enterButton;

    void setupUi(QWidget *Keyboard)
    {
        if (Keyboard->objectName().isEmpty())
            Keyboard->setObjectName(QStringLiteral("Keyboard"));
        Keyboard->setEnabled(true);
        Keyboard->resize(294, 301);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Keyboard->sizePolicy().hasHeightForWidth());
        Keyboard->setSizePolicy(sizePolicy);
        Keyboard->setMinimumSize(QSize(0, 0));
        Keyboard->setMaximumSize(QSize(340, 385));
        Keyboard->setLayoutDirection(Qt::LeftToRight);
        Keyboard->setStyleSheet(QLatin1String("QWidget{\n"
"	background-color: rgb(135, 135, 135);\n"
"}\n"
""));
        lineEdit = new QLineEdit(Keyboard);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(20, 10, 81, 31));
        lineEdit->setStyleSheet(QLatin1String("QLineEdit{\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius:10px;\n"
"}\n"
"\n"
"\n"
""));
        backButton = new QPushButton(Keyboard);
        backButton->setObjectName(QStringLiteral("backButton"));
        backButton->setGeometry(QRect(110, 10, 51, 31));
        QFont font;
        font.setFamily(QStringLiteral("Source Code Pro"));
        font.setBold(true);
        font.setWeight(75);
        backButton->setFont(font);
        backButton->setStyleSheet(QLatin1String("QPushButton{\n"
"background-color: #FF8C00;\n"
"border-style: outset;\n"
"border-color:beige;\n"
"border: 1px beige;\n"
"border-radius: 10px;\n"
"padding: 5px;\n"
"}\n"
"\n"
"QPushButton::Pressed{\n"
"background-color: rgb(200, 174, 44)9;\n"
"border-style: inset;\n"
"border: 1px solid gray;\n"
"padding: 5px;\n"
"}\n"
""));
        layoutWidget = new QWidget(Keyboard);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(3, 49, 281, 251));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout->setHorizontalSpacing(6);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        Button7 = new QPushButton(layoutWidget);
        Button7->setObjectName(QStringLiteral("Button7"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Button7->sizePolicy().hasHeightForWidth());
        Button7->setSizePolicy(sizePolicy1);
        Button7->setMinimumSize(QSize(80, 50));
        Button7->setMaximumSize(QSize(80, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("Noto Sans Tagalog"));
        font1.setPointSize(12);
        Button7->setFont(font1);
        Button7->setStyleSheet(QStringLiteral("background-color: rgb(221, 221, 221);"));
        Button7->setIconSize(QSize(10, 10));

        gridLayout->addWidget(Button7, 0, 0, 1, 1);

        Button8 = new QPushButton(layoutWidget);
        Button8->setObjectName(QStringLiteral("Button8"));
        sizePolicy1.setHeightForWidth(Button8->sizePolicy().hasHeightForWidth());
        Button8->setSizePolicy(sizePolicy1);
        Button8->setMinimumSize(QSize(80, 50));
        Button8->setMaximumSize(QSize(80, 31));
        Button8->setFont(font1);
        Button8->setStyleSheet(QStringLiteral("background-color: rgb(221, 221, 221);"));

        gridLayout->addWidget(Button8, 0, 1, 1, 1);

        Button9 = new QPushButton(layoutWidget);
        Button9->setObjectName(QStringLiteral("Button9"));
        sizePolicy1.setHeightForWidth(Button9->sizePolicy().hasHeightForWidth());
        Button9->setSizePolicy(sizePolicy1);
        Button9->setMinimumSize(QSize(80, 50));
        Button9->setMaximumSize(QSize(80, 31));
        Button9->setFont(font1);
        Button9->setStyleSheet(QStringLiteral("background-color: rgb(221, 221, 221);"));

        gridLayout->addWidget(Button9, 0, 2, 1, 1);

        Button4 = new QPushButton(layoutWidget);
        Button4->setObjectName(QStringLiteral("Button4"));
        sizePolicy1.setHeightForWidth(Button4->sizePolicy().hasHeightForWidth());
        Button4->setSizePolicy(sizePolicy1);
        Button4->setMinimumSize(QSize(80, 50));
        Button4->setMaximumSize(QSize(80, 31));
        Button4->setFont(font1);
        Button4->setStyleSheet(QStringLiteral("background-color: rgb(221, 221, 221);"));

        gridLayout->addWidget(Button4, 1, 0, 1, 1);

        Button5 = new QPushButton(layoutWidget);
        Button5->setObjectName(QStringLiteral("Button5"));
        sizePolicy1.setHeightForWidth(Button5->sizePolicy().hasHeightForWidth());
        Button5->setSizePolicy(sizePolicy1);
        Button5->setMinimumSize(QSize(80, 50));
        Button5->setMaximumSize(QSize(80, 31));
        Button5->setFont(font1);
        Button5->setStyleSheet(QStringLiteral("background-color: rgb(221, 221, 221);"));

        gridLayout->addWidget(Button5, 1, 1, 1, 1);

        Button6 = new QPushButton(layoutWidget);
        Button6->setObjectName(QStringLiteral("Button6"));
        sizePolicy1.setHeightForWidth(Button6->sizePolicy().hasHeightForWidth());
        Button6->setSizePolicy(sizePolicy1);
        Button6->setMinimumSize(QSize(80, 50));
        Button6->setMaximumSize(QSize(80, 31));
        Button6->setFont(font1);
        Button6->setStyleSheet(QStringLiteral("background-color: rgb(221, 221, 221);"));

        gridLayout->addWidget(Button6, 1, 2, 1, 1);

        Button1 = new QPushButton(layoutWidget);
        Button1->setObjectName(QStringLiteral("Button1"));
        sizePolicy1.setHeightForWidth(Button1->sizePolicy().hasHeightForWidth());
        Button1->setSizePolicy(sizePolicy1);
        Button1->setMinimumSize(QSize(80, 50));
        Button1->setMaximumSize(QSize(80, 31));
        Button1->setFont(font1);
        Button1->setStyleSheet(QStringLiteral("background-color: rgb(221, 221, 221);"));

        gridLayout->addWidget(Button1, 2, 0, 1, 1);

        Button2 = new QPushButton(layoutWidget);
        Button2->setObjectName(QStringLiteral("Button2"));
        Button2->setEnabled(true);
        sizePolicy1.setHeightForWidth(Button2->sizePolicy().hasHeightForWidth());
        Button2->setSizePolicy(sizePolicy1);
        Button2->setMinimumSize(QSize(80, 50));
        Button2->setMaximumSize(QSize(80, 31));
        Button2->setFont(font1);
        Button2->setStyleSheet(QStringLiteral("background-color: rgb(221, 221, 221);"));

        gridLayout->addWidget(Button2, 2, 1, 1, 1);

        Button3 = new QPushButton(layoutWidget);
        Button3->setObjectName(QStringLiteral("Button3"));
        sizePolicy1.setHeightForWidth(Button3->sizePolicy().hasHeightForWidth());
        Button3->setSizePolicy(sizePolicy1);
        Button3->setMinimumSize(QSize(80, 50));
        Button3->setMaximumSize(QSize(80, 31));
        Button3->setFont(font1);
        Button3->setStyleSheet(QStringLiteral("background-color: rgb(221, 221, 221);"));

        gridLayout->addWidget(Button3, 2, 2, 1, 1);

        clear = new QPushButton(layoutWidget);
        clear->setObjectName(QStringLiteral("clear"));
        sizePolicy1.setHeightForWidth(clear->sizePolicy().hasHeightForWidth());
        clear->setSizePolicy(sizePolicy1);
        clear->setMinimumSize(QSize(85, 50));
        clear->setMaximumSize(QSize(80, 31));
        clear->setFont(font);
        clear->setStyleSheet(QLatin1String("QPushButton{\n"
"background-color: #FF8C00;\n"
"border-style: outset;\n"
"border-color:beige;\n"
"border: 1px beige;\n"
"border-radius: 10px;\n"
"padding: 5px;\n"
"}\n"
"\n"
"QPushButton::Pressed{\n"
"background-color: rgb(200, 174, 44)9;\n"
"border-style: inset;\n"
"border: 1px solid gray;\n"
"padding: 5px;\n"
"}\n"
""));

        gridLayout->addWidget(clear, 3, 0, 1, 1);

        Button0 = new QPushButton(layoutWidget);
        Button0->setObjectName(QStringLiteral("Button0"));
        sizePolicy1.setHeightForWidth(Button0->sizePolicy().hasHeightForWidth());
        Button0->setSizePolicy(sizePolicy1);
        Button0->setMinimumSize(QSize(80, 50));
        Button0->setMaximumSize(QSize(80, 28));
        QFont font2;
        font2.setFamily(QStringLiteral("Noto Sans Tagalog"));
        font2.setPointSize(12);
        font2.setBold(false);
        font2.setWeight(50);
        Button0->setFont(font2);
        Button0->setStyleSheet(QStringLiteral("background-color: rgb(221, 221, 221);"));

        gridLayout->addWidget(Button0, 3, 1, 1, 1);

        enterButton = new QPushButton(layoutWidget);
        enterButton->setObjectName(QStringLiteral("enterButton"));
        sizePolicy1.setHeightForWidth(enterButton->sizePolicy().hasHeightForWidth());
        enterButton->setSizePolicy(sizePolicy1);
        enterButton->setMinimumSize(QSize(85, 50));
        enterButton->setMaximumSize(QSize(80, 31));
        enterButton->setFont(font);
        enterButton->setStyleSheet(QLatin1String("QPushButton{\n"
"background-color: #FF8C00;\n"
"border-style: outset;\n"
"border-color:beige;\n"
"border: 1px beige;\n"
"border-radius: 10px;\n"
"padding: 5px;\n"
"}\n"
"\n"
"QPushButton::Pressed{\n"
"background-color: rgb(200, 174, 44)9;\n"
"border-style: inset;\n"
"border: 1px solid gray;\n"
"padding: 5px;\n"
"}\n"
""));

        gridLayout->addWidget(enterButton, 3, 2, 1, 1);


        retranslateUi(Keyboard);

        QMetaObject::connectSlotsByName(Keyboard);
    } // setupUi

    void retranslateUi(QWidget *Keyboard)
    {
        backButton->setText(QApplication::translate("Keyboard", "Back", nullptr));
        Button7->setText(QApplication::translate("Keyboard", "7", nullptr));
        Button8->setText(QApplication::translate("Keyboard", "8", nullptr));
        Button9->setText(QApplication::translate("Keyboard", "9", nullptr));
        Button4->setText(QApplication::translate("Keyboard", "4", nullptr));
        Button5->setText(QApplication::translate("Keyboard", "5", nullptr));
        Button6->setText(QApplication::translate("Keyboard", "6", nullptr));
        Button1->setText(QApplication::translate("Keyboard", "1", nullptr));
#ifndef QT_NO_ACCESSIBILITY
        Button2->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
        Button2->setText(QApplication::translate("Keyboard", "2", nullptr));
        Button3->setText(QApplication::translate("Keyboard", "3", nullptr));
        clear->setText(QApplication::translate("Keyboard", "Clear", nullptr));
        Button0->setText(QApplication::translate("Keyboard", "0", nullptr));
        enterButton->setText(QApplication::translate("Keyboard", "Enter", nullptr));
        Q_UNUSED(Keyboard);
    } // retranslateUi

};

namespace Ui {
    class Keyboard: public Ui_Keyboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KEYBOARD_H
