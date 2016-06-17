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
    void UpdateTabReferee();
    void UpdateMatch();
    void UpdateRank();

    void AddMatch();

    void AddScore();

signals:
    void DruzynaDodana(bool);
    void SedziaDodany(bool);

public slots:
    void GeneratorDruzyny(int Liczba, int Typ);
    void GeneratorSedziego(int Liczba, int Typ);
    void DodajDruzyne(QString Nazwa, QList<Zawodnik> Zawodnicy, int Typ);
    void DodajSedziego(QString Imie, QString Nazwisko, int Typ);

private slots:
    void on_actionGeneruj_Druzyny_triggered();

    void on_actionGeneruj_Sedziego_triggered();

    void on_actionUsun_2_triggered();

    void on_actionDodaj_2_triggered();

    void on_actionUsun_triggered();

    void on_actionDodaj_triggered();

    void on_actionO_nas_triggered();

    void on_actionUstaw_Spotkania_triggered();

    void on_actionRozegraj_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
