#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    qsrand(QTime::currentTime().msecsSinceStartOfDay());
    ui->setupUi(this);
    gen = Generator();
    connect(ui->TableRank->horizontalHeader(), SIGNAL(sortIndicatorChanged(int,Qt::SortOrder)), ui->TableRank, SLOT(sortByColumn(int)));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_actionGeneruj_Druzyny_triggered()
{
    GeneratorDruzynyDialog dialog;
    dialog.exec();
}

void MainWindow::on_actionGeneruj_Sedziego_triggered()
{
    GeneratorSedziegoDialog dialog;
    dialog.exec();
}

void MainWindow::on_actionUsun_2_triggered()
{
    UsunSedziegoDialog dialog;
    dialog.exec();

}

void MainWindow::on_actionDodaj_2_triggered()
{
    DodajSedziegoDialog dialog;
    dialog.exec();
}

void MainWindow::on_actionUsun_triggered()
{
    UsunDruzyneDialog dialog;
    dialog.exec();
}

void MainWindow::on_actionDodaj_triggered()
{
    DodajDruzyneDialog dialog;
    dialog.exec();
}

void MainWindow::on_actionO_nas_triggered()
{
    AboutUsDialog dialog;
    dialog.exec();
}

void MainWindow::UpdateTabTeam()
{
    QList <QString> DSP;
    QList <QString> DDO;
    QList <QString> DPL;

    QString Nazwa;

    DSP = NoweZawody.Druzyny.DruzynySiatkowkaPlazowa.keys();
    DDO = NoweZawody.Druzyny.DruzynyDwaOgnie.keys();
    DPL = NoweZawody.Druzyny.DruzynyPrzeciaganieLiny.keys();

    int A, B;
    A = NoweZawody.Druzyny.DruzynySiatkowkaPlazowa.size();
    B = NoweZawody.Druzyny.DruzynyDwaOgnie.size() + A;

    for (int i = 0; i < ui->TableTeam->rowCount(); i++){
        if (i < A){
            ui->TableTeam->setItem(i,0,new QTableWidgetItem(NoweZawody.Druzyny.DruzynySiatkowkaPlazowa.value(DSP.at(i)).Nazwa()));
            ui->TableTeam->setItem(i, 1,new QTableWidgetItem("Siatkowka Plazowa"));
            for (int j = 0; j < 5; j++){
                Nazwa = NoweZawody.Druzyny.DruzynySiatkowkaPlazowa.value(DSP.at(i)).m_Zawodnicy.at(j).Imie() + " " + NoweZawody.Druzyny.DruzynySiatkowkaPlazowa.value(DSP.at(i)).m_Zawodnicy.at(j).Nazwisko();
                ui->TableTeam->setItem(i,j+2,new QTableWidgetItem(Nazwa));
            }
        }
        else if (i >=A && i < B){
            ui->TableTeam->setItem(i,0,new QTableWidgetItem(NoweZawody.Druzyny.DruzynyDwaOgnie.value(DDO.at(i - A)).Nazwa()));
            ui->TableTeam->setItem(i, 1,new QTableWidgetItem("Dwa Ognie"));
            for (int j = 0; j < 5; j++){
                Nazwa = NoweZawody.Druzyny.DruzynyDwaOgnie.value(DDO.at(i - A)).m_Zawodnicy.at(j).Imie() + " " + NoweZawody.Druzyny.DruzynyDwaOgnie.value(DDO.at(i - A)).m_Zawodnicy.at(j).Nazwisko();
                ui->TableTeam->setItem(i,j+2,new QTableWidgetItem(Nazwa));
            }
        }
        else {
            ui->TableTeam->setItem(i,0,new QTableWidgetItem(NoweZawody.Druzyny.DruzynyPrzeciaganieLiny.value(DPL.at(i - B)).Nazwa()));
            ui->TableTeam->setItem(i, 1,new QTableWidgetItem("Przeciaganie Liny"));
            for (int j = 0; j < 5; j++){
                Nazwa = NoweZawody.Druzyny.DruzynyPrzeciaganieLiny.value(DPL.at(i - B)).m_Zawodnicy.at(j).Imie() + " " + NoweZawody.Druzyny.DruzynyPrzeciaganieLiny.value(DPL.at(i - B)).m_Zawodnicy.at(j).Nazwisko();
                ui->TableTeam->setItem(i,j+2,new QTableWidgetItem(Nazwa));
            }
        }
    }
}

