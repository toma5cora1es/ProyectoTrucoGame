QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Jugador.cpp \
    boton.cpp \
    botones.cpp \
    carta.cpp \
    envido.cpp \
    game.cpp \
    gamestate.cpp \
    inteligenciaagresiva.cpp \
    inteligenciaaleatoria.cpp \
    inteligenciafacil.cpp \
    jugador_humano.cpp \
    jugador_ia.cpp \
    main.cpp \
    gamewindow.cpp \
    mazo.cpp \
    modulointeligencia.cpp \
    playerselection.cpp \
    qwboton.cpp \
    qwcarta.cpp \
    qwgame.cpp \
    qwmazo.cpp \
    ronda.cpp

HEADERS += \
    Jugador.h \
    boton.h \
    botones.h \
    carta.h \
    envido.h \
    game.h \
    gamestate.h \
    gamewindow.h \
    inteligenciaagresiva.h \
    inteligenciaaleatoria.h \
    inteligenciafacil.h \
    jugador_humano.h \
    jugador_ia.h \
    mazo.h \
    modulointeligencia.h \
    playerselection.h \
    qwboton.h \
    qwcarta.h \
    qwgame.h \
    qwmazo.h \
    ronda.h

FORMS += \
    gamewindow.ui \
    playerselection.ui \
    qwboton.ui \
    qwcarta.ui \
    qwgame.ui \
    qwmazo.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
