#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <connectwindow.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    friend class ConnectWindow;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_joinToGameButton_clicked();
    void on_exitButton_clicked();

    void back(); //back to main window and delete ConnectWindow

private:
    Ui::MainWindow *ui;
    ConnectWindow *win;
};

#endif // MAINWINDOW_H
