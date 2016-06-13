#ifndef LISTASPOTKAN_H
#define LISTASPOTKAN_H

#include "przeciaganieliny.h"
#include "siatkowkaplazowa.h"
#include "dwaognie.h"
#include "QMap"

class ListaSpotkan
{
public:
    QMap <QString, SiatkowkaPlazowa> MeczeSiatkowekPlazowych;
    QMap <QString, DwaOgnie> MeczeDwochOgni;
    QMap <QString, PrzeciaganieLiny> MeczePrzeciaganieLiny;

    ListaSpotkan();
};

#endif // LISTASPOTKAN_H
