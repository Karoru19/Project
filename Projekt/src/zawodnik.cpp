#include "zawodnik.h"

Zawodnik::Zawodnik() : Osoba(), m_Numer(-1) {

}

Zawodnik::Zawodnik(QString Imie, QString Nazwisko, int Numer) : Osoba(Imie, Nazwisko), m_Numer(Numer) {

}

Zawodnik::Zawodnik(const Zawodnik &Z) : Osoba(Z), m_Numer(Z.m_Numer) {

}

int Zawodnik::Numer() const {
    return m_Numer;
}

void Zawodnik::setNumer(int Numer) {
    m_Numer = Numer;
}
