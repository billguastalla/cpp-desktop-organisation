/********************************************************************************
** Form generated from reading UI file 'SocialOrganisation.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOCIALORGANISATION_H
#define UI_SOCIALORGANISATION_H

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

class Ui_SocialOrganisationClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SocialOrganisationClass)
    {
        if (SocialOrganisationClass->objectName().isEmpty())
            SocialOrganisationClass->setObjectName(QStringLiteral("SocialOrganisationClass"));
        SocialOrganisationClass->resize(600, 400);
        menuBar = new QMenuBar(SocialOrganisationClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        SocialOrganisationClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SocialOrganisationClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        SocialOrganisationClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(SocialOrganisationClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        SocialOrganisationClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(SocialOrganisationClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SocialOrganisationClass->setStatusBar(statusBar);

        retranslateUi(SocialOrganisationClass);

        QMetaObject::connectSlotsByName(SocialOrganisationClass);
    } // setupUi

    void retranslateUi(QMainWindow *SocialOrganisationClass)
    {
        SocialOrganisationClass->setWindowTitle(QApplication::translate("SocialOrganisationClass", "SocialOrganisation", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SocialOrganisationClass: public Ui_SocialOrganisationClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOCIALORGANISATION_H
