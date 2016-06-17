#ifndef DODAJSEDZIEGODIALOG_H
#define DODAJSEDZIEGODIALOG_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class DodajSedziegoDialog;
}

class DodajSedziegoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DodajSedziegoDialog(QWidget *parent = 0);
    ~DodajSedziegoDialog();

signals:
    void DodajSedziego(QString Imie, QString Nazwisko, int Typ);

public slots:
    void Sprawdz();
    void OKButton(bool Odp);

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::DodajSedziegoDialog *ui;
};

#endif // DODAJSEDZIEGODIALOG_H
