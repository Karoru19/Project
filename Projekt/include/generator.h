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
    QStringList m_NWM;
public:
    Generator();
    Osoba GenerujOsobe();
    Zawodnik GenerujZawodnika(int a);
    SedziaGlowny GenerujSedziegoGlownego();
    SedziaPomocniczy GenerujSedziegoPomocniczego();
    Druzyna GenerujDruzyne();
};

#endif // GENERATOR_H
