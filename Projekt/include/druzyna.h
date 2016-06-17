#ifndef DRUZYNA_H
#define DRUZYNA_H

#include <QList>
#include <zawodnik.h>

/**
 * @brief Klasa drużyna, składa się z ludzi i nazwy.
 *
 * @see Zawodnik
 */
class Druzyna {
public:
    QString m_Nazwa; ///< Nazwa drużyny.
    QList <Zawodnik> m_Zawodnicy; ///< Lista zawodników.
    int m_Punkty = 0; ///< Liczba wygranych meczy.
    int m_PunktyZdobyte = 0; ///< Łączną liczba punktów zdobytych przez drużynę we wszystkich meczach.
    int m_PunktyStracone = 0; ///< Łączną liczba punktów straconych przez drużynę we wszystkich meczach.

    Druzyna(); ///< Konstruktor domyślny.

    /**
     * @brief Konstruktor
     * @param Nazwa Nazwa drużyny.
     * @param Zawodnicy Lista zawodników.
     */
    Druzyna(QString Nazwa, QList <Zawodnik> Zawodnicy);

    int Punkty() const; ///< Zwraca liczbę punktów.

    void Wygrana(); ///< Wygrywa drużynę.
    QString Nazwa() const; ///< Zwraca nazwę drużyny.
};

#endif // DRUZYNA_H
