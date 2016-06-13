#ifndef USUNDRUZYNEDIALOG_H
#define USUNDRUZYNEDIALOG_H

#include <QDialog>

namespace Ui {
class UsunDruzyneDialog;
}

class UsunDruzyneDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UsunDruzyneDialog(QWidget *parent = 0);
    ~UsunDruzyneDialog();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::UsunDruzyneDialog *ui;
};

#endif // USUNDRUZYNEDIALOG_H
