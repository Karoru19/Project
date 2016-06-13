#ifndef LISTADRUZYN_H
#define LISTADRUZYN_H

#include "druzyna.h"
#include <QMap>

class ListaDruzyn
{
public:
    QMap <QString, Druzyna> DruzynySiatkowkaPlazowa;
    QMap <QString, Druzyna> DruzynyDwaOgnie;
    QMap <QString, Druzyna> DruzynyPrzeciaganieLiny;

    ListaDruzyn();
};

#endif // LISTADRUZYN_H
