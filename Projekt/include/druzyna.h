#ifndef DRUZYNA_H
#define DRUZYNA_H

#include <QList>
#include <zawodnik.h>

class Druzyna {
public:
    QString m_Nazwa;
    QList <Zawodnik> m_Zawodnicy;
    int m_Punkty;

    Druzyna();
    Druzyna(QString Nazwa, QList <Zawodnik> Zawodnicy, int Punkty = 0);

    int Punkty() const;

    void Wygrana();
    QString Nazwa() const;
};

#endif // DRUZYNA_H
