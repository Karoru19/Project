#include "dodajsedziegodialog.h"
#include "ui_dodajsedziegodialog.h"

DodajSedziegoDialog::DodajSedziegoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DodajSedziegoDialog)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(Sprawdz()));
}

DodajSedziegoDialog::~DodajSedziegoDialog()
{
    delete ui;
}

void DodajSedziegoDialog::Sprawdz()
{
    int Typ = 0;
    QString Imie, Nazwisko;
    if (ui->lineEdit_2->text().isEmpty() || ui->lineEdit_3->text().isEmpty()){
        QMessageBox::warning(this, "UWAGA", "Wprowadz Imie i Nazwisko!");
    }
    else
    {
        Imie = ui->lineEdit_2->text();
        Nazwisko = ui->lineEdit_3->text();
        if (ui->radioButton->isChecked()){
            Typ = 0x01;
        }
        if (ui->radioButton_2->isChecked()){
            Typ = 0x02;
        }
        if (ui->radioButton_3->isChecked()){
            Typ = 0x04;
        }
        if (ui->radioButton_4->isChecked()){
            Typ = 0x08;
        }
    }
    emit DodajSedziego(Imie, Nazwisko, Typ);
}

void DodajSedziegoDialog::OKButton(bool Odp)
{
    if (Odp){
        accept();
    }
    else {
        QMessageBox::warning(this, "UWAGA", "Brakuje czegos");
    }
}

void DodajSedziegoDialog::on_pushButton_2_clicked()
{
    reject();
}
