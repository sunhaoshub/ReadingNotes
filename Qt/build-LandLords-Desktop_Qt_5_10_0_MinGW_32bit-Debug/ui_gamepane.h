/********************************************************************************
** Form generated from reading UI file 'gamepane.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEPANE_H
#define UI_GAMEPANE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GamePane
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GamePane)
    {
        if (GamePane->objectName().isEmpty())
            GamePane->setObjectName(QStringLiteral("GamePane"));
        GamePane->resize(400, 300);
        menuBar = new QMenuBar(GamePane);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        GamePane->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GamePane);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        GamePane->addToolBar(mainToolBar);
        centralWidget = new QWidget(GamePane);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        GamePane->setCentralWidget(centralWidget);
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

#endif // UI_GAMEPANE_H
