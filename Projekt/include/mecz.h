#ifndef MECZ_H
#define MECZ_H

#include "sedziaglowny.h"

/**
 * @brief Klasa meczu.
 */
class Mecz
{
public:
    int m_PunktyGospodarza = 0; ///< Punkty gospodarza.
    int m_PunktyGoscia = 0; ///< Punkty gościa.
    SedziaGlowny m_Sedzia; ///< Sędzia główny.

    Mecz(); ///< Konstruktor domyślny
    Mecz(SedziaGlowny Sedzia); ///< Konstruktor

    int PunktyGospodarza() const; ///< Zwraca puntky gospodarza.
    int PunktyGoscia() const; ///< Zwraca punkty gościa.

    void Rozegraj(); ///< Rozgrywa mecz dając losowy wynik meczu.
    void UstawMecz(int PunktyGospodarza, int PunktyGoscia); ///< Przekupuje sędziego, ustawia wynik na podany przez użytkownika.
};

#endif // MECZ_H
