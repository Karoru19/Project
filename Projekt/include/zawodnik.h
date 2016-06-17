#ifndef ZAWODNIK_H
#define ZAWODNIK_H

#include "osoba.h"

/**
 * @brief Klasa zawodnika.
 */
class Zawodnik : public Osoba {
public:
    int m_Numer; ///< Numer zawodnika.

    Zawodnik(); ///< Konstruktor domyślny

    /**
     * @brief Konstruktor.
     * @param Imie Imie zawodnika.
     * @param Nazwisko Nazwisko zawodnika.
     * @param Numer Numer zawodnika.
     */
    Zawodnik(QString Imie, QString Nazwisko, int Numer);
    Zawodnik(const Zawodnik &Z); ///< Konstruktor kopiujący.

    int Numer() const; ///< Zwraca numer zawodnika.
    void setNumer(int Numer); ///< Ustawia numer zawodnika.
};

#endif // ZAWODNIK_H
