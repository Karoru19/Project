#ifndef DODAJSEDZIEGODIALOG_H
#define DODAJSEDZIEGODIALOG_H

#include <QDialog>

namespace Ui {
class DodajSedziegoDialog;
}

class DodajSedziegoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DodajSedziegoDialog(QWidget *parent = 0);
    ~DodajSedziegoDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::DodajSedziegoDialog *ui;
};

#endif // DODAJSEDZIEGODIALOG_H
