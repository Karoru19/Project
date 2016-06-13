#include "include/siatkowka.h"

Siatkowka::Siatkowka()
{

}

Siatkowka::Siatkowka(Druzyna Gospodarz, Druzyna Gosc, SedziaGlowny Sedzia, SedziaPomocniczy SedziaPomocniczy1, SedziaPomocniczy SedziaPomocniczy2)
    : Pilka(Gospodarz, Gosc, Sedzia), m_SedziaPomocniczy1(SedziaPomocniczy1), m_SedziaPomocniczy2(SedziaPomocniczy2) {

}
