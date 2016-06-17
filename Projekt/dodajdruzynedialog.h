#ifndef DODAJDRUZYNEDIALOG_H
#define DODAJDRUZYNEDIALOG_H

#include <QDialog>
#include <QString>
#include "zawodnik.h"
#include <QMessageBox>

namespace Ui {
class DodajDruzyneDialog;
}

class DodajDruzyneDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DodajDruzyneDialog(QWidget *parent = 0);
    ~DodajDruzyneDialog();

public slots:
    void Sprawdz();
    void OKButton(bool Odp);

signals:
    void DodajDruzyne(QString Nazwa, QList <Zawodnik> Zawodnicy, int Typ);

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::DodajDruzyneDialog *ui;

};

#endif // DODAJDRUZYNEDIALOG_H
