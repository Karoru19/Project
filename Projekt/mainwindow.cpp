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
    GeneratorDruzynyDialog dialog;
    connect(ui->TableTeam->horizontalHeader(), SIGNAL(sortIndicatorChanged(int,Qt::SortOrder)), ui->TableTeam, SLOT(sortByColumn(int)));
    connect(ui->TableReferee->horizontalHeader(), SIGNAL(sortIndicatorChanged(int,Qt::SortOrder)), ui->TableReferee, SLOT(sortByColumn(int)));
    connect(ui->TableMatch->horizontalHeader(), SIGNAL(sortIndicatorChanged(int,Qt::SortOrder)), ui->TableMatch, SLOT(sortByColumn(int)));
    connect(ui->TableRank->horizontalHeader(), SIGNAL(sortIndicatorChanged(int,Qt::SortOrder)), ui->TableRank, SLOT(sortByColumn(int)));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_actionGeneruj_Druzyny_triggered()
{
    GeneratorDruzynyDialog dialog;
    connect(&dialog, &GeneratorDruzynyDialog::GeneratorDruzyny, this, &MainWindow::GeneratorDruzyny);
    connect(this, &MainWindow::DruzynaDodana, &dialog, &GeneratorDruzynyDialog::OKButton);
    dialog.exec();
}

void MainWindow::on_actionGeneruj_Sedziego_triggered()
{
    GeneratorSedziegoDialog dialog;
    connect(&dialog, &GeneratorSedziegoDialog::GeneratorSedziego, this, &MainWindow::GeneratorSedziego);
    connect(this, &MainWindow::SedziaDodany, &dialog, &GeneratorSedziegoDialog::OKButton);
    dialog.exec();
}

void MainWindow::on_actionUsun_2_triggered()
{
    UsunSedziegoDialog dialog;
    dialog.exec();

}

void MainWindow::on_actionDodaj_2_triggered()
{
    QMessageBox::information(this, "UWAGA", "Zle wprowadzenie imienia i nazwiska spowoduje zakonczenie sie programu!");
    DodajSedziegoDialog dialog;
    connect(&dialog, &DodajSedziegoDialog::DodajSedziego, this, &MainWindow::DodajSedziego);
    connect(this, &MainWindow::SedziaDodany, &dialog, &DodajSedziegoDialog::OKButton);
    dialog.exec();
}

void MainWindow::on_actionUsun_triggered()
{
    UsunDruzyneDialog dialog;
    dialog.exec();
}

