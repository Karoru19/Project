#include "generatordruzynydialog.h"
#include "ui_generatordruzynydialog.h"
#include "QDebug"

GeneratorDruzynyDialog::GeneratorDruzynyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GeneratorDruzynyDialog)
{
    ui->setupUi(this);
    connect(ui->spinBox, SIGNAL(valueChanged(int)),this, SLOT(WczytajLiczbe(int)));
    connect(ui->checkBox, SIGNAL(stateChanged(int)), this, SLOT(ObliczLiczbe()));
    connect(ui->checkBox_2, SIGNAL(stateChanged(int)), this, SLOT(ObliczLiczbe()));
    connect(ui->checkBox_3, SIGNAL(stateChanged(int)), this, SLOT(ObliczLiczbe()));
    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(Sprawdz()));
}

GeneratorDruzynyDialog::~GeneratorDruzynyDialog()
{
    delete ui;
}

int GeneratorDruzynyDialog::WczytajLiczbe(int Liczba)
{
    m_Liczba = Liczba;
    ObliczLiczbe();
    return 0;
}

int GeneratorDruzynyDialog::ObliczLiczbe()
{
    int ilosc = 0;
    if (ui->checkBox->isChecked()){
        ilosc += m_Liczba;
    }
    if (ui->checkBox_2->isChecked()){
        ilosc += m_Liczba;
    }
    if (ui->checkBox_3->isChecked()){
        ilosc += m_Liczba;
    }
    ui->label_3->setText(QString::number(ilosc));
    return 0;
}

void GeneratorDruzynyDialog::Sprawdz()
{
    if (ui->checkBox->isChecked()){
        m_Typ += 4;
    }
    if (ui->checkBox_2->isChecked()){
        m_Typ += 2;
    }
    if (ui->checkBox_3->isChecked()){
        m_Typ += 1;
    }
    emit GeneratorDruzyny(ui->spinBox->value(), m_Typ);
}

void GeneratorDruzynyDialog::on_pushButton_2_clicked()
{
    reject();
}

void GeneratorDruzynyDialog::OKButton(bool Odp)
{
    if (Odp){
        accept();
    }
    else QMessageBox::warning(this, "UWAGA!", "Wybierz dyscypliny lub liczbe druzyny!");
}
