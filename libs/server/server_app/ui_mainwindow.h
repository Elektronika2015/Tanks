/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QListView *playerListView;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_4;
    QLineEdit *ipAddressLineEdit;
    QLabel *label_2;
    QLabel *label;
    QLineEdit *portLineEdit;
    QTextBrowser *debugWindow;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QLabel *label_3;
    QLineEdit *playerNameLineEdit;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *positionLineEdit;
    QLineEdit *tankDirectionLineEdit;
    QLineEdit *activityLineEdit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(624, 495);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        playerListView = new QListView(centralWidget);
        playerListView->setObjectName(QStringLiteral("playerListView"));
        playerListView->setEnabled(true);

        gridLayout->addWidget(playerListView, 0, 0, 2, 1);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_4 = new QGridLayout(groupBox);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        ipAddressLineEdit = new QLineEdit(groupBox);
        ipAddressLineEdit->setObjectName(QStringLiteral("ipAddressLineEdit"));

        gridLayout_4->addWidget(ipAddressLineEdit, 1, 0, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_4->addWidget(label_2, 2, 0, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_4->addWidget(label, 0, 0, 1, 1);

        portLineEdit = new QLineEdit(groupBox);
        portLineEdit->setObjectName(QStringLiteral("portLineEdit"));

        gridLayout_4->addWidget(portLineEdit, 3, 0, 1, 1);


        gridLayout->addWidget(groupBox, 1, 1, 1, 1);

        debugWindow = new QTextBrowser(centralWidget);
        debugWindow->setObjectName(QStringLiteral("debugWindow"));

        gridLayout->addWidget(debugWindow, 2, 0, 1, 2);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_3->addWidget(label_3, 0, 0, 1, 1);

        playerNameLineEdit = new QLineEdit(groupBox_2);
        playerNameLineEdit->setObjectName(QStringLiteral("playerNameLineEdit"));
        playerNameLineEdit->setEnabled(false);

        gridLayout_3->addWidget(playerNameLineEdit, 0, 1, 1, 1);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_3->addWidget(label_4, 2, 0, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_3->addWidget(label_5, 3, 0, 1, 1);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_3->addWidget(label_6, 4, 0, 1, 1);

        positionLineEdit = new QLineEdit(groupBox_2);
        positionLineEdit->setObjectName(QStringLiteral("positionLineEdit"));
        positionLineEdit->setEnabled(false);

        gridLayout_3->addWidget(positionLineEdit, 2, 1, 1, 1);

        tankDirectionLineEdit = new QLineEdit(groupBox_2);
        tankDirectionLineEdit->setObjectName(QStringLiteral("tankDirectionLineEdit"));
        tankDirectionLineEdit->setEnabled(false);

        gridLayout_3->addWidget(tankDirectionLineEdit, 3, 1, 1, 1);

        activityLineEdit = new QLineEdit(groupBox_2);
        activityLineEdit->setObjectName(QStringLiteral("activityLineEdit"));
        activityLineEdit->setEnabled(false);

        gridLayout_3->addWidget(activityLineEdit, 4, 1, 1, 1);


        gridLayout->addWidget(groupBox_2, 0, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 624, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Dane serwera", 0));
        label_2->setText(QApplication::translate("MainWindow", "Port", 0));
        label->setText(QApplication::translate("MainWindow", "Adres Ip", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Dane gracza", 0));
        label_3->setText(QApplication::translate("MainWindow", "Nazwa gracza", 0));
        label_4->setText(QApplication::translate("MainWindow", "Pozycja", 0));
        label_5->setText(QApplication::translate("MainWindow", "Kierunek", 0));
        label_6->setText(QApplication::translate("MainWindow", "Activity", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
