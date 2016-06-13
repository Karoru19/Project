#ifndef ZAWODNIK_H
#define ZAWODNIK_H

#include "osoba.h"

class Zawodnik : public Osoba {
public:
    int m_Numer;

    Zawodnik();
    Zawodnik(QString Imie, QString Nazwisko, int Numer);
    Zawodnik(const Zawodnik &Z);

    int Numer() const;
    void setNumer(int Numer);
};

#endif // ZAWODNIK_H
