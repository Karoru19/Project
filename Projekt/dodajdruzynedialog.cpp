#include "dodajdruzynedialog.h"
#include "ui_dodajdruzynedialog.h"

DodajDruzyneDialog::DodajDruzyneDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DodajDruzyneDialog)
{
    ui->setupUi(this);
}

DodajDruzyneDialog::~DodajDruzyneDialog()
{
    delete ui;
}

void DodajDruzyneDialog::on_pushButton_2_clicked()
{
    reject();
}
