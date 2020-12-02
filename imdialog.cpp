#include "imdialog.h"
#include "ui_imdialog.h"
#include "mainwindow.h"
#include "programlama.h"
#include <QTimer>

programlama ptr_im;
WordNode RandomWord;
int counter = 0,isNormal, counter2=0;


imDialog::imDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::imDialog)
{
    ui->setupUi(this);
    ptr_im.File2Struct();
    RandomWord = ptr_im.GetRandomWord();
    ui->lineEdit->setText(QString::fromStdString(RandomWord.word));
    ui->lcdNumber->display(ptr_im.list.lenList());
    ui->plainTextEdit->setPlainText(QString::fromStdString(ptr_im.elenenler(0)));
    ui->pushButton_2->hide();
    ui->label_11->hide();
    ui->lineEdit_4->hide();
    ui->pushButton_7->hide();
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT(myclock()));
    timer->start(1000);
}

imDialog::~imDialog()
{
    delete ui;
}

int imDialog::myclock()
{
   counter2++;
   ui->lcdNumber_3->display(counter2);
}

void imDialog::on_pushButton_2_pressed()
{

    ui->lcdNumber_2->display(++counter);
    RandomWord.score[0] = ui->lineEdit_2->text().toInt();
    RandomWord.score[1] = ui->lineEdit_3->text().toInt();
    ptr_im.EliminateWords(RandomWord,isNormal);
    RandomWord = ptr_im.GetRandomWord();
    if(RandomWord.word =="-1"){
        ui->label_11->show();
        ui->lineEdit_4->show();
        ui->pushButton_7->show();

    }
    ui->lcdNumber->display(ptr_im.list.lenList());
    ui->lineEdit->setText(QString::fromStdString(RandomWord.word));
    ui->plainTextEdit->setPlainText(QString::fromStdString(ptr_im.elenenler(0)));


}

void imDialog::on_pushButton_6_pressed()
{
    this->close();
}

void imDialog::on_pushButton_5_pressed()
{
    ui->pushButton_2->show();
    isNormal = 0;
    ui->pushButton_4->hide();
    ui->pushButton_5->hide();
}

void imDialog::on_pushButton_4_pressed()
{
    ui->pushButton_2->show();
    isNormal = 1;
    ui->pushButton_4->hide();
    ui->pushButton_5->hide();
}

void imDialog::on_pushButton_7_pressed()
{
    string a = ui->lineEdit_4->text().toStdString();
    ptr_im.AddWord2Dictionary(a);
}