void MainWindow::on_actionDodaj_triggered()
{
    QMessageBox::information(this, "UWAGA", "Nie wprowadzenie zawodnikow spowoduje zakonczenie sie programu!");
    DodajDruzyneDialog dialog;
    connect(&dialog, &DodajDruzyneDialog::DodajDruzyne, this, &MainWindow::DodajDruzyne);
    connect(this, &MainWindow::DruzynaDodana, &dialog, &DodajDruzyneDialog::OKButton);
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

void MainWindow::UpdateTabReferee()
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

   for (int i = 0; i < ui->TableReferee->rowCount(); i++){
        if (i < A){
            ui->TableReferee->setItem(i,0,new QTableWidgetItem(NoweZawody.Sedziowie.SedziowieGlowniSiatkowkaPlazowa.value(SGSP.at(i)).m_Imie));
            ui->TableReferee->setItem(i,1,new QTableWidgetItem(NoweZawody.Sedziowie.SedziowieGlowniSiatkowkaPlazowa.value(SGSP.at(i)).m_Nazwisko));
            ui->TableReferee->setItem(i,2,new QTableWidgetItem("Sedzia Glowny"));
            ui->TableReferee->setItem(i,3,new QTableWidgetItem("Siatkowka Plazowa"));
        }
        else if (i >=A && i < B){
            ui->TableReferee->setItem(i,0,new QTableWidgetItem(NoweZawody.Sedziowie.SedziowiePomocniczySiatkowkaPlazowa.value(SPSP.at(i-A)).m_Imie));
            ui->TableReferee->setItem(i,1,new QTableWidgetItem(NoweZawody.Sedziowie.SedziowiePomocniczySiatkowkaPlazowa.value(SPSP.at(i-A)).m_Nazwisko));
            ui->TableReferee->setItem(i,2,new QTableWidgetItem("Sedzia Pomocniczy"));
            ui->TableReferee->setItem(i,3,new QTableWidgetItem("Siatkowka Plazowa"));
        }
        else if (i >=B && i < C){
            ui->TableReferee->setItem(i,0,new QTableWidgetItem(NoweZawody.Sedziowie.SedziowieDwaOgnie.value(SGDO.at(i-B)).m_Imie));
            ui->TableReferee->setItem(i,1,new QTableWidgetItem(NoweZawody.Sedziowie.SedziowieDwaOgnie.value(SGDO.at(i-B)).m_Nazwisko));
            ui->TableReferee->setItem(i,2,new QTableWidgetItem("Sedzia"));
            ui->TableReferee->setItem(i,3,new QTableWidgetItem("Dwa Ognie"));
        }
        else {
            ui->TableReferee->setItem(i,0,new QTableWidgetItem(NoweZawody.Sedziowie.SedziowiePrzeciaganieLiny.value(SGPL.at(i-C)).m_Imie));
            ui->TableReferee->setItem(i,1,new QTableWidgetItem(NoweZawody.Sedziowie.SedziowiePrzeciaganieLiny.value(SGPL.at(i-C)).m_Nazwisko));
            ui->TableReferee->setItem(i,2,new QTableWidgetItem("Sedzia"));
            ui->TableReferee->setItem(i,3,new QTableWidgetItem("Przeciaganie Liny"));
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
            pktza = NoweZawody.Druzyny.DruzynySiatkowkaPlazowa.value(DSP.at(i)).m_PunktyZdobyte;
            pktprzeciw = NoweZawody.Druzyny.DruzynySiatkowkaPlazowa.value(DSP.at(i)).m_PunktyStracone;
            Nazwa = NoweZawody.Druzyny.DruzynySiatkowkaPlazowa.value(DSP.at(i)).Nazwa();
            ui->TableRank->setItem(i,0,new QTableWidgetItem(Nazwa));
            ui->TableRank->setItem(i, 1,new QTableWidgetItem("Siatkowka Plazowa"));
            Wynik = QString::number(pktza) + " : " + QString::number(pktprzeciw);
            ui->TableRank->setItem(i,2,new QTableWidgetItem(Wynik));
            ui->TableRank->setItem(i,3,new QTableWidgetItem(QString::number(NoweZawody.Druzyny.DruzynySiatkowkaPlazowa.value(DSP.at(i)).m_Punkty)));
            Wynik = QString::number(pktza-pktprzeciw);
            ui->TableRank->setItem(i, 4, new QTableWidgetItem(Wynik));
        }
        else if (i >=A && i < B){
            pktza = NoweZawody.Druzyny.DruzynyDwaOgnie.value(DDO.at(i - A)).m_PunktyZdobyte;
            pktprzeciw = NoweZawody.Druzyny.DruzynyDwaOgnie.value(DDO.at(i - A)).m_PunktyStracone;
            Nazwa = NoweZawody.Druzyny.DruzynyDwaOgnie.value(DDO.at(i - A)).Nazwa();
            ui->TableRank->setItem(i,0,new QTableWidgetItem(Nazwa));
            ui->TableRank->setItem(i, 1,new QTableWidgetItem("Dwa Ognie"));
            Wynik = QString::number(pktza) + " : " + QString::number(pktprzeciw);
            ui->TableRank->setItem(i,2,new QTableWidgetItem(Wynik));
            ui->TableRank->setItem(i,3,new QTableWidgetItem(QString::number(NoweZawody.Druzyny.DruzynyDwaOgnie.value(DDO.at(i - A)).m_Punkty)));
            Wynik = QString::number(pktza-pktprzeciw);
            ui->TableRank->setItem(i, 4, new QTableWidgetItem(Wynik));
        }
        else {
            pktza = NoweZawody.Druzyny.DruzynyPrzeciaganieLiny.value(DPL.at(i - B)).m_PunktyZdobyte;
            pktprzeciw = NoweZawody.Druzyny.DruzynyPrzeciaganieLiny.value(DPL.at(i - B)).m_PunktyStracone;
            Nazwa = NoweZawody.Druzyny.DruzynyPrzeciaganieLiny.value(DPL.at(i - B)).Nazwa();
            ui->TableRank->setItem(i,0,new QTableWidgetItem(Nazwa));
            ui->TableRank->setItem(i, 1,new QTableWidgetItem("Przeciaganie Liny"));
            Wynik = QString::number(pktza) + " : " + QString::number(pktprzeciw);
            ui->TableRank->setItem(i,2,new QTableWidgetItem(Wynik));
            ui->TableRank->setItem(i,3,new QTableWidgetItem(QString::number(NoweZawody.Druzyny.DruzynyPrzeciaganieLiny.value(DPL.at(i - B)).m_Punkty)));
            Wynik = QString::number(pktza-pktprzeciw);
            ui->TableRank->setItem(i, 4, new QTableWidgetItem(Wynik));
        }
    }
}

