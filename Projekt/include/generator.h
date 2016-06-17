#ifndef GENERATOR_H
#define GENERATOR_H

#include <QStringList>
#include <QFile>
#include <QTextStream>
#include <cstdlib>
#include "osoba.h"
#include "sedziaglowny.h"
#include "sedziapomocniczy.h"
#include "zawodnik.h"
#include "druzyna.h"

class Generator
{
private:
    QStringList m_ImieMeskie;
    QStringList m_NazwiskoMeskie;
    QStringList m_ImieZenskie;
    QStringList m_NazwiskoZenskie;
    QStringList m_Przymiotnik;
    QStringList m_Rzeczownik;
    QStringList m_NWO;
public:
    Generator(); ///< Konstruktor domyślny.
    Osoba GenerujOsobe(); ///< Zwraca losową osobę.
    Zawodnik GenerujZawodnika(int Numer); ///< Zwraca losowego zawodnika o podanym numerze.
    SedziaGlowny GenerujSedziegoGlownego(); ///< Zwraca losowego sedziego głównego.
    SedziaPomocniczy GenerujSedziegoPomocniczego(); ///< Zwraca losowego sędziego pomocniczego.
    Druzyna GenerujDruzyne(); ///< Zwraca losową drużynę.
};

#endif // GENERATOR_H
