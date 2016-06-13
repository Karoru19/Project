#ifndef SIATKOWKA_H
#define SIATKOWKA_H

#include "pilka.h"
#include "sedziapomocniczy.h"

class Siatkowka : public Pilka
{
public:
    SedziaPomocniczy m_SedziaPomocniczy1;
    SedziaPomocniczy m_SedziaPomocniczy2;

    Siatkowka();
    Siatkowka(Druzyna Gospodarz, Druzyna Gosc, SedziaGlowny Sedzia, SedziaPomocniczy SedziaPomocniczy1, SedziaPomocniczy SedziaPomocniczy2);
};

#endif // SIATKOWKA_H
