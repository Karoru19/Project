#ifndef MECZDRUZYNOWY_H
#define MECZDRUZYNOWY_H

#include "mecz.h"
#include "druzyna.h"

class MeczDruzynowy : public Mecz
{
public:
    Druzyna m_Gospodarz;
    Druzyna m_Gosc;

    MeczDruzynowy();
    MeczDruzynowy(Druzyna Gospodarz, Druzyna Gosc, SedziaGlowny Sedzia);
};

#endif // MECZDRUZYNOWY_H
