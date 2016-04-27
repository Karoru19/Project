#ifndef OSOBA_H
#define OSOBA_H

#include <QString>

class Osoba {
private:
    QString m_Imie;
    QString m_Nazwisko;
public:
    Osoba(QString Imie, QString Nazwisko);

    QString Imie() const;
    QString Nazwisko() const;

    void setImie(const QString &Imie);
    void setNazwisko(const QString &Nazwisko);
};

#endif // OSOBA_H
