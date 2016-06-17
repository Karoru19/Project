#ifndef MECZDRUZYNOWY_H
#define MECZDRUZYNOWY_H

#include "mecz.h"
#include "druzyna.h"
/**
 * @brief Klasa meczu drużynowego
 *
 */
class MeczDruzynowy : public Mecz
{
public:
    Druzyna m_Gospodarz; ///< Drużyna gospodarza.
    Druzyna m_Gosc; ///< Drużyna gościa.

    MeczDruzynowy(); ///< Konstruktor domyślny.

    /**
     * @brief Konstruktor.
     * @param Gospodarz Drużyna gospodarza.
     * @param Gosc Drużyna gościa.
     * @param Sedzia Sędzia główny.
     */
    MeczDruzynowy(Druzyna Gospodarz, Druzyna Gosc, SedziaGlowny Sedzia);
};

#endif // MECZDRUZYNOWY_H
