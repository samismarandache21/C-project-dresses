/********************************************************************************
** Form generated from reading UI file 'rochii.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROCHII_H
#define UI_ROCHII_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_rochiiClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *rochiiClass)
    {
        if (rochiiClass->objectName().isEmpty())
            rochiiClass->setObjectName("rochiiClass");
        rochiiClass->resize(600, 400);
        menuBar = new QMenuBar(rochiiClass);
        menuBar->setObjectName("menuBar");
        rochiiClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(rochiiClass);
        mainToolBar->setObjectName("mainToolBar");
        rochiiClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(rochiiClass);
        centralWidget->setObjectName("centralWidget");
        rochiiClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(rochiiClass);
        statusBar->setObjectName("statusBar");
        rochiiClass->setStatusBar(statusBar);

        retranslateUi(rochiiClass);

        QMetaObject::connectSlotsByName(rochiiClass);
    } // setupUi

    void retranslateUi(QMainWindow *rochiiClass)
    {
        rochiiClass->setWindowTitle(QCoreApplication::translate("rochiiClass", "rochii", nullptr));
    } // retranslateUi

};

namespace Ui {
    class rochiiClass: public Ui_rochiiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROCHII_H
