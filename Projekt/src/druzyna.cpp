#include "druzyna.h"

QString Druzyna::Nazwa() const
{
    return m_Nazwa;
}

Druzyna::Druzyna() {

}

Druzyna::Druzyna(QString Nazwa, QList<Zawodnik> Zawodnicy, int Punkty) : m_Nazwa(Nazwa), m_Zawodnicy(Zawodnicy), m_Punkty(Punkty) {

}

int Druzyna::Punkty() const {
    return m_Punkty;
}

void Druzyna::Wygrana(){
    m_Punkty += 1;
}
