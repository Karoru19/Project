#ifndef MECZ_H
#define MECZ_H

#include "sedziaglowny.h"
#include <cstdlib>

class Mecz
{
public:
    int m_PunktyGospodarza;
    int m_PunktyGoscia;
    SedziaGlowny m_Sedzia;

    Mecz ();
    Mecz (SedziaGlowny Sedzia, int PunktyGospodarza = 0, int PunktyGoscia = 0);

    int PunktyGospodarza() const;
    int PunktyGoscia() const;

    void Rozegraj();
    void UstawMecz(int PunktyGospodarza, int PunktyGoscia);
};

#endif // MECZ_H
