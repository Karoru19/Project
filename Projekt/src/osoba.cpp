#include "osoba.h"

Osoba::Osoba() : m_Imie("Bezimienny"), m_Nazwisko("Beznazwiska") {

}

Osoba::Osoba(QString Imie, QString Nazwisko) : m_Imie(Imie), m_Nazwisko(Nazwisko) {

}

Osoba::Osoba(const Osoba &O) : m_Imie(O.m_Imie), m_Nazwisko(O.m_Nazwisko) {

}

QString Osoba::Imie() const {
    return m_Imie;
}

QString Osoba::Nazwisko() const {
    return m_Nazwisko;
}

void Osoba::setImie(const QString &Imie) {
    m_Imie = Imie;
}

void Osoba::setNazwisko(const QString &Nazwisko) {
    m_Nazwisko = Nazwisko;
}
