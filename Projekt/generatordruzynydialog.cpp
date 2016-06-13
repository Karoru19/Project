#include "generatordruzynydialog.h"
#include "ui_generatordruzynydialog.h"

GeneratorDruzynyDialog::GeneratorDruzynyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GeneratorDruzynyDialog)
{
    ui->setupUi(this);
}

GeneratorDruzynyDialog::~GeneratorDruzynyDialog()
{
    delete ui;
}

void GeneratorDruzynyDialog::on_pushButton_2_clicked()
{
    reject();
}

void GeneratorDruzynyDialog::on_pushButton_clicked()
{

}
