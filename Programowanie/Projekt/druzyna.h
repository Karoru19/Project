#ifndef DRUZYNA_H
#define DRUZYNA_H

#include <QList>
#include <zawodnik.h>

class Druzyna {
protected:
    QString m_Nazwa;
    QList <Zawodnik> m_Zawodnicy;
    int m_Punkty;
public:
    Druzyna(QString Nazwa, QList <Zawodnik> Zawodnicy, int Punkty);

    int Punkty() const;

    void Wygrana();
    void Przegrana();
};

#endif // DRUZYNA_H