void MainWindow::DodajDruzyne(QString Nazwa, QList <Zawodnik> Zawodnicy, int Typ)
{
    if (NoweZawody.Druzyny.DruzynySiatkowkaPlazowa.keys().count(Nazwa) > 0 || NoweZawody.Druzyny.DruzynyDwaOgnie.keys().count(Nazwa) > 0 || NoweZawody.Druzyny.DruzynyPrzeciaganieLiny.keys().count(Nazwa) > 0){
        QMessageBox::warning(this, "UWAGA", "Juz istnieje druzyna o takiej nazwie!");
        return;
    }
    if (Nazwa == NULL || Zawodnicy.count() < 5){
        QMessageBox::warning(this, "UWAGA", "Wpisz nazwe lub zawodnikow");
        return;
    }
    if (Typ & 0x01){
        ui->TableTeam->insertRow(0);
        ui->TableRank->insertRow(0);
        NoweZawody.UstawDruzyne(Druzyna(Nazwa, Zawodnicy), 0);
        emit DruzynaDodana(true);
    }
    if (Typ & 0x02){
        ui->TableTeam->insertRow(0);
        ui->TableRank->insertRow(0);
        NoweZawody.UstawDruzyne(Druzyna(Nazwa, Zawodnicy), 1);
        emit DruzynaDodana(true);
    }
    if (Typ & 0x04){
        ui->TableTeam->insertRow(0);
        ui->TableRank->insertRow(0);
        NoweZawody.UstawDruzyne(Druzyna(Nazwa, Zawodnicy), 2);
        emit DruzynaDodana(true);
    }
    UpdateTabTeam();
}

void MainWindow::DodajSedziego(QString Imie, QString Nazwisko, int Typ)
{
    if (NoweZawody.Sedziowie.SedziowieGlowniSiatkowkaPlazowa.keys().count(Imie + " " + Nazwisko) > 0 || NoweZawody.Sedziowie.SedziowiePomocniczySiatkowkaPlazowa.keys().count(Imie + " " + Nazwisko) > 0 || NoweZawody.Sedziowie.SedziowieDwaOgnie.keys().count(Imie + " " + Nazwisko) > 0 || NoweZawody.Sedziowie.SedziowiePrzeciaganieLiny.keys().count(Imie + " " + Nazwisko) > 0){
        QMessageBox::warning(this, "UWAGA", "Juz istnieje druzyna o takiej nazwie!");
        return;
    }
    if (Imie == NULL || Imie == NULL){
        QMessageBox::warning(this, "UWAGA", "Wprowadz Sedziego");
        emit DruzynaDodana(false);
    }
    if (Typ & 0x01){
        ui->TableReferee->insertRow(0);
        NoweZawody.UstawSedziego(SedziaGlowny(Imie, Nazwisko), 0);
        emit SedziaDodany(true);
    }
    if (Typ & 0x02){
        ui->TableReferee->insertRow(0);
        NoweZawody.UstawSedziego(SedziaPomocniczy(Imie, Nazwisko), 0, true);
        emit SedziaDodany(true);
    }
    if (Typ & 0x04){
        ui->TableReferee->insertRow(0);
        NoweZawody.UstawSedziego(SedziaGlowny(Imie, Nazwisko), 1);
        emit SedziaDodany(true);
    }
    if (Typ & 0x08){
        ui->TableReferee->insertRow(0);
        NoweZawody.UstawSedziego(SedziaGlowny(Imie, Nazwisko), 2);
        emit SedziaDodany(true);
    }
    UpdateTabReferee();
}

void MainWindow::AddMatch()
{
    ui->TableMatch->insertRow(0);
    NoweZawody.UstawSpotkania();
}

void MainWindow::AddScore()
{
    NoweZawody.RozegrajMecze();
}

