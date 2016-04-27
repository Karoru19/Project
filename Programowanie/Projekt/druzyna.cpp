#include "druzyna.h"

Druzyna::Druzyna(QString Nazwa, QList<Zawodnik> Zawodnicy, int Punkty) : m_Nazwa(Nazwa), m_Zawodnicy(Zawodnicy), m_Punkty(Punkty) {

}

int Druzyna::Punkty() const {
    return m_Punkty;
}

void Druzyna::Wygrana(){
    int punkty = m_Punkty;
    punkty += 3;
    m_Punkty = punkty;
}

void Druzyna::Przegrana(){

}
