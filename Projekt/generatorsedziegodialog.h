#ifndef GENERATORSEDZIEGODIALOG_H
#define GENERATORSEDZIEGODIALOG_H

#include <QDialog>

namespace Ui {
class GeneratorSedziegoDialog;
}

class GeneratorSedziegoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GeneratorSedziegoDialog(QWidget *parent = 0);
    ~GeneratorSedziegoDialog();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::GeneratorSedziegoDialog *ui;
};

#endif // GENERATORSEDZIEGODIALOG_H