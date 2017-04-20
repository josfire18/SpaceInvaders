/********************************************************************************
** Form generated from reading UI file 'mainmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENU_H
#define UI_MAINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainMenu
{
public:
    QWidget *centralWidget;
    QPushButton *cmdStartGame;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainMenu)
    {
        if (MainMenu->objectName().isEmpty())
            MainMenu->setObjectName(QStringLiteral("MainMenu"));
        MainMenu->resize(488, 334);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainMenu->sizePolicy().hasHeightForWidth());
        MainMenu->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainMenu);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        cmdStartGame = new QPushButton(centralWidget);
        cmdStartGame->setObjectName(QStringLiteral("cmdStartGame"));
        cmdStartGame->setGeometry(QRect(200, 232, 281, 41));
        sizePolicy.setHeightForWidth(cmdStartGame->sizePolicy().hasHeightForWidth());
        cmdStartGame->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QStringLiteral("Franklin Gothic Demi"));
        font.setPointSize(18);
        font.setBold(false);
        font.setWeight(50);
        cmdStartGame->setFont(font);
        MainMenu->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainMenu);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 488, 21));
        MainMenu->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainMenu);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainMenu->setStatusBar(statusBar);

        retranslateUi(MainMenu);

        QMetaObject::connectSlotsByName(MainMenu);
    } // setupUi

    void retranslateUi(QMainWindow *MainMenu)
    {
        MainMenu->setWindowTitle(QApplication::translate("MainMenu", "MainMenu", 0));
        cmdStartGame->setText(QApplication::translate("MainMenu", "S       T       A       R       T", 0));
    } // retranslateUi

};

namespace Ui {
    class MainMenu: public Ui_MainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H
