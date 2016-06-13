#include "usunsedziegodialog.h"
#include "ui_usunsedziegodialog.h"

UsunSedziegoDialog::UsunSedziegoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UsunSedziegoDialog)
{
    ui->setupUi(this);
}

UsunSedziegoDialog::~UsunSedziegoDialog()
{
    delete ui;
}

void UsunSedziegoDialog::on_pushButton_2_clicked()
{
    reject();
}
