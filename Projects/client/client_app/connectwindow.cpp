#include "connectwindow.h"
#include "ui_connectwindow.h"

ConnectWindow::ConnectWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConnectWindow),
    mainWindowPointer(parent)
{
    ui->setupUi(this);

    connect(ui->backButton,SIGNAL(clicked()),mainWindowPointer,SLOT(back()));
    connect(&socket,SIGNAL(connectionAccepted()),this,SLOT(connectionAcceptedSlot()));
    connect(&socket,SIGNAL(nameAlreadyExists()),this,SLOT(nameAlreadyExistsSlot()));
    connect(&socket,SIGNAL(serverSendMessage(QString)),this,SLOT(serverSendMessageSlot(QString)));
    firstConnection = true;
}

ConnectWindow::~ConnectWindow()
{
    delete ui;
}



void ConnectWindow::on_connectButton_clicked()
{


    socket.connectToServer(ui->serverAddresLineEdit->text()
                         ,ui->serverPortLineEdit->text()
                         ,ui->nameLineEdit->text());
    if(firstConnection)
    {
        socket.connectToServer(this->ui->serverAddresLineEdit->text()
                               ,this->ui->serverPortLineEdit->text()
                               ,this->ui->nameLineEdit->text());
        firstConnection = false;
    }
    else
        socket.writeToServer(this->ui->nameLineEdit->text());


}

void ConnectWindow::connectionAcceptedSlot()
{
    mainWindowPointer->close();
    win= new GameWindow(this);
    win->setSocketPointer(&socket);
    win->setTankName(socket.getPlayerName());
    ui->label_4->setText("ok");
    win->show();


    firstConnection = false;
    disconnect(&socket,SIGNAL(serverSendMessage(QString)),this,SLOT(serverSendMessageSlot(QString)));
}

void ConnectWindow::nameAlreadyExistsSlot()
{
    QMessageBox box;
    box.setText("Istnieje juz gracz o takim nicku!");
    box.exec();
    firstConnection = false;
}

void ConnectWindow::serverSendMessageSlot(QString data)
{
    logger l;
    l.log(data);
}


void ConnectWindow::on_nameLineEdit_editingFinished()
{
}

void ConnectWindow::on_backButton_clicked()
{

}

