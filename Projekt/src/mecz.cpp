#include "mecz.h"

Mecz::Mecz()
{

}

Mecz::Mecz(SedziaGlowny Sedzia, int PunktyGospodarza, int PunktyGoscia) : m_PunktyGospodarza(PunktyGospodarza), m_PunktyGoscia(PunktyGoscia) , m_Sedzia(Sedzia) {

}

int Mecz::PunktyGospodarza() const {
    return m_PunktyGospodarza;
}

int Mecz::PunktyGoscia() const {
    return m_PunktyGoscia;
}

void Mecz::Rozegraj() {
    int x = qrand()%4;
    m_PunktyGospodarza = x;
    if (x == 3) {
        int y = qrand()%3;
        m_PunktyGoscia = y;
    }
    else {
        m_PunktyGoscia = 3;
    }

}

void Mecz::UstawMecz(int PunktyGospodarza, int PunktyGoscia) {
    int x = m_PunktyGospodarza;
    int y = m_PunktyGoscia;
    x = PunktyGospodarza;
    y = PunktyGoscia;
    m_PunktyGospodarza = x;
    m_PunktyGoscia = y;
}
