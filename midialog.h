#ifndef MIDIALOG_H
#define MIDIALOG_H

#include <QDialog>


namespace Ui {
class miDialog;
}

class miDialog : public QDialog
{
    Q_OBJECT

public:
    explicit miDialog(QWidget *parent = nullptr);
    ~miDialog();

public slots:
    int myclock();

private slots:
    void on_textEdit_3_textChanged();

    void on_pushButton_pressed();

private:
    Ui::miDialog *ui;
    QTimer *timer;
};

#endif // MIDIALOG_H
