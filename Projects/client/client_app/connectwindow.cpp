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
}

ConnectWindow::~ConnectWindow()
{
    delete ui;
}



void ConnectWindow::on_connectButton_clicked()
{
    connectionAcceptedSlot();
    /*
    socket.connectToServer(ui->serverAddresLineEdit->text()
                         ,ui->serverPortLineEdit->text()
                         ,ui->nameLineEdit->text());
*/
}

void ConnectWindow::connectionAcceptedSlot()
{
    win= new GameWindow(this);
    ui->label_4->setText("ok");
    win->show();
    this->hide();
}

void ConnectWindow::nameAlreadyExistsSlot()
{
    QMessageBox box;
    box.setText("Istnieje juz gracz o takim nicku!");
    box.exec();
}

void ConnectWindow::serverSendMessageSlot(QString data)
{
    logger::log(data);
}

void ConnectWindow::on_nameLineEdit_editingFinished()
{

}

void ConnectWindow::on_backButton_clicked()
{

}

