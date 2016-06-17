#ifndef LISTASPOTKAN_H
#define LISTASPOTKAN_H

#include "przeciaganieliny.h"
#include "siatkowkaplazowa.h"
#include "dwaognie.h"
#include "QMap"

/**
 * @brief Przechowuje informacje o meczach.
 *
 * @see ListaSedziow
 * @see ListaDruzyn
 */
class ListaSpotkan
{
public:
    QMap <QString, SiatkowkaPlazowa> MeczeSiatkowekPlazowych; ///< Zawiera dane z siatkówki plażowej.
    QMap <QString, DwaOgnie> MeczeDwochOgni; ///< Zawiera dane z dwóch ogni.
    QMap <QString, PrzeciaganieLiny> MeczePrzeciaganieLiny; ///< Zawiera dane z przeciągania liny.

    ListaSpotkan();
};

#endif // LISTASPOTKAN_H
