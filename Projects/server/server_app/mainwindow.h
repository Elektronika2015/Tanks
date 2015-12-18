#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tcpserver.h"
#include <QHostAddress>
#include <QNetworkInterface>
#include <QStringListModel>
#include "common_codes.h"
#include "logger.h"
namespace Ui {
class MainWindow;
}



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    static Ui::MainWindow ui;
    static QList<standardTankInfo> players;
    static QStringList playersNamesList;
    static QStringListModel listModel;
    static logger servLogger;
    static TCPserver serv;
    static int index;


    static void callback(QString msg);
    static void updatePlayerInformation(standardTankInfo info);
    static void clearPlayerInformation();




private slots:
    static void playerConnectedSlot(standardTankInfo info);
    static void playerMovedSlot(standardTankInfo info);
    static void playerDisconnectedSlot(QString name);

    void on_playerListView_clicked(const QModelIndex &index);
};

#endif // MAINWINDOW_H
