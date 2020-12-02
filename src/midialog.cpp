#include "programlama.h"
#include "midialog.h"
#include "ui_midialog.h"
#include <QApplication>
#include <QFile>
#include <QDebug>
#include <QTimer>

programlama ptr_mi;
WordNode secretWord;
int counter1 = 0;

miDialog::miDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::miDialog)
{
    ui->setupUi(this);
    ptr_mi.File2Struct();
    ptr_mi.list.printH2T();
    secretWord = ptr_mi.GetRandomWord();
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT(myclock()));
    timer->start(1000);

}

miDialog::~miDialog()
{
    delete ui;
}
int miDialog::myclock()
{
   counter1++;
   ui->lcdNumber_3->display(counter1);
}
void miDialog::on_textEdit_3_textChanged()
{


}

void miDialog::on_pushButton_pressed()
{
    WordNode inputWord;

    inputWord.word =ui->lineEdit->text().toStdString();
     QString inputWord1 = QString :: fromStdString(inputWord.word);
     qDebug() << inputWord1;
     qDebug() << QString::fromStdString(secretWord.word);

        if (inputWord.word == secretWord.word)
        {
            ui->textEdit_3->setText("DOĞRU TAHMİN");
            ptr_mi.CalculateBlackScore(&inputWord, secretWord);
            ptr_mi. CalculateWhiteScore(&inputWord, secretWord);
            ui->textEdit->setText(QString::number(inputWord.score[0]));
            ui->textEdit_2->setText(QString::number(inputWord.score[1]));
            return;
        }
        else if(inputWord.word == "-1")
        {

            ui->textEdit_3->setText("OYUN BİTTİ");
            this->close();
            return;
        }
        else
        {
            ui->textEdit_3->setText("yanlis tahmin");
            ui->lcdNumber->display(QString::number(ptr_mi.list.lenList()));
            inputWord.score[0] = inputWord.score[1] = 0;
            ptr_mi.CalculateBlackScore(&inputWord, secretWord);
            ptr_mi. CalculateWhiteScore(&inputWord, secretWord);
            ui->textEdit->setText(QString::number(inputWord.score[0]));
            ui->textEdit_2->setText(QString::number(inputWord.score[1]));
        }

}