void MainWindow::UpdateTabRefree()
{
    QList <QString> SGSP;
    QList <QString> SPSP;
    QList <QString> SGDO;
    QList <QString> SGPL;

    QString Nazwa;

    SGSP = NoweZawody.Sedziowie.SedziowieGlowniSiatkowkaPlazowa.keys();
    SPSP = NoweZawody.Sedziowie.SedziowiePomocniczySiatkowkaPlazowa.keys();
    SGDO = NoweZawody.Sedziowie.SedziowieDwaOgnie.keys();
    SGPL = NoweZawody.Sedziowie.SedziowiePrzeciaganieLiny.keys();

    int A, B, C;
    A = NoweZawody.Sedziowie.SedziowieGlowniSiatkowkaPlazowa.size();
    B = NoweZawody.Sedziowie.SedziowiePomocniczySiatkowkaPlazowa.size() + A;
    C = NoweZawody.Sedziowie.SedziowieDwaOgnie.size() + B;

   for (int i = 0; i < ui->TableRefree->rowCount(); i++){
        if (i < A){
            ui->TableRefree->setItem(i,0,new QTableWidgetItem(NoweZawody.Sedziowie.SedziowieGlowniSiatkowkaPlazowa.value(SGSP.at(i)).m_Imie));
            ui->TableRefree->setItem(i,1,new QTableWidgetItem(NoweZawody.Sedziowie.SedziowieGlowniSiatkowkaPlazowa.value(SGSP.at(i)).m_Nazwisko));
            ui->TableRefree->setItem(i,2,new QTableWidgetItem("Sedzia Glowny"));
            ui->TableRefree->setItem(i,3,new QTableWidgetItem("Siatkowka Plazowa"));
        }
        else if (i >=A && i < B){
            ui->TableRefree->setItem(i,0,new QTableWidgetItem(NoweZawody.Sedziowie.SedziowiePomocniczySiatkowkaPlazowa.value(SPSP.at(i-A)).m_Imie));
            ui->TableRefree->setItem(i,1,new QTableWidgetItem(NoweZawody.Sedziowie.SedziowiePomocniczySiatkowkaPlazowa.value(SPSP.at(i-A)).m_Nazwisko));
            ui->TableRefree->setItem(i,2,new QTableWidgetItem("Sedzia Pomocniczy"));
            ui->TableRefree->setItem(i,3,new QTableWidgetItem("Siatkowka Plazowa"));
        }
        else if (i >=B && i < C){
            ui->TableRefree->setItem(i,0,new QTableWidgetItem(NoweZawody.Sedziowie.SedziowieDwaOgnie.value(SGDO.at(i-B)).m_Imie));
            ui->TableRefree->setItem(i,1,new QTableWidgetItem(NoweZawody.Sedziowie.SedziowieDwaOgnie.value(SGDO.at(i-B)).m_Nazwisko));
            ui->TableRefree->setItem(i,2,new QTableWidgetItem("Sedzia"));
            ui->TableRefree->setItem(i,3,new QTableWidgetItem("Dwa Ognie"));
        }
        else {
            ui->TableRefree->setItem(i,0,new QTableWidgetItem(NoweZawody.Sedziowie.SedziowiePrzeciaganieLiny.value(SGPL.at(i-C)).m_Imie));
            ui->TableRefree->setItem(i,1,new QTableWidgetItem(NoweZawody.Sedziowie.SedziowiePrzeciaganieLiny.value(SGPL.at(i-C)).m_Nazwisko));
            ui->TableRefree->setItem(i,2,new QTableWidgetItem("Sedzia"));
            ui->TableRefree->setItem(i,3,new QTableWidgetItem("Przeciaganie Liny"));
        }
   }
}

