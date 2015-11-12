#ifndef CONNECTWINDOW_H
#define CONNECTWINDOW_H

#include <QWidget>
#include <gamewindow.h>

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

private:
    Ui::ConnectWindow *ui;
    QWidget *mainWindowPointer;
    GameWindow *win;

};

#endif // CONNECTWINDOW_H
