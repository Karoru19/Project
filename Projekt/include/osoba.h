#ifndef OSOBA_H
#define OSOBA_H

#include <QString>

/**
 * @brief Klasa osoby.
 */
class Osoba {
public:
    QString m_Imie; ///< Imie
    QString m_Nazwisko; ///< Nazwisko

    Osoba(); ///< Konstruktor domyślny.
    Osoba(QString Imie, QString Nazwisko); ///< Konstruktor, ustawia imię i nazwisko.
    Osoba(const Osoba &O); ///< Konstruktor kopiujący.

    QString Imie() const; ///< Zwraca imię.
    QString Nazwisko() const; ///< Zwraca nazwisko.

    void setImie(const QString &Imie); ///< Ustawia imie.
    void setNazwisko(const QString &Nazwisko); ///< Ustawia nazwisko.
};

#endif // OSOBA_H
