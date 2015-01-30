/********************************************************************************
** Form generated from reading UI file 'qtwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTWINDOW_H
#define UI_QTWINDOW_H

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

class Ui_QtWindow
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtWindow)
    {
        if (QtWindow->objectName().isEmpty())
            QtWindow->setObjectName(QStringLiteral("QtWindow"));
        QtWindow->resize(400, 300);
        menuBar = new QMenuBar(QtWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        QtWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QtWindow->addToolBar(mainToolBar);
        centralWidget = new QWidget(QtWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QtWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QtWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QtWindow->setStatusBar(statusBar);

        retranslateUi(QtWindow);

        QMetaObject::connectSlotsByName(QtWindow);
    } // setupUi

    void retranslateUi(QMainWindow *QtWindow)
    {
        QtWindow->setWindowTitle(QApplication::translate("QtWindow", "QtWindow", 0));
    } // retranslateUi

};

namespace Ui {
    class QtWindow: public Ui_QtWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTWINDOW_H
