#include "generator.h"

Generator::Generator() {
    QFile *plik;
    QTextStream *in;
    plik = new QFile(":/osoba/imiona/Resources/imiona_m.txt");
    plik->open(QIODevice::ReadOnly);
    in = new QTextStream(plik);
    while(!in->atEnd()){
        m_ImieMeskie.append(in->readLine());
    }
    delete in;
    plik->close();
    delete plik;
    plik = new QFile(":/osoba/nazwiska/Resources/nazwiska_m.txt");
    plik->open(QIODevice::ReadOnly);
    in = new QTextStream(plik);
    while(!in->atEnd()){
        m_NazwiskoMeskie.append(in->readLine());
    }
    delete in;
    plik->close();
    delete plik;
    plik = new QFile(":/osoba/imiona/Resources/imiona_z.txt");
    plik->open(QIODevice::ReadOnly);
    in = new QTextStream(plik);
    while(!in->atEnd()){
        m_ImieZenskie.append(in->readLine());
    }
    delete in;
    plik->close();
    delete plik;
    plik = new QFile(":/osoba/nazwiska/Resources/nazwiska_z.txt");
    plik->open(QIODevice::ReadOnly);
    in = new QTextStream(plik);
    while(!in->atEnd()){
        m_NazwiskoZenskie.append(in->readLine());
    }
    delete in;
    plik->close();
    delete plik;
    plik = new QFile(":/druzyny/Resources/przymiotniki.txt");
    plik->open(QIODevice::ReadOnly);
    in = new QTextStream(plik);
    while(!in->atEnd()){
        m_Przymiotnik.append(in->readLine());
    }
    delete in;
    plik->close();
    delete plik;
    plik = new QFile(":/druzyny/Resources/rzeczowniki.txt");
    plik->open(QIODevice::ReadOnly);
    in = new QTextStream(plik);
    while(!in->atEnd()){
        m_Rzeczownik.append(in->readLine());
    }
    delete in;
    plik->close();
    delete plik;
    plik = new QFile(":/druzyny/Resources/te_trzecie.txt");
    plik->open(QIODevice::ReadOnly);
    in = new QTextStream(plik);
    while(!in->atEnd()){
        m_NWO.append(in->readLine());
    }
    delete in;
    plik->close();
    delete plik;
}

Osoba Generator::GenerujOsobe()
{
    int x;
    int y;

    QString Imie;
    QString Nazwisko;

    int r = qrand()%2;

    if (r == 0) {
        x = qrand()%m_ImieMeskie.size();
        y = qrand()%m_NazwiskoMeskie.size();
        Imie = m_ImieMeskie.at(x);
        Nazwisko = m_NazwiskoMeskie.at(y);
    }
    else {
        x = qrand()%m_ImieZenskie.size();
        y = qrand()%m_NazwiskoZenskie.size();
        Imie = m_ImieZenskie.at(x);
        Nazwisko = m_NazwiskoZenskie.at(y);
    }
    return Osoba(Imie, Nazwisko);
}

Zawodnik Generator::GenerujZawodnika(int Numer) {
    Osoba pom = GenerujOsobe();
    return Zawodnik(pom.Imie(), pom.Nazwisko(), Numer);
}

SedziaGlowny Generator::GenerujSedziegoGlownego() {
    SedziaGlowny pom = GenerujOsobe();
    return SedziaGlowny(pom.Imie(), pom.Nazwisko());
}

SedziaPomocniczy Generator::GenerujSedziegoPomocniczego() {
    SedziaPomocniczy pom = GenerujOsobe();
    return SedziaPomocniczy(pom.Imie(), pom.Nazwisko());
}

Druzyna Generator::GenerujDruzyne() {
    int x;
    int y;
    int z;

    QString Przymiotnik;
    QString Rzeczownik;
    QString NWM;

    QString NazwaDruzyny;

    x = qrand()%m_Przymiotnik.size();
    y = qrand()%m_Rzeczownik.size();
    z = qrand()%m_NWO.size();

    Przymiotnik = m_Przymiotnik.at(x);
    Rzeczownik = m_Rzeczownik.at(y);
    NWM = m_NWO.at(z);

    if (Rzeczownik.at(Rzeczownik.length()-1) == 'a'){
        NazwaDruzyny = Przymiotnik + "a " + Rzeczownik + " " + NWM;
    }
    else if (Rzeczownik.at(Rzeczownik.length()-1) == 'o'){
        NazwaDruzyny = Przymiotnik + "e " + Rzeczownik + " " + NWM;
    }
    else {
        NazwaDruzyny = Przymiotnik + "y " + Rzeczownik + " " + NWM;
    }

    QList <Zawodnik> Zawodnicy;

    for (int i = 1; i <= 5; i++){
        Zawodnicy.append(GenerujZawodnika(i));
    }

    return Druzyna (NazwaDruzyny, Zawodnicy);
}
