#-------------------------------------------------
#
# Project created by QtCreator 2016-04-22T14:53:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Projekt
TEMPLATE = app

INCLUDEPATH += include/

SOURCES += main.cpp\
        mainwindow.cpp \
    src/druzyna.cpp \
    src/generator.cpp \
    src/mecz.cpp \
    src/osoba.cpp \
    src/sedzia.cpp \
    src/sedziaglowny.cpp \
    src/zawodnik.cpp \
    src/meczdruzynowy.cpp \
    src/przeciaganieliny.cpp \
    src/pilka.cpp \
    src/dwaognie.cpp \
    src/siatkowka.cpp \
    src/siatkowkaplazowa.cpp \
    src/sedziapomocniczy.cpp \
    src/listaspotkan.cpp \
    src/listasedziow.cpp \
    src/listadruzyn.cpp \
    src/zawody.cpp \
    dodajdruzynedialog.cpp \
    usunsedziegodialog.cpp \
    usundruzynedialog.cpp \
    dodajsedziegodialog.cpp \
    generatordruzynydialog.cpp \
    generatorsedziegodialog.cpp \
    aboutusdialog.cpp

HEADERS  += mainwindow.h \
    include/druzyna.h \
    include/generator.h \
    include/mecz.h \
    include/osoba.h \
    include/sedzia.h \
    include/sedziaglowny.h \
    include/zawodnik.h \
    include/meczdruzynowy.h \
    include/przeciaganieliny.h \
    include/pilka.h \
    include/dwaognie.h \
    include/siatkowka.h \
    include/siatkowkaplazowa.h \
    include/sedziapomocniczy.h \
    include/listaspotkan.h \
    include/listasedziow.h \
    include/listadruzyn.h \
    include/zawody.h \
    dodajdruzynedialog.h \
    usunsedziegodialog.h \
    usundruzynedialog.h \
    dodajsedziegodialog.h \
    generatordruzynydialog.h \
    generatorsedziegodialog.h \
    aboutusdialog.h

FORMS    += mainwindow.ui \
    dodajdruzynedialog.ui \
    usunsedziegodialog.ui \
    usundruzynedialog.ui \
    dodajsedziegodialog.ui \
    generatordruzynydialog.ui \
    generatorsedziegodialog.ui \
    aboutusdialog.ui

RESOURCES += \
    resources.qrc
