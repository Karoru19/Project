#include "mecz.h"

Mecz::Mecz(SedziaGlowny Sedzia, int PunktyGospodarza, int PunktyGoscia) : m_PunktyGospodarza(PunktyGospodarza), m_PunktyGoscia(PunktyGoscia) , m_Sedzia(Sedzia) {

}

int Mecz::PunktyGospodarza() const
{
    return m_PunktyGospodarza;
}

int Mecz::PunktyGoscia() const
{
    return m_PunktyGoscia;
}
