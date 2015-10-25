#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::back()
{
    delete win;
    ui->centralWidget->show();

}

void MainWindow::on_joinToGameButton_clicked()
{
    win = new ConnectWindow(this);
    win->show();
    ui->centralWidget->hide();
}

void MainWindow::on_exitButton_clicked()
{
    QApplication::quit();

}
