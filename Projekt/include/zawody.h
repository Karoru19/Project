#ifndef ZAWODY_H
#define ZAWODY_H

#include "listadruzyn.h"
#include "listasedziow.h"
#include "listaspotkan.h"
#include <QDebug>

/**
 * @brief Klasa zawodów.
 */
class Zawody
{
public:
    ListaSpotkan Spotkania; ///< Spotkania
    ListaSedziow Sedziowie; ///< Sedziowie
    ListaDruzyn Druzyny; ///< Drużyny

    Zawody(); ///< Konstruktor.

    bool UstawDruzyne (Druzyna NowaDruzyna, int Konkurencja); ///< Dodaje drużynę do zawodów.
    bool UsunDruzyne (QString Nazwa); ///< Usuwa drużynę z zawodów.
    bool UstawSedziego (Sedzia NowySedzia, int Konkurencja, bool Pomocniczy = false); ///< Dodaje sędziego do zawodów.
    bool UsunSedziego (QString Imie, QString Nazwisko); ///< Usuwa sedziego z zawodów.

    void UstawSpotkania(); ///< Planuje spotkania.
    void RozegrajMecze(); ///< Losuje wyniki meczy.
};

#endif // ZAWODY_H
