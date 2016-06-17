#ifndef SEDZIAGLOWNY_H
#define SEDZIAGLOWNY_H

#include "sedzia.h"

/**
 * @brief Klasa sędziego głównego
 */
class SedziaGlowny : public Sedzia {
public:
    SedziaGlowny(); ///< Konstruktor domyślny.
    SedziaGlowny(QString Imie, QString Nazwisko); ///< Konstruktor, ustawia imie i nazwisko.
    SedziaGlowny(const Osoba &O); ///< Konwersja z osoby.
};

#endif // SEDZIAGLOWNY_H
