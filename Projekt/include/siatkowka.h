#ifndef SIATKOWKA_H
#define SIATKOWKA_H

#include "pilka.h"
#include "sedziapomocniczy.h"

/**
 * @brief Klasa meczu w siatkowkę.
 */
class Siatkowka : public Pilka
{
public:
    SedziaPomocniczy m_SedziaPomocniczy1; ///< Sędzia pomocniczy 1.
    SedziaPomocniczy m_SedziaPomocniczy2; ///< Sędzia pomocniczy 2.

    Siatkowka(); ///< Konstruktor domyślny.

    /**
     * @brief Konstruktor.
     * @param Gospodarz Drużyna gospodarza.
     * @param Gosc Drużyna gościa.
     * @param Sedzia Sędzia główny.
     * @param SedziaPomocniczy1 Pierwszy sędzia pomocniczy.
     * @param SedziaPomocniczy2 Drugi sędzia pomocniczy.
     */
    Siatkowka(Druzyna Gospodarz, Druzyna Gosc, SedziaGlowny Sedzia, SedziaPomocniczy SedziaPomocniczy1, SedziaPomocniczy SedziaPomocniczy2);
};

#endif // SIATKOWKA_H
