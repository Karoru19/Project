#ifndef SIATKOWKAPLAZOWA_H
#define SIATKOWKAPLAZOWA_H

#include "siatkowka.h"

/**
 * @brief Klasa meczu siatkówki plażowej.
 */
class SiatkowkaPlazowa : public Siatkowka
{
public:
    SiatkowkaPlazowa(); ///< Konstruktor domyślny.

    /**
     * @brief Konstruktor
     * @param Gospodarz Drużyna gospodarza.
     * @param Gosc Drużyna gościa.
     * @param Sedzia Sędzia główny.
     * @param SedziaPomocniczy1 Pierwszy sędzia pomocniczy.
     * @param SedziaPomocniczy2 Drugi sędzia pomoczniczy.
     */
    SiatkowkaPlazowa(Druzyna Gospodarz, Druzyna Gosc, SedziaGlowny Sedzia, SedziaPomocniczy SedziaPomocniczy1, SedziaPomocniczy SedziaPomocniczy2);
};

#endif // SIATKOWKAPLAZOWA_H
