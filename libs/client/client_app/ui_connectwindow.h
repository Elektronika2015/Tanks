/********************************************************************************
** Form generated from reading UI file 'connectwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTWINDOW_H
#define UI_CONNECTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConnectWindow
{
public:
    QPushButton *connectButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *nameLineEdit;
    QLineEdit *serverAddresLineEdit;
    QLineEdit *serverPortLineEdit;
    QPushButton *backButton;
    QLabel *label_4;

    void setupUi(QWidget *ConnectWindow)
    {
        if (ConnectWindow->objectName().isEmpty())
            ConnectWindow->setObjectName(QStringLiteral("ConnectWindow"));
        ConnectWindow->resize(400, 300);
        connectButton = new QPushButton(ConnectWindow);
        connectButton->setObjectName(QStringLiteral("connectButton"));
        connectButton->setGeometry(QRect(300, 200, 75, 23));
        label = new QLabel(ConnectWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 50, 47, 13));
        label_2 = new QLabel(ConnectWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 80, 81, 16));
        label_3 = new QLabel(ConnectWindow);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 110, 47, 13));
        nameLineEdit = new QLineEdit(ConnectWindow);
        nameLineEdit->setObjectName(QStringLiteral("nameLineEdit"));
        nameLineEdit->setGeometry(QRect(130, 50, 113, 20));
        serverAddresLineEdit = new QLineEdit(ConnectWindow);
        serverAddresLineEdit->setObjectName(QStringLiteral("serverAddresLineEdit"));
        serverAddresLineEdit->setGeometry(QRect(130, 80, 113, 20));
        serverPortLineEdit = new QLineEdit(ConnectWindow);
        serverPortLineEdit->setObjectName(QStringLiteral("serverPortLineEdit"));
        serverPortLineEdit->setGeometry(QRect(130, 110, 113, 20));
        backButton = new QPushButton(ConnectWindow);
        backButton->setObjectName(QStringLiteral("backButton"));
        backButton->setGeometry(QRect(210, 200, 75, 23));
        label_4 = new QLabel(ConnectWindow);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(290, 80, 47, 13));

        retranslateUi(ConnectWindow);

        QMetaObject::connectSlotsByName(ConnectWindow);
    } // setupUi

    void retranslateUi(QWidget *ConnectWindow)
    {
        ConnectWindow->setWindowTitle(QApplication::translate("ConnectWindow", "Form", 0));
        connectButton->setText(QApplication::translate("ConnectWindow", "Po\305\202\304\205cz", 0));
        label->setText(QApplication::translate("ConnectWindow", "Nick", 0));
        label_2->setText(QApplication::translate("ConnectWindow", "Adres ip serwera", 0));
        label_3->setText(QApplication::translate("ConnectWindow", "Port", 0));
        serverAddresLineEdit->setText(QApplication::translate("ConnectWindow", "127.0.0.1", 0));
        serverPortLineEdit->setText(QApplication::translate("ConnectWindow", "1234", 0));
        backButton->setText(QApplication::translate("ConnectWindow", "Wstecz", 0));
        label_4->setText(QApplication::translate("ConnectWindow", "Nie ok", 0));
    } // retranslateUi

};

namespace Ui {
    class ConnectWindow: public Ui_ConnectWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTWINDOW_H
