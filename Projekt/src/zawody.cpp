#include "zawody.h"

Zawody::Zawody(){

}

bool Zawody::UstawDruzyne(Druzyna NowaDruzyna, int Konkurencja){
    QString Nazwa = NowaDruzyna.Nazwa();
    if (Konkurencja == 0){
        Druzyny.DruzynySiatkowkaPlazowa.insert(Nazwa, NowaDruzyna);
        return true;
    }
    if (Konkurencja == 1){
        Druzyny.DruzynyDwaOgnie.insert(Nazwa, NowaDruzyna);
        return true;
    }
    if (Konkurencja == 2){
        Druzyny.DruzynyPrzeciaganieLiny.insert(Nazwa, NowaDruzyna);
        return true;
    }
    return false;
}

bool Zawody::UsunDruzyne(QString Nazwa){
    if (Druzyny.DruzynySiatkowkaPlazowa.remove(Nazwa)){
        return true;
    }
    if (Druzyny.DruzynyDwaOgnie.remove(Nazwa)){
        return true;
    }
    if (Druzyny.DruzynyPrzeciaganieLiny.remove(Nazwa)){
        return true;
    }
    return false;
}

bool Zawody::UstawSedziego(Sedzia NowySedzia, int Konkurencja, bool Pomocniczy){
    QString Nazwa = NowySedzia.Imie() + " " + NowySedzia.Nazwisko();
    if (!Pomocniczy){
        if (Konkurencja == 0){
            Sedziowie.SedziowieGlowniSiatkowkaPlazowa.insert(Nazwa, NowySedzia);
            return true;
        }
        if (Konkurencja == 1){
            Sedziowie.SedziowieDwaOgnie.insert(Nazwa, NowySedzia);
            return true;
        }
        if (Konkurencja == 2){
            Sedziowie.SedziowiePrzeciaganieLiny.insert(Nazwa, NowySedzia);
            return true;
        }
        return false;
    }
    else{
        if (Konkurencja == 0){
            Sedziowie.SedziowiePomocniczySiatkowkaPlazowa.insert(Nazwa, NowySedzia);
            return true;
        }
        return false;
    }
}

bool Zawody::UsunSedziego(QString Imie, QString Nazwisko){
    QString Nazwa = Imie + " " + Nazwisko;
    if (Sedziowie.SedziowieGlowniSiatkowkaPlazowa.remove(Nazwa)){
        return true;
    }
    if (Sedziowie.SedziowiePomocniczySiatkowkaPlazowa.remove(Nazwa)){
        return true;
    }
    if (Sedziowie.SedziowieDwaOgnie.remove(Nazwa)){
        return true;
    }
    if (Sedziowie.SedziowiePrzeciaganieLiny.remove(Nazwa)){
        return true;
    }
    return false;
}

void Zawody::UstawSpotkania(){
    QList <QString> D = Druzyny.DruzynySiatkowkaPlazowa.keys();
    QList <QString> SG = Sedziowie.SedziowieGlowniSiatkowkaPlazowa.keys();
    QList <QString> SP = Sedziowie.SedziowiePomocniczySiatkowkaPlazowa.keys();

    for (int i = 0; i < D.size(); i++){
        int x = qrand()%SG.size();
        int y = qrand()%SP.size();
        int z = qrand()%SP.size();
        while (z == y){
            z = qrand()%SP.size();
        }
        for (int j = i + 1; j < D.size(); j++){
            QString Nazwa = Druzyny.DruzynySiatkowkaPlazowa.value(D.at(i)).Nazwa() + " " + Druzyny.DruzynySiatkowkaPlazowa.value(D.at(j)).Nazwa();
            Spotkania.MeczeSiatkowekPlazowych.insert(Nazwa, SiatkowkaPlazowa(
                                                           Druzyny.DruzynySiatkowkaPlazowa.value(D.at(i)),
                                                           Druzyny.DruzynySiatkowkaPlazowa.value(D.at(j)),
                                                           Sedziowie.SedziowieGlowniSiatkowkaPlazowa.value(SG.at(x)),
                                                           Sedziowie.SedziowiePomocniczySiatkowkaPlazowa.value(SP.at(y)),
                                                           Sedziowie.SedziowiePomocniczySiatkowkaPlazowa.value(SP.at(z))));
        }
    }

    D = Druzyny.DruzynyDwaOgnie.keys();
    SG = Sedziowie.SedziowieDwaOgnie.keys();
    for (int i = 0; i < D.size(); i++){
        int x = qrand()%SG.size();
        for (int j = i + 1; j < D.size(); j++){
        QString Nazwa = Druzyny.DruzynyDwaOgnie.value(D.at(i)).Nazwa() + " " + Druzyny.DruzynyDwaOgnie.value(D.at(j)).Nazwa();
        Spotkania.MeczeDwochOgni.insert(Nazwa, DwaOgnie(
                                                        Druzyny.DruzynyDwaOgnie.value(D.at(i)),
                                                        Druzyny.DruzynyDwaOgnie.value(D.at(j)),
                                                        Sedziowie.SedziowieDwaOgnie.value(SG.at(x))));
        }
    }

    D = Druzyny.DruzynyPrzeciaganieLiny.keys();
    SG = Sedziowie.SedziowiePrzeciaganieLiny.keys();
    for (int i = 0; i < D.size(); i++){
        int x = qrand()%SG.size();
        for (int j =  i + 1; j < D.size(); j++){
            QString Nazwa = Druzyny.DruzynyPrzeciaganieLiny.value(D.at(i)).Nazwa() + " " + Druzyny.DruzynyPrzeciaganieLiny.value(D.at(j)).Nazwa();
            Spotkania.MeczePrzeciaganieLiny.insert(Nazwa, PrzeciaganieLiny(
                                                                           Druzyny.DruzynyPrzeciaganieLiny.value(D.at(i)),
                                                                           Druzyny.DruzynyPrzeciaganieLiny.value(D.at(j)),
                                                                           Sedziowie.SedziowiePrzeciaganieLiny.value(SG.at(x))));
        }
    }
}

