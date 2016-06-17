#include "dodajdruzynedialog.h"
#include "ui_dodajdruzynedialog.h"

DodajDruzyneDialog::DodajDruzyneDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DodajDruzyneDialog)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(Sprawdz()));
}

DodajDruzyneDialog::~DodajDruzyneDialog()
{
    delete ui;
}

void DodajDruzyneDialog::Sprawdz()
{
    QString Nazwa;
    QList <Zawodnik> Zawodnicy;
    int Typ = 0;
    if (ui->lineEdit->text().isEmpty()){
        QMessageBox::warning(this, "UWAGA", "Wprowadz Nazwe!");
    }
    Nazwa = ui->lineEdit->text();
    if (ui->radioButton->isChecked()){
        Typ = 0x01;
    }
    if (ui->radioButton_2->isChecked()){
        Typ = 0x02;
    }
    if (ui->radioButton_3->isChecked()){
        Typ = 0x04;
    }
    QString Imie;
    QString Nazwisko;
    if (ui->lineEdit_2->text().isEmpty() && ui->lineEdit_3->text().isEmpty() && ui->lineEdit_4->text().isEmpty() && ui->lineEdit_5->text().isEmpty() && ui->lineEdit_6->text().isEmpty() &&
            ui->lineEdit_7->text().isEmpty() && ui->lineEdit_8->text().isEmpty() && ui->lineEdit_9->text().isEmpty() && ui->lineEdit_10->text().isEmpty() && ui->lineEdit_11->text().isEmpty())
    {
        QMessageBox::warning(this, "UWAGA", "Wprowadz Zawodnikow!");
    }
    else {
        Imie = ui->lineEdit_2->text();
        Nazwisko = ui->lineEdit_7->text();
        Zawodnicy.append(Zawodnik(Imie, Nazwisko, 0));
        Imie = ui->lineEdit_3->text();
        Nazwisko = ui->lineEdit_8->text();
        Zawodnicy.append(Zawodnik(Imie, Nazwisko, 1));
        Imie = ui->lineEdit_4->text();
        Nazwisko = ui->lineEdit_9->text();
        Zawodnicy.append(Zawodnik(Imie, Nazwisko, 2));
        Imie = ui->lineEdit_5->text();
        Nazwisko = ui->lineEdit_10->text();
        Zawodnicy.append(Zawodnik(Imie, Nazwisko, 3));
        Imie = ui->lineEdit_6->text();
        Nazwisko = ui->lineEdit_11->text();
        Zawodnicy.append(Zawodnik(Imie, Nazwisko, 4));
    }
    emit DodajDruzyne(Nazwa, Zawodnicy, Typ);
}

void DodajDruzyneDialog::OKButton(bool Odp)
{
    if (Odp){
        accept();
    }
    else {
        QMessageBox::warning(this, "UWAGA", "Brakuje czegos");
    }
}

void DodajDruzyneDialog::on_pushButton_2_clicked()
{
    reject();
}
