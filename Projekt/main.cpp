#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    for (int i = 0; i < 32; i++){
        w.AddTeam();
        w.AddRefree();
    }
    int SP = w.NoweZawody.Druzyny.DruzynySiatkowkaPlazowa.size();
    int DO = w.NoweZawody.Druzyny.DruzynyDwaOgnie.size();
    int PL = w.NoweZawody.Druzyny.DruzynyPrzeciaganieLiny.size();
    int k = SP * (SP - 1) / 2 + DO * (DO - 1) / 2 + PL * (PL - 1) / 2;
    for (int i = 0; i < k; i ++){
        w.AddMatch();
    }
    w.AddScore();
    w.UpdateTabTeam();
    w.UpdateTabRefree();
    w.UpdateMatch();
    for (int i = 0; i < 32; i++){
        w.UpdateRank();
    }

    return a.exec();
}
