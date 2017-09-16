/********************************************************************************
** Form generated from reading UI file 'centralwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CENTRALWIDGET_H
#define UI_CENTRALWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CentralWidget
{
public:

    void setupUi(QWidget *CentralWidget)
    {
        if (CentralWidget->objectName().isEmpty())
            CentralWidget->setObjectName(QStringLiteral("CentralWidget"));
        CentralWidget->resize(400, 300);

        retranslateUi(CentralWidget);

        QMetaObject::connectSlotsByName(CentralWidget);
    } // setupUi

    void retranslateUi(QWidget *CentralWidget)
    {
        CentralWidget->setWindowTitle(QApplication::translate("CentralWidget", "CentralWidget", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CentralWidget: public Ui_CentralWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CENTRALWIDGET_H
