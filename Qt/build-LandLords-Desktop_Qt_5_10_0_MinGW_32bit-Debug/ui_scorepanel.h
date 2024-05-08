/********************************************************************************
** Form generated from reading UI file 'scorepanel.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCOREPANEL_H
#define UI_SCOREPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ScorePanel
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_6;
    QLabel *label_5;
    QLabel *label_4;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_7;

    void setupUi(QWidget *ScorePanel)
    {
        if (ScorePanel->objectName().isEmpty())
            ScorePanel->setObjectName(QStringLiteral("ScorePanel"));
        ScorePanel->resize(154, 79);
        gridLayout = new QGridLayout(ScorePanel);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(ScorePanel);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QStringLiteral("Microsoft YaHei"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("color:rgb(255, 255, 255)"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(ScorePanel);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);
        label_2->setStyleSheet(QStringLiteral("color:rgb(255, 255, 255)"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        label_3 = new QLabel(ScorePanel);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);
        label_3->setStyleSheet(QStringLiteral("color:rgb(255, 255, 255)"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 0, 2, 1, 1);

        label_6 = new QLabel(ScorePanel);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);
        label_6->setStyleSheet(QStringLiteral("color:rgb(255, 255, 255)"));
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_6, 1, 0, 1, 1);

        label_5 = new QLabel(ScorePanel);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);
        label_5->setStyleSheet(QStringLiteral("color:rgb(255, 255, 255)"));
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_5, 1, 1, 1, 1);

        label_4 = new QLabel(ScorePanel);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);
        label_4->setStyleSheet(QStringLiteral("color:rgb(255, 255, 255)"));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 1, 2, 1, 1);

        label_8 = new QLabel(ScorePanel);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font);
        label_8->setStyleSheet(QStringLiteral("color:rgb(255, 255, 255)"));
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_8, 2, 0, 1, 1);

        label_9 = new QLabel(ScorePanel);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font);
        label_9->setStyleSheet(QStringLiteral("color:rgb(255, 255, 255)"));
        label_9->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_9, 2, 1, 1, 1);

        label_7 = new QLabel(ScorePanel);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);
        label_7->setStyleSheet(QStringLiteral("color:rgb(255, 255, 255)"));
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_7, 2, 2, 1, 1);


        retranslateUi(ScorePanel);

        QMetaObject::connectSlotsByName(ScorePanel);
    } // setupUi

    void retranslateUi(QWidget *ScorePanel)
    {
        ScorePanel->setWindowTitle(QApplication::translate("ScorePanel", "Form", nullptr));
        label->setText(QApplication::translate("ScorePanel", "\346\210\221", nullptr));
        label_2->setText(QApplication::translate("ScorePanel", "0", nullptr));
        label_3->setText(QApplication::translate("ScorePanel", "\345\210\206", nullptr));
        label_6->setText(QApplication::translate("ScorePanel", "\345\267\246\350\276\271\346\234\272\345\231\250\344\272\272", nullptr));
        label_5->setText(QApplication::translate("ScorePanel", "0", nullptr));
        label_4->setText(QApplication::translate("ScorePanel", "\345\210\206", nullptr));
        label_8->setText(QApplication::translate("ScorePanel", "\345\217\263\350\276\271\346\234\272\345\231\250\344\272\272", nullptr));
        label_9->setText(QApplication::translate("ScorePanel", "0", nullptr));
        label_7->setText(QApplication::translate("ScorePanel", "\345\210\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ScorePanel: public Ui_ScorePanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCOREPANEL_H
