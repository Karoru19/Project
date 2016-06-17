#ifndef PRZECIAGANIELINY_H
#define PRZECIAGANIELINY_H

#include "meczdruzynowy.h"

/**
 * @brief Klasa meczu w przeciąganie liny.
 */
class PrzeciaganieLiny : public MeczDruzynowy
{
public:
    PrzeciaganieLiny(); ///< Konstruktor domyślny.

    /**
     * @brief Konstruktor.
     * @param Gospodarz Drużyna gospodarza.
     * @param Gosc Drużyna gościa.
     * @param Sedzia Sedzia główny.
     */
    PrzeciaganieLiny(Druzyna Gospodarz, Druzyna Gosc, SedziaGlowny Sedzia);
};

#endif // PRZECIAGANIELINY_H
