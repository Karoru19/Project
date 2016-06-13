#ifndef SIATKOWKAPLAZOWA_H
#define SIATKOWKAPLAZOWA_H

#include "siatkowka.h"

class SiatkowkaPlazowa : public Siatkowka
{
public:
    SiatkowkaPlazowa();
    SiatkowkaPlazowa(Druzyna Gospodarz, Druzyna Gosc, SedziaGlowny Sedzia, SedziaPomocniczy SedziaPomocniczy1, SedziaPomocniczy SedziaPomocniczy2);
};

#endif // SIATKOWKAPLAZOWA_H
