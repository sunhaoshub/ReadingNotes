/********************************************************************************
** Form generated from reading UI file 'gamepanel.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEPANEL_H
#define UI_GAMEPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "buttongroup.h"
#include "scorepanel.h"

QT_BEGIN_NAMESPACE

class Ui_GamePane
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    ScorePanel *scorePanel;
    QSpacerItem *verticalSpacer;
    ButtonGroup *btnGroup;
    QSpacerItem *verticalSpacer_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GamePane)
    {
        if (GamePane->objectName().isEmpty())
            GamePane->setObjectName(QStringLiteral("GamePane"));
        GamePane->resize(400, 300);
        centralWidget = new QWidget(GamePane);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(359, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        scorePanel = new ScorePanel(widget);
        scorePanel->setObjectName(QStringLiteral("scorePanel"));

        horizontalLayout->addWidget(scorePanel);


        verticalLayout->addWidget(widget);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        btnGroup = new ButtonGroup(centralWidget);
        btnGroup->setObjectName(QStringLiteral("btnGroup"));

        verticalLayout->addWidget(btnGroup);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        GamePane->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(GamePane);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 17));
        GamePane->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GamePane);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        GamePane->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(GamePane);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        GamePane->setStatusBar(statusBar);

        retranslateUi(GamePane);

        QMetaObject::connectSlotsByName(GamePane);
    } // setupUi

    void retranslateUi(QMainWindow *GamePane)
    {
        GamePane->setWindowTitle(QApplication::translate("GamePane", "GamePane", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GamePane: public Ui_GamePane {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEPANEL_H
