#ifndef PILKA_H
#define PILKA_H

#include "meczdruzynowy.h"

/**
 * @brief Klasa meczu w piłkę.
 */
class Pilka : public MeczDruzynowy
{
public:
    Pilka(); ///< Konstruktor domyślny.

    /**
     * @brief Konstruktor
     * @param Gospodarz Drużyna gospodarza.
     * @param Gosc Drużyna gościa.
     * @param Sedzia Sędzia główny.
     */
    Pilka(Druzyna Gospodarz, Druzyna Gosc, SedziaGlowny Sedzia);
};

#endif // PILKA_H
