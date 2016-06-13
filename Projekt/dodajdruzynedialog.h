#ifndef DODAJDRUZYNEDIALOG_H
#define DODAJDRUZYNEDIALOG_H

#include <QDialog>

namespace Ui {
class DodajDruzyneDialog;
}

class DodajDruzyneDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DodajDruzyneDialog(QWidget *parent = 0);
    ~DodajDruzyneDialog();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::DodajDruzyneDialog *ui;

};

#endif // DODAJDRUZYNEDIALOG_H
