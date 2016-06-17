#ifndef SEDZIA_H
#define SEDZIA_H

#include "osoba.h"

/**
 * @brief Klasa sędziego.
 */
class Sedzia : public Osoba {
public:
    Sedzia(); ///< Konstruktor domyślny.
    Sedzia(QString Imie, QString Nazwisko); ///< Konstruktor.
    Sedzia(const Osoba &O); ///< Konwersja z osoby.
};

#endif // SEDZIA_H
