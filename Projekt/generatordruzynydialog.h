#ifndef GENERATORDRUZYNYDIALOG_H
#define GENERATORDRUZYNYDIALOG_H

#include <QDialog>

namespace Ui {
class GeneratorDruzynyDialog;
}

class GeneratorDruzynyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GeneratorDruzynyDialog(QWidget *parent = 0);
    ~GeneratorDruzynyDialog();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::GeneratorDruzynyDialog *ui;
};

#endif // GENERATORDRUZYNYDIALOG_H
