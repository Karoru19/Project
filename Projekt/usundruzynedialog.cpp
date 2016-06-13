#include "usundruzynedialog.h"
#include "ui_usundruzynedialog.h"

UsunDruzyneDialog::UsunDruzyneDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UsunDruzyneDialog)
{
    ui->setupUi(this);
}

UsunDruzyneDialog::~UsunDruzyneDialog()
{
    delete ui;
}

void UsunDruzyneDialog::on_pushButton_2_clicked()
{
    reject();
}
