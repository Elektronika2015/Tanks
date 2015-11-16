#ifndef CONNECTWINDOW_H
#define CONNECTWINDOW_H

#include <QWidget>
#include "gamewindow.h"
#include "client_socket.h"
#include <QMessageBox>

namespace Ui {
class ConnectWindow;

}

class ConnectWindow  : public QWidget
{
    Q_OBJECT

public:
    explicit ConnectWindow(QWidget *parent = 0);
    ~ConnectWindow();


private slots:
    void on_backButton_clicked();
    void on_connectButton_clicked();

    void connectionAcceptedSlot();
    void nameAlreadyExistsSlot();
    void serverSendMessageSlot(QString data);

    void on_nameLineEdit_editingFinished();


private:
    Ui::ConnectWindow *ui;
    QWidget *mainWindowPointer;
    GameWindow *win;
    client_socket socket;


};

#endif // CONNECTWINDOW_H
