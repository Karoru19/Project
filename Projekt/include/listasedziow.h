#ifndef LISTASEDZIOW_H
#define LISTASEDZIOW_H

#include "sedziaglowny.h"
#include "sedziapomocniczy.h"

#include <QMap>

/**
 * @brief Przechowuje informacje o sędziach.
 *
 * @see ListaSpotkan
 * @see ListaDruzyn
 */
class ListaSedziow
{
public:
    QMap <QString, SedziaGlowny> SedziowieGlowniSiatkowkaPlazowa; ///< Zawiera dane z siatkówki plażowej.
    QMap <QString, SedziaPomocniczy> SedziowiePomocniczySiatkowkaPlazowa; ///< Zawiera dane z siatkówki plażowej.
    QMap <QString, SedziaGlowny> SedziowieDwaOgnie; ///< Zawiera dane z dwóch ogni.
    QMap <QString, SedziaGlowny> SedziowiePrzeciaganieLiny; ///< Zawiera dane z przeciągania liny.

    ListaSedziow();
};

#endif // LISTASEDZIOW_H
