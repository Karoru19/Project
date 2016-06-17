#ifndef GENERATORSEDZIEGODIALOG_H
#define GENERATORSEDZIEGODIALOG_H

#include <QDialog>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class GeneratorSedziegoDialog;
}

class GeneratorSedziegoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GeneratorSedziegoDialog(QWidget *parent = 0);
    ~GeneratorSedziegoDialog();
    int m_Liczba = 0;
    int m_Typ = 0;

signals:
    void GeneratorSedziego(int Liczba, int Typ);

public slots:
    int ObliczLiczbe();
    int WczytajLiczbe(int Liczba);
    void Sprawdz();
    void OKButton(bool Odp);

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::GeneratorSedziegoDialog *ui;
};

#endif // GENERATORSEDZIEGODIALOG_H
