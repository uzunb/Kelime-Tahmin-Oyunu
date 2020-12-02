#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "imdialog.h"
#include "midialog.h"
#include <string>
#include <iostream>

using namespace std;

namespace Ui {

class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_pressed();

    void on_pushButton_11_pressed();

private:
    Ui::MainWindow *ui;
    imDialog *im;
    miDialog *mi;

};

#endif // MAINWINDOW_H
