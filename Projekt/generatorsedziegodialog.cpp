#include "generatorsedziegodialog.h"
#include "ui_generatorsedziegodialog.h"

GeneratorSedziegoDialog::GeneratorSedziegoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GeneratorSedziegoDialog)
{
    ui->setupUi(this);
}

GeneratorSedziegoDialog::~GeneratorSedziegoDialog()
{
    delete ui;
}

void GeneratorSedziegoDialog::on_pushButton_2_clicked()
{
    reject();
}