void MainWindow::UpdateMatch()
{
    QList <QString> SSP;
    QList <QString> SDO;
    QList <QString> SPL;

    QString Wynik;
    QString NazwaSedziego;
    QString NazwaSedziegoPom1;
    QString NazwaSedziegoPom2;

    SSP = NoweZawody.Spotkania.MeczeSiatkowekPlazowych.keys();
    SDO = NoweZawody.Spotkania.MeczeDwochOgni.keys();
    SPL = NoweZawody.Spotkania.MeczePrzeciaganieLiny.keys();

    int A, B;
    A = NoweZawody.Spotkania.MeczeSiatkowekPlazowych.size();
    B = NoweZawody.Spotkania.MeczeDwochOgni.size() + A;
    for (int i = 0; i < ui->TableMatch->rowCount(); i++){
        if (i < A){
            Wynik = QString::number(NoweZawody.Spotkania.MeczeSiatkowekPlazowych.value(SSP.at(i)).m_PunktyGospodarza) + " - " + QString::number(NoweZawody.Spotkania.MeczeSiatkowekPlazowych.value(SSP.at(i)).m_PunktyGoscia);
            NazwaSedziego = NoweZawody.Spotkania.MeczeSiatkowekPlazowych.value(SSP.at(i)).m_Sedzia.m_Imie + " " + NoweZawody.Spotkania.MeczeSiatkowekPlazowych.value(SSP.at(i)).m_Sedzia.m_Nazwisko;
            NazwaSedziegoPom1 = NoweZawody.Spotkania.MeczeSiatkowekPlazowych.value(SSP.at(i)).m_SedziaPomocniczy1.m_Imie + " " + NoweZawody.Spotkania.MeczeSiatkowekPlazowych.value(SSP.at(i)).m_SedziaPomocniczy1.m_Nazwisko;
            NazwaSedziegoPom2 = NoweZawody.Spotkania.MeczeSiatkowekPlazowych.value(SSP.at(i)).m_SedziaPomocniczy2.m_Imie + " " + NoweZawody.Spotkania.MeczeSiatkowekPlazowych.value(SSP.at(i)).m_SedziaPomocniczy2.m_Nazwisko;
            ui->TableMatch->setItem(i,0,new QTableWidgetItem(NoweZawody.Spotkania.MeczeSiatkowekPlazowych.value(SSP.at(i)).m_Gospodarz.m_Nazwa));
            ui->TableMatch->setItem(i,1,new QTableWidgetItem(NoweZawody.Spotkania.MeczeSiatkowekPlazowych.value(SSP.at(i)).m_Gosc.m_Nazwa));
            ui->TableMatch->setItem(i,2,new QTableWidgetItem(Wynik));
            ui->TableMatch->setItem(i,3,new QTableWidgetItem("Siatkowka Plazowa"));
            ui->TableMatch->setItem(i,4,new QTableWidgetItem(NazwaSedziego));
            ui->TableMatch->setItem(i,5,new QTableWidgetItem(NazwaSedziegoPom1));
            ui->TableMatch->setItem(i,6,new QTableWidgetItem(NazwaSedziegoPom2));
        }
        else if (i >= A && i < B){
            Wynik = QString::number(NoweZawody.Spotkania.MeczeDwochOgni.value(SDO.at(i - A)).m_PunktyGospodarza) + " - " + QString::number(NoweZawody.Spotkania.MeczeDwochOgni.value(SDO.at(i - A)).m_PunktyGoscia);
            NazwaSedziego = NoweZawody.Spotkania.MeczeDwochOgni.value(SDO.at(i - A)).m_Sedzia.m_Imie + " " + NoweZawody.Spotkania.MeczeDwochOgni.value(SDO.at(i - A)).m_Sedzia.m_Nazwisko;
            ui->TableMatch->setItem(i,0,new QTableWidgetItem(NoweZawody.Spotkania.MeczeDwochOgni.value(SDO.at(i - A)).m_Gospodarz.m_Nazwa));
            ui->TableMatch->setItem(i,1,new QTableWidgetItem(NoweZawody.Spotkania.MeczeDwochOgni.value(SDO.at(i - A)).m_Gosc.m_Nazwa));
            ui->TableMatch->setItem(i,2,new QTableWidgetItem(Wynik));
            ui->TableMatch->setItem(i,3,new QTableWidgetItem("Dwa Ognie"));
            ui->TableMatch->setItem(i,4,new QTableWidgetItem(NazwaSedziego));
            ui->TableMatch->setItem(i,5,new QTableWidgetItem("Brak"));
            ui->TableMatch->setItem(i,6,new QTableWidgetItem("Brak"));
        }
        else {
            Wynik = QString::number(NoweZawody.Spotkania.MeczePrzeciaganieLiny.value(SPL.at(i - B)).m_PunktyGospodarza) + " - " + QString::number(NoweZawody.Spotkania.MeczePrzeciaganieLiny.value(SPL.at(i - B)).m_PunktyGoscia);
            NazwaSedziego = NoweZawody.Spotkania.MeczePrzeciaganieLiny.value(SPL.at(i - B)).m_Sedzia.m_Imie + " " + NoweZawody.Spotkania.MeczePrzeciaganieLiny.value(SPL.at(i - B)).m_Sedzia.m_Nazwisko;
            ui->TableMatch->setItem(i,0,new QTableWidgetItem(NoweZawody.Spotkania.MeczePrzeciaganieLiny.value(SPL.at(i - B)).m_Gospodarz.m_Nazwa));
            ui->TableMatch->setItem(i,1,new QTableWidgetItem(NoweZawody.Spotkania.MeczePrzeciaganieLiny.value(SPL.at(i - B)).m_Gosc.m_Nazwa));
            ui->TableMatch->setItem(i,2,new QTableWidgetItem(Wynik));
            ui->TableMatch->setItem(i,3,new QTableWidgetItem("Przeciaganie Liny"));
            ui->TableMatch->setItem(i,4,new QTableWidgetItem(NazwaSedziego));
            ui->TableMatch->setItem(i,5,new QTableWidgetItem("Brak"));
            ui->TableMatch->setItem(i,6,new QTableWidgetItem("Brak"));
        }
    }
}