void Zawody::RozegrajMecze()
{
    QList <QString> MSP = Spotkania.MeczeSiatkowekPlazowych.keys();
    QList <QString> MDO = Spotkania.MeczeDwochOgni.keys();
    QList <QString> MPL = Spotkania.MeczePrzeciaganieLiny.keys();

    QString Gosp;
    QString Gosc;

    int Pkt = 0;

    for (int i = 0; i < MSP.size(); i++){
        Spotkania.MeczeSiatkowekPlazowych[MSP.at(i)].Rozegraj();
        Gosp = Spotkania.MeczeSiatkowekPlazowych.value(MSP.at(i)).m_Gospodarz.Nazwa();
        Gosc = Spotkania.MeczeSiatkowekPlazowych.value(MSP.at(i)).m_Gosc.Nazwa();
        Pkt = Spotkania.MeczeSiatkowekPlazowych.value(MSP.at(i)).m_PunktyGospodarza;
        Druzyny.DruzynySiatkowkaPlazowa[(Gosp)].m_PunktyZdobyte += Pkt;
        Druzyny.DruzynySiatkowkaPlazowa[(Gosp)].m_PunktyStracone += Spotkania.MeczeSiatkowekPlazowych.value(MSP.at(i)).m_PunktyGoscia;
        Druzyny.DruzynySiatkowkaPlazowa[(Gosc)].m_PunktyZdobyte += Spotkania.MeczeSiatkowekPlazowych.value(MSP.at(i)).m_PunktyGoscia;
        Druzyny.DruzynySiatkowkaPlazowa[(Gosc)].m_PunktyStracone += Pkt;
        if (Pkt != 3){
            Druzyny.DruzynySiatkowkaPlazowa[(Gosc)].Wygrana();
        }
        else {
            Druzyny.DruzynySiatkowkaPlazowa[(Gosp)].Wygrana();
        }
    }
    for (int i = 0; i < MDO.size(); i++){
        Spotkania.MeczeDwochOgni[(MDO.at(i))].Rozegraj();
        Gosp = Spotkania.MeczeDwochOgni.value(MDO.at(i)).m_Gospodarz.Nazwa();
        Gosc = Spotkania.MeczeDwochOgni.value(MDO.at(i)).m_Gosc.Nazwa();
        Pkt = Spotkania.MeczeDwochOgni.value(MDO.at(i)).m_PunktyGospodarza;
        Druzyny.DruzynyDwaOgnie[(Gosp)].m_PunktyZdobyte += Pkt;
        Druzyny.DruzynyDwaOgnie[(Gosp)].m_PunktyStracone += Spotkania.MeczeDwochOgni.value(MDO.at(i)).m_PunktyGoscia;
        Druzyny.DruzynyDwaOgnie[(Gosc)].m_PunktyZdobyte += Spotkania.MeczeDwochOgni.value(MDO.at(i)).m_PunktyGoscia;
        Druzyny.DruzynyDwaOgnie[(Gosc)].m_PunktyStracone += Pkt;
        if (Pkt != 3){
            Druzyny.DruzynyDwaOgnie[(Gosc)].Wygrana();
        }
        else {
            Druzyny.DruzynyDwaOgnie[(Gosp)].Wygrana();
        }
    }
    for (int i = 0; i < MPL.size(); i++){
        Spotkania.MeczePrzeciaganieLiny[(MPL.at(i))].Rozegraj();
        Gosp = Spotkania.MeczePrzeciaganieLiny.value(MPL.at(i)).m_Gospodarz.Nazwa();
        Gosc = Spotkania.MeczePrzeciaganieLiny.value(MPL.at(i)).m_Gosc.Nazwa();
        Pkt = Spotkania.MeczePrzeciaganieLiny.value(MPL.at(i)).m_PunktyGospodarza;
        Druzyny.DruzynyPrzeciaganieLiny[(Gosp)].m_PunktyZdobyte += Pkt;
        Druzyny.DruzynyPrzeciaganieLiny[(Gosp)].m_PunktyStracone += Spotkania.MeczePrzeciaganieLiny.value(MPL.at(i)).m_PunktyGoscia;
        Druzyny.DruzynyPrzeciaganieLiny[(Gosc)].m_PunktyZdobyte += Spotkania.MeczePrzeciaganieLiny.value(MPL.at(i)).m_PunktyGoscia;
        Druzyny.DruzynyPrzeciaganieLiny[(Gosc)].m_PunktyStracone += Pkt;
        if (Pkt != 3){
            Druzyny.DruzynyPrzeciaganieLiny[(Gosc)].Wygrana();
        }
        else {
            Druzyny.DruzynyPrzeciaganieLiny[(Gosp)].Wygrana();
        }
    }
}


