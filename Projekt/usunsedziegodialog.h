#ifndef USUNSEDZIEGODIALOG_H
#define USUNSEDZIEGODIALOG_H

#include <QDialog>

namespace Ui {
class UsunSedziegoDialog;
}

class UsunSedziegoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UsunSedziegoDialog(QWidget *parent = 0);
    ~UsunSedziegoDialog();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::UsunSedziegoDialog *ui;
};

#endif // USUNSEDZIEGODIALOG_H
