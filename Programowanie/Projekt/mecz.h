#ifndef MECZ_H
#define MECZ_H

#include "sedziaglowny.h"

class Mecz
{
private:
    int m_PunktyGospodarza;
    int m_PunktyGoscia;
    SedziaGlowny m_Sedzia;
public:
    Mecz (SedziaGlowny Sedzia, int PunktyGospodarza = 0, int PunktyGoscia = 0);
    int PunktyGospodarza() const;
    int PunktyGoscia() const;
};

#endif // MECZ_H