void MainWindow::GeneratorDruzyny(int Liczba, int Typ)
{
    if (Liczba == 0 || Typ == 0){
        emit DruzynaDodana(false);
    }
    if (Typ & 0x01){
        for (int i = 0; i < Liczba; i++){
            ui->TableTeam->insertRow(0);
            ui->TableRank->insertRow(0);
            NoweZawody.UstawDruzyne(gen.GenerujDruzyne(),0);
        }
        emit DruzynaDodana(true);
    }
    if (Typ & 0x02){
        for (int i = 0; i < Liczba; i++){
            ui->TableTeam->insertRow(0);
            ui->TableRank->insertRow(0);
            NoweZawody.UstawDruzyne(gen.GenerujDruzyne(),1);
        }
        emit DruzynaDodana(true);
    }
    if (Typ & 0x04){
        for (int i = 0; i < Liczba; i++){
            ui->TableTeam->insertRow(0);
            ui->TableRank->insertRow(0);
            NoweZawody.UstawDruzyne(gen.GenerujDruzyne(),2);
        }
        emit DruzynaDodana(true);
    }
    UpdateTabTeam();
    UpdateRank();
}

void MainWindow::GeneratorSedziego(int Liczba, int Typ)
{
    if (Liczba == 0 || Typ == 0){
        emit SedziaDodany(false);
    }
    if (Typ & 0x01){
        for (int i = 0; i < Liczba; i++){
            ui->TableReferee->insertRow(0);
            NoweZawody.UstawSedziego(gen.GenerujSedziegoGlownego(),0);
        }
        emit SedziaDodany(true);
    }
    if (Typ & 0x02){
        for (int i = 0; i < Liczba; i++){
            ui->TableReferee->insertRow(0);
            NoweZawody.UstawSedziego(gen.GenerujSedziegoPomocniczego(), 0, true);
        }
        emit SedziaDodany(true);
    }
    if (Typ & 0x04){
        for (int i = 0; i < Liczba; i++){
            ui->TableReferee->insertRow(0);
            NoweZawody.UstawSedziego(gen.GenerujSedziegoGlownego(),1);
        }
        emit SedziaDodany(true);
    }
    if (Typ & 0x08){
        for (int i = 0; i < Liczba; i++){
            ui->TableReferee->insertRow(0);
            NoweZawody.UstawSedziego(gen.GenerujSedziegoGlownego(),2);
        }
        emit SedziaDodany(true);
    }
    UpdateTabReferee();
}

void MainWindow::on_actionUstaw_Spotkania_triggered()
{
    if ((NoweZawody.Druzyny.DruzynySiatkowkaPlazowa.size() > 0 && NoweZawody.Sedziowie.SedziowieGlowniSiatkowkaPlazowa.size() > 0 && NoweZawody.Sedziowie.SedziowiePomocniczySiatkowkaPlazowa.size() > 0) ||
            (NoweZawody.Druzyny.DruzynyDwaOgnie.size() > 0 && NoweZawody.Sedziowie.SedziowieDwaOgnie.size() > 0) ||
            (NoweZawody.Druzyny.DruzynyPrzeciaganieLiny.size() > 0 && NoweZawody.Sedziowie.SedziowiePrzeciaganieLiny.size() > 0)){

        int a, b, c, ilosc;
        a = NoweZawody.Druzyny.DruzynySiatkowkaPlazowa.size();
        b = NoweZawody.Druzyny.DruzynyDwaOgnie.size();
        c = NoweZawody.Druzyny.DruzynyPrzeciaganieLiny.size();
        ilosc = (a*(a-1)+b*(b-1)+c*(c-1))/2;
        for (int i = 0; i < ilosc; i++){
            AddMatch();
        }
        UpdateMatch();
    }
    else{
        QMessageBox::warning(this,"UWAGA", "Dodaj Druzyne lub Sedziego Glownego lub Sedziego Pomocniczego!");
    }
}

void MainWindow::on_actionRozegraj_triggered()
{
    if (NoweZawody.Spotkania.MeczeSiatkowekPlazowych.size() > 0 || NoweZawody.Spotkania.MeczeDwochOgni.size() > 0 || NoweZawody.Spotkania.MeczePrzeciaganieLiny.size() > 0){
        AddScore();
    }
    else {
        QMessageBox::warning(this,"UWAGA", "Nie ma zadnych meczy!");
    }
}
