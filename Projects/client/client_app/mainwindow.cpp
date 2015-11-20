#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    win = new ConnectWindow(this);
    win->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::back()
{
    //delete win;
    win->hide();
    ui->centralWidget->show();

}

void MainWindow::on_joinToGameButton_clicked()
{

    win->show();
    ui->centralWidget->hide();
}

void MainWindow::on_exitButton_clicked()
{
    QApplication::quit();

}
