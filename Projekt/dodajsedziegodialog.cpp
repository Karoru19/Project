#include "dodajsedziegodialog.h"
#include "ui_dodajsedziegodialog.h"

DodajSedziegoDialog::DodajSedziegoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DodajSedziegoDialog)
{
    ui->setupUi(this);
}

DodajSedziegoDialog::~DodajSedziegoDialog()
{
    delete ui;
}

void DodajSedziegoDialog::on_pushButton_clicked()
{
    reject();
}
