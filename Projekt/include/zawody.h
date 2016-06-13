#ifndef ZAWODY_H
#define ZAWODY_H

#include <cstdlib>
#include "listadruzyn.h"
#include "listasedziow.h"
#include "listaspotkan.h"

class Zawody
{
public:
    ListaSpotkan Spotkania;
    ListaSedziow Sedziowie;
    ListaDruzyn Druzyny;

    int Zwyciezcy = 4;
    bool Koniec = false;

    QMap <QString, Druzyna> ListaZwyciezcowSiatkowkaPlazowa;
    QMap <QString, Druzyna> ListaZwyciezcowDwaOgnie;
    QMap <QString, Druzyna> ListaZwyciezcowPrzeciaganieLiny;

    Zawody();

    bool UstawDruzyne (Druzyna NowaDruzyna, int Konkurencja);
    bool UsunDruzyne (QString Nazwa);
    bool UstawSedziego (Sedzia NowySedzia, int Konkurencja, bool Pomocniczy = false);
    bool UsunSedziego (QString Imie, QString Nazwisko);

    void UstawSpotkania();
    void RozegrajMecze();
};

#endif // ZAWODY_H
