#include "sedzia.h"

Sedzia::Sedzia() : Osoba() {

}

Sedzia::Sedzia(QString Imie, QString Nazwisko) : Osoba(Imie, Nazwisko) {

}

Sedzia::Sedzia(const Osoba &O) : Osoba(O) {

}
