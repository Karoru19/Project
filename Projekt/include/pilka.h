#ifndef PILKA_H
#define PILKA_H

#include "meczdruzynowy.h"

class Pilka : public MeczDruzynowy
{
public:
    Pilka();
    Pilka(Druzyna Gospodarz, Druzyna Gosc, SedziaGlowny Sedzia);
};

#endif // PILKA_H
