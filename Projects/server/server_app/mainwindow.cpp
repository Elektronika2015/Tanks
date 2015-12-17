#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qapplication.h"

Ui::MainWindow MainWindow::ui;
TCPserver MainWindow::serv;
int MainWindow::index = 0;
QStringListModel MainWindow::listModel;
QStringList MainWindow::playersNamesList;
QList<standardTankInfo> MainWindow::players;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
    //ui(new Ui::MainWindow)
{
    ui.setupUi(this);
    logger::setCallbackFunc(callback);
    serv.startServer();
    connect(&serv,SIGNAL(playerConnectedSignal(standardTankInfo)),
            this,SLOT(playerConnectedSlot(standardTankInfo)));//, Qt::QueuedConnection);
    connect(&serv,SIGNAL(playerMovedSignal(standardTankInfo)),
            this,SLOT(playerMovedSlot(standardTankInfo)));//, Qt::QueuedConnection);
    connect(&serv,SIGNAL(playerDisconnectedSignal(QString)),
            this,SLOT(playerDisconnectedSlot(QString)), Qt::QueuedConnection);
    listModel.setStringList(playersNamesList);
    ui.playerListView->setModel(&listModel);

    QString port = serv.getServerPort();
    ui.portLineEdit->setText(port);
    foreach (const QHostAddress &address, QNetworkInterface::allAddresses()) {
        if (address.protocol() == QAbstractSocket::IPv4Protocol && address != QHostAddress(QHostAddress::LocalHost))
             ui.ipAddressLineEdit->setText( address.toString());
    }
}


MainWindow::~MainWindow()
{

}

void MainWindow::callback(QString msg)
{
    //QMutex mutex;
    //mutex.lock();
    //ui.debugWindow->setText(msg);
    msg.insert(0,QString::number(++index)+". ");
    ui.debugWindow->append(msg);
    //mutex.unlock();
}

void MainWindow::playerConnectedSlot(standardTankInfo info)
{
    playersNamesList.append(info.name);

    players.append(info);

    listModel.setStringList(playersNamesList);
    ui.playerListView->setModel(&listModel);
}

void MainWindow::playerMovedSlot(standardTankInfo info)
{
    for(int i = 0; i < players.count();i++)
        if(players.value(i).name == info.name)
        {
            players[i].position = info.position;
            players[i].tankDirection = info.tankDirection;
            return;
        }
    logger::log("could not find given player in list: "+info.name);
}

void MainWindow::playerDisconnectedSlot(QString name)
{
    playersNamesList.removeAll(name);
    for(int i = 0; i < players.count();i++)
        if(players.value(i).name == name)
            players.removeAt(i);

    listModel.setStringList(playersNamesList);
    ui.playerListView->setModel(&listModel);
}

void MainWindow::on_playerListView_clicked(const QModelIndex &index)
{
    //ui.playerListView->indexWidget(index)->;
}
