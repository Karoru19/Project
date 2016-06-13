#ifndef PRZECIAGANIELINY_H
#define PRZECIAGANIELINY_H

#include "meczdruzynowy.h"

class PrzeciaganieLiny : public MeczDruzynowy
{
public:
    PrzeciaganieLiny();
    PrzeciaganieLiny(Druzyna Gospodarz, Druzyna Gosc, SedziaGlowny Sedzia);
};

#endif // PRZECIAGANIELINY_H
