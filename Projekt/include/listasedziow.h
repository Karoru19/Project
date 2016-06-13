#ifndef LISTASEDZIOW_H
#define LISTASEDZIOW_H

#include "sedziaglowny.h"
#include "sedziapomocniczy.h"

#include <QMap>

class ListaSedziow
{
public:
    QMap <QString, SedziaGlowny> SedziowieGlowniSiatkowkaPlazowa;
    QMap <QString, SedziaPomocniczy> SedziowiePomocniczySiatkowkaPlazowa;
    QMap <QString, SedziaGlowny> SedziowieDwaOgnie;
    QMap <QString, SedziaGlowny> SedziowiePrzeciaganieLiny;

    ListaSedziow();
};

#endif // LISTASEDZIOW_H