void MainWindow::UpdateRank()
{
    QList <QString> DSP;
    QList <QString> DDO;
    QList <QString> DPL;

    QList <QString> MSP;
    QList <QString> MDO;
    QList <QString> MPL;

    QString Nazwa;
    QString Wynik;

    int pktza, pktprzeciw;

    DSP = NoweZawody.Druzyny.DruzynySiatkowkaPlazowa.keys();
    DDO = NoweZawody.Druzyny.DruzynyDwaOgnie.keys();
    DPL = NoweZawody.Druzyny.DruzynyPrzeciaganieLiny.keys();

    MSP = NoweZawody.Spotkania.MeczeSiatkowekPlazowych.keys();
    MDO = NoweZawody.Spotkania.MeczeDwochOgni.keys();
    MPL = NoweZawody.Spotkania.MeczePrzeciaganieLiny.keys();

    int A, B;
    A = NoweZawody.Druzyny.DruzynySiatkowkaPlazowa.size();
    B = NoweZawody.Druzyny.DruzynyDwaOgnie.size() + A;

    for (int i = 0; i < ui->TableRank->rowCount(); i++){
        if (i < A){
            pktza = 0;
            pktprzeciw = 0;
            Nazwa = NoweZawody.Druzyny.DruzynySiatkowkaPlazowa.value(DSP.at(i)).Nazwa();
            ui->TableRank->setItem(i,0,new QTableWidgetItem(Nazwa));
            ui->TableRank->setItem(i, 1,new QTableWidgetItem("Siatkowka Plazowa"));
            for (int j = 0; j < MSP.size(); j++){
                if (NoweZawody.Spotkania.MeczeSiatkowekPlazowych.value(MSP.at(j)).m_Gospodarz.m_Nazwa == Nazwa) {
                    pktza += NoweZawody.Spotkania.MeczeSiatkowekPlazowych.value(MSP.at(j)).m_PunktyGospodarza;
                    pktprzeciw += NoweZawody.Spotkania.MeczeSiatkowekPlazowych.value(MSP.at(j)).m_PunktyGoscia;
                }
                else if (NoweZawody.Spotkania.MeczeSiatkowekPlazowych.value(MSP.at(j)).m_Gosc.m_Nazwa == Nazwa) {
                    pktza += NoweZawody.Spotkania.MeczeSiatkowekPlazowych.value(MSP.at(j)).m_PunktyGoscia;
                    pktprzeciw += NoweZawody.Spotkania.MeczeSiatkowekPlazowych.value(MSP.at(j)).m_PunktyGospodarza;
                }
            }
            Wynik = QString::number(pktza) + " - " + QString::number(pktprzeciw);
            ui->TableRank->setItem(i,2,new QTableWidgetItem(Wynik));
            ui->TableRank->setItem(i,3,new QTableWidgetItem(QString::number(NoweZawody.Druzyny.DruzynySiatkowkaPlazowa.value(DSP.at(i)).m_Punkty)));
        }
        else if (i >=A && i < B){
            pktza = 0;
            pktprzeciw = 0;
            Nazwa = NoweZawody.Druzyny.DruzynyDwaOgnie.value(DDO.at(i - A)).Nazwa();
            ui->TableRank->setItem(i,0,new QTableWidgetItem(Nazwa));
            ui->TableRank->setItem(i, 1,new QTableWidgetItem("Dwa Ognie"));
            for (int j = 0; j < MDO.size(); j++){
                if (NoweZawody.Spotkania.MeczeDwochOgni.value(MDO.at(j)).m_Gospodarz.m_Nazwa == Nazwa) {
                    pktza += NoweZawody.Spotkania.MeczeDwochOgni.value(MDO.at(j)).m_PunktyGospodarza;
                    pktprzeciw += NoweZawody.Spotkania.MeczeDwochOgni.value(MDO.at(j)).m_PunktyGoscia;
                }
                else if (NoweZawody.Spotkania.MeczeDwochOgni.value(MDO.at(j)).m_Gosc.m_Nazwa == Nazwa) {
                    pktza += NoweZawody.Spotkania.MeczeDwochOgni.value(MDO.at(j)).m_PunktyGoscia;
                    pktprzeciw += NoweZawody.Spotkania.MeczeDwochOgni.value(MDO.at(j)).m_PunktyGospodarza;
                }
            }
            Wynik = QString::number(pktza) + " - " + QString::number(pktprzeciw);
            ui->TableRank->setItem(i,2,new QTableWidgetItem(Wynik));
            ui->TableRank->setItem(i,3,new QTableWidgetItem(QString::number(NoweZawody.Druzyny.DruzynyDwaOgnie.value(DDO.at(i - A)).m_Punkty)));
        }
        else {
            pktza = 0;
            pktprzeciw = 0;
            Nazwa = NoweZawody.Druzyny.DruzynyPrzeciaganieLiny.value(DPL.at(i - B)).Nazwa();
            ui->TableRank->setItem(i,0,new QTableWidgetItem(Nazwa));
            ui->TableRank->setItem(i, 1,new QTableWidgetItem("Przeciaganie Liny"));
            for (int j = 0; j < MPL.size(); j++){
                if (NoweZawody.Spotkania.MeczePrzeciaganieLiny.value(MPL.at(j)).m_Gospodarz.m_Nazwa == Nazwa) {
                    pktza += NoweZawody.Spotkania.MeczePrzeciaganieLiny.value(MPL.at(j)).m_PunktyGospodarza;
                    pktprzeciw += NoweZawody.Spotkania.MeczePrzeciaganieLiny.value(MPL.at(j)).m_PunktyGoscia;
                }
                else if (NoweZawody.Spotkania.MeczePrzeciaganieLiny.value(MPL.at(j)).m_Gosc.m_Nazwa == Nazwa) {
                    pktza += NoweZawody.Spotkania.MeczePrzeciaganieLiny.value(MPL.at(j)).m_PunktyGoscia;
                    pktprzeciw += NoweZawody.Spotkania.MeczePrzeciaganieLiny.value(MPL.at(j)).m_PunktyGospodarza;
                }
            }
            Wynik = QString::number(pktza) + " - " + QString::number(pktprzeciw);
            ui->TableRank->setItem(i,2,new QTableWidgetItem(Wynik));
            ui->TableRank->setItem(i,3,new QTableWidgetItem(QString::number(NoweZawody.Druzyny.DruzynyPrzeciaganieLiny.value(DPL.at(i - B)).m_Punkty)));
        }
    }
}

void MainWindow::AddTeam()
{
    ui->TableTeam->insertRow(0);
    ui->TableRank->insertRow(0);
    int a = qrand()%3;
    NoweZawody.UstawDruzyne(gen.GenerujDruzyne(),a);
}

void MainWindow::AddRefree()
{
    ui->TableRefree->insertRow(0);
    int a = qrand()%4;
    if (a == 0){
        NoweZawody.UstawSedziego(gen.GenerujSedziegoGlownego(), a);
    }
    else if (a == 1){
        NoweZawody.UstawSedziego(gen.GenerujSedziegoGlownego(), a);
    }
    else if (a == 2){
        NoweZawody.UstawSedziego(gen.GenerujSedziegoGlownego(), a);
    }
    else{
        NoweZawody.UstawSedziego(gen.GenerujSedziegoPomocniczego(), 0, true);
    }
}

void MainWindow::AddMatch()
{
    ui->TableMatch->insertRow(0);
    NoweZawody.UstawSpotkania();
}

void MainWindow::AddRank()
{

}

void MainWindow::AddScore()
{
    NoweZawody.RozegrajMecze();
}
