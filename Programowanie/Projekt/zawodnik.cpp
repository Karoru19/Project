#include "zawodnik.h"

Zawodnik::Zawodnik(QString Imie, QString Nazwisko, int Numer) : Osoba(Imie, Nazwisko), m_Numer(Numer) {

}

int Zawodnik::Numer() const {
    return m_Numer;
}

void Zawodnik::setNumer(int Numer) {
    m_Numer = Numer;
}
