#include "generatordruzynydialog.h"
#include "ui_generatordruzynydialog.h"
#include "QDebug"

GeneratorDruzynyDialog::GeneratorDruzynyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GeneratorDruzynyDialog)
{
    ui->setupUi(this);
    qDebug() << m_Liczba;
    //connect(ui->spinBox, SIGNAL, m_Liczba, SLOT(WczytajLiczbe()));
    //connect(m_Liczba,SIGNAL,ui->label_3 , SLOT(setText(QString::number(ObliczLiczbe))));
}

GeneratorDruzynyDialog::~GeneratorDruzynyDialog()
{
    delete ui;
}

int GeneratorDruzynyDialog::WczytajLiczbe()
{
    return ui->spinBox->value();
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
    return ilosc;
}

void GeneratorDruzynyDialog::on_pushButton_2_clicked()
{
    reject();
}

void GeneratorDruzynyDialog::on_pushButton_clicked()
{

}
