#ifndef LISTADRUZYN_H
#define LISTADRUZYN_H

#include "druzyna.h"
#include <QMap>

/**
 * @brief Przechowuje informacje o drużynach
 *
 * @see ListaSpotkan
 * @see ListaSedziow
 */
class ListaDruzyn
{
public:
    QMap <QString, Druzyna> DruzynySiatkowkaPlazowa; ///< Zawiera dane z siatkówki plażowej.
    QMap <QString, Druzyna> DruzynyDwaOgnie; ///< Zawiera dane z dwóch ogni.
    QMap <QString, Druzyna> DruzynyPrzeciaganieLiny; ///< Zawiera dane z przeciągania liny.

    ListaDruzyn();
};

#endif // LISTADRUZYN_H
