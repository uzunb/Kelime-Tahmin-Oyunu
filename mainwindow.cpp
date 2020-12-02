#include "mainwindow.h"
#include "programlama.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QDebug>
#include <QIntValidator>
#include <iostream>
#include <QApplication>

programlama prog;

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

void MainWindow::on_pushButton_pressed()
{
    hide();
    this->close();
    imDialog win;
    win.setModal(true);
    win.exec();

}

void MainWindow::on_pushButton_11_pressed()
{
    this->close();
    miDialog win;
    win.setModal(true);
    win.exec();
}
