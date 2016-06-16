#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "dodajdruzynedialog.h"
#include "dodajsedziegodialog.h"
#include "usundruzynedialog.h"
#include "usunsedziegodialog.h"
#include "generatordruzynydialog.h"
#include "generatorsedziegodialog.h"
#include "aboutusdialog.h"

#include "zawody.h"
#include "generator.h"
#include <QTime>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:    
    Zawody NoweZawody;
    Generator gen;

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void UpdateTabTeam();
    void UpdateTabRefree();
    void UpdateMatch();
    void UpdateRank();

    void AddTeam();
    void AddRefree();
    void AddMatch();

    void AddScore();

signals:
    void DruzynaDodana(bool);

public slots:
    void GeneratorDruzyny(int Liczba, int Typ);

private slots:
    void on_actionGeneruj_Druzyny_triggered();

    void on_actionGeneruj_Sedziego_triggered();

    void on_actionUsun_2_triggered();

    void on_actionDodaj_2_triggered();

    void on_actionUsun_triggered();

    void on_actionDodaj_triggered();

    void on_actionO_nas_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
