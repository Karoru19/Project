#ifndef DWAOGNIE_H
#define DWAOGNIE_H

#include "pilka.h"

/**
 * @brief Mecz w dwa ognie.
 */
class DwaOgnie : public Pilka
{
public:
    DwaOgnie(); ///< Konstruktor domyślny.

    /**
     * @brief Konstruktor.
     * @param Gospodarz Drużyna gospodarza.
     * @param Gosc Drużyna gościa.
     * @param Sedzia Sedzia.
     */
    DwaOgnie(Druzyna Gospodarz, Druzyna Gosc, SedziaGlowny Sedzia);
};

#endif // DWAOGNIE_H
