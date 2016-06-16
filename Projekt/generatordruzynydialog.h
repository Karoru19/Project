#ifndef GENERATORDRUZYNYDIALOG_H
#define GENERATORDRUZYNYDIALOG_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class GeneratorDruzynyDialog;
}

class GeneratorDruzynyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GeneratorDruzynyDialog(QWidget *parent = 0);
    ~GeneratorDruzynyDialog();
    int m_Liczba;
    int m_Typ;

signals:
    void GeneratorDruzyny(int Liczba, int Typ);

public slots:
    int WczytajLiczbe(int Liczba);
    int ObliczLiczbe();
    void Sprawdz();
    void OKButton (bool Odp);

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::GeneratorDruzynyDialog *ui;
};

#endif // GENERATORDRUZYNYDIALOG_H
