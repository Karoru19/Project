#ifndef ZAWODNIK_H
#define ZAWODNIK_H

#include "osoba.h"

class Zawodnik : public Osoba {
private:
    int m_Numer;
public:
    Zawodnik(QString Imie, QString Nazwisko, int Numer);

    int Numer() const;
    void setNumer(int Numer);
};

#endif // ZAWODNIK_H
