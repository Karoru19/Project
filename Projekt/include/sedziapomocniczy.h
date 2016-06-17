#ifndef SEDZIAPOMOCNICZY_H
#define SEDZIAPOMOCNICZY_H

#include "sedzia.h"

/**
 * @brief Klasa sędziego pomocniczego.
 */
class SedziaPomocniczy : public Sedzia
{
public:
    SedziaPomocniczy(); ///< Konstruktor domyślny.
    SedziaPomocniczy(QString Imie, QString Nazwisko); ///< Konstruktor, ustawia imie i nazwisko.
    SedziaPomocniczy(const Osoba &O); ///< Konwersja z osoby.
};

#endif // SEDZIAPOMOCNICZY_H
