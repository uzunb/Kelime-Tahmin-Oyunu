#ifndef IMDIALOG_H
#define IMDIALOG_H

#include <QDialog>

namespace Ui {
class imDialog;
}

class imDialog : public QDialog
{
    Q_OBJECT

public:
    explicit imDialog(QWidget *parent = nullptr);
    ~imDialog();

public slots:
    int myclock();

private slots:
    void on_pushButton_2_pressed();

    void on_pushButton_6_pressed();

    void on_pushButton_5_pressed();

    void on_pushButton_4_pressed();

    void on_pushButton_7_pressed();

private:
    Ui::imDialog *ui;
    QTimer *timer;
};

#endif // IMDIALOG_H
