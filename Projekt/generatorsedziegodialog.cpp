#include "generatorsedziegodialog.h"
#include "ui_generatorsedziegodialog.h"

GeneratorSedziegoDialog::GeneratorSedziegoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GeneratorSedziegoDialog)
{
    ui->setupUi(this);
    connect(ui->spinBox, SIGNAL(valueChanged(int)),this, SLOT(WczytajLiczbe(int)));
    connect(ui->checkBox, SIGNAL(stateChanged(int)), this, SLOT(ObliczLiczbe()));
    connect(ui->checkBox_2, SIGNAL(stateChanged(int)), this, SLOT(ObliczLiczbe()));
    connect(ui->checkBox_3, SIGNAL(stateChanged(int)), this, SLOT(ObliczLiczbe()));
    connect(ui->checkBox_4, SIGNAL(stateChanged(int)), this, SLOT(ObliczLiczbe()));
    //connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(Sprawdz()));
}

GeneratorSedziegoDialog::~GeneratorSedziegoDialog()
{
    delete ui;
}

void GeneratorSedziegoDialog::on_pushButton_2_clicked()
{
    reject();
}

int GeneratorSedziegoDialog::WczytajLiczbe(int Liczba)
{
    m_Liczba = Liczba;
    ObliczLiczbe();
    return 0;
}

int GeneratorSedziegoDialog::ObliczLiczbe()
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
    if (ui->checkBox_4->isChecked()){
        ilosc += m_Liczba;
    }
    ui->label_3->setText(QString::number(ilosc));
    return 0;
}
