#ifndef OSOBA_H
#define OSOBA_H

#include <QString>

class Osoba {
public:
    QString m_Imie;
    QString m_Nazwisko;

    Osoba();
    Osoba(QString Imie, QString Nazwisko);
    Osoba(const Osoba &O);

    QString Imie() const;
    QString Nazwisko() const;

    void setImie(const QString &Imie);
    void setNazwisko(const QString &Nazwisko);
};

#endif // OSOBA_H
