/********************************************************************************
** Form generated from reading UI file 'buttongroup.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUTTONGROUP_H
#define UI_BUTTONGROUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>
#include "mybutton.h"

QT_BEGIN_NAMESPACE

class Ui_ButtonGroup
{
public:
    QHBoxLayout *horizontalLayout;
    QStackedWidget *stackedWidget;
    QWidget *startPage;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    MyButton *start;
    QSpacerItem *horizontalSpacer_2;
    QWidget *playCardPage;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    MyButton *playCard;
    QSpacerItem *horizontalSpacer_4;
    QWidget *PlayorPassPage;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_5;
    MyButton *pass;
    QSpacerItem *horizontalSpacer_6;
    MyButton *playCard1;
    QSpacerItem *horizontalSpacer_7;
    QWidget *callLordPage;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_15;
    MyButton *giveup;
    QSpacerItem *horizontalSpacer_17;
    MyButton *twoScore;
    QSpacerItem *horizontalSpacer_18;
    MyButton *oneScore;
    QSpacerItem *horizontalSpacer_19;
    MyButton *threeScore;
    QSpacerItem *horizontalSpacer_16;
    QWidget *nullButton;

    void setupUi(QWidget *ButtonGroup)
    {
        if (ButtonGroup->objectName().isEmpty())
            ButtonGroup->setObjectName(QStringLiteral("ButtonGroup"));
        ButtonGroup->resize(516, 103);
        horizontalLayout = new QHBoxLayout(ButtonGroup);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        stackedWidget = new QStackedWidget(ButtonGroup);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        startPage = new QWidget();
        startPage->setObjectName(QStringLiteral("startPage"));
        horizontalLayout_2 = new QHBoxLayout(startPage);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(199, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        start = new MyButton(startPage);
        start->setObjectName(QStringLiteral("start"));

        horizontalLayout_2->addWidget(start);

        horizontalSpacer_2 = new QSpacerItem(199, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        stackedWidget->addWidget(startPage);
        playCardPage = new QWidget();
        playCardPage->setObjectName(QStringLiteral("playCardPage"));
        horizontalLayout_3 = new QHBoxLayout(playCardPage);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(199, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        playCard = new MyButton(playCardPage);
        playCard->setObjectName(QStringLiteral("playCard"));

        horizontalLayout_3->addWidget(playCard);

        horizontalSpacer_4 = new QSpacerItem(199, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        stackedWidget->addWidget(playCardPage);
        PlayorPassPage = new QWidget();
        PlayorPassPage->setObjectName(QStringLiteral("PlayorPassPage"));
        horizontalLayout_4 = new QHBoxLayout(PlayorPassPage);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_5 = new QSpacerItem(146, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        pass = new MyButton(PlayorPassPage);
        pass->setObjectName(QStringLiteral("pass"));

        horizontalLayout_4->addWidget(pass);

        horizontalSpacer_6 = new QSpacerItem(15, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);

        playCard1 = new MyButton(PlayorPassPage);
        playCard1->setObjectName(QStringLiteral("playCard1"));

        horizontalLayout_4->addWidget(playCard1);

        horizontalSpacer_7 = new QSpacerItem(146, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);

        stackedWidget->addWidget(PlayorPassPage);
        callLordPage = new QWidget();
        callLordPage->setObjectName(QStringLiteral("callLordPage"));
        horizontalLayout_8 = new QHBoxLayout(callLordPage);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalSpacer_15 = new QSpacerItem(49, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_15);

        giveup = new MyButton(callLordPage);
        giveup->setObjectName(QStringLiteral("giveup"));

        horizontalLayout_8->addWidget(giveup);

        horizontalSpacer_17 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_17);

        twoScore = new MyButton(callLordPage);
        twoScore->setObjectName(QStringLiteral("twoScore"));

        horizontalLayout_8->addWidget(twoScore);

        horizontalSpacer_18 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_18);

        oneScore = new MyButton(callLordPage);
        oneScore->setObjectName(QStringLiteral("oneScore"));

        horizontalLayout_8->addWidget(oneScore);

        horizontalSpacer_19 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_19);

        threeScore = new MyButton(callLordPage);
        threeScore->setObjectName(QStringLiteral("threeScore"));

        horizontalLayout_8->addWidget(threeScore);

        horizontalSpacer_16 = new QSpacerItem(49, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_16);

        stackedWidget->addWidget(callLordPage);
        nullButton = new QWidget();
        nullButton->setObjectName(QStringLiteral("nullButton"));
        stackedWidget->addWidget(nullButton);

        horizontalLayout->addWidget(stackedWidget);


        retranslateUi(ButtonGroup);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ButtonGroup);
    } // setupUi

    void retranslateUi(QWidget *ButtonGroup)
    {
        ButtonGroup->setWindowTitle(QApplication::translate("ButtonGroup", "Form", nullptr));
        start->setText(QApplication::translate("ButtonGroup", "PushButton", nullptr));
        playCard->setText(QApplication::translate("ButtonGroup", "PushButton", nullptr));
        pass->setText(QApplication::translate("ButtonGroup", "PushButton", nullptr));
        playCard1->setText(QApplication::translate("ButtonGroup", "PushButton", nullptr));
        giveup->setText(QApplication::translate("ButtonGroup", "PushButton", nullptr));
        twoScore->setText(QApplication::translate("ButtonGroup", "PushButton", nullptr));
        oneScore->setText(QApplication::translate("ButtonGroup", "PushButton", nullptr));
        threeScore->setText(QApplication::translate("ButtonGroup", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ButtonGroup: public Ui_ButtonGroup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUTTONGROUP_H
