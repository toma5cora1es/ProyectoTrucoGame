#ifndef MAZO_H
#define MAZO_H

#include "Jugador.h"
#include "carta.h"
#include <QList>
#include <QDebug>
#include <QObject>

#include <QRandomGenerator>

class Mazo: public QObject
{
    Q_OBJECT

public:
    Mazo();

    virtual ~Mazo(){

    };

    QList<Carta*> Repartir();

    void ReiniciarCartasRepartidas() ;

    void ReiniciarCartasJugadas() ;

    void AgregarCartaJugada(Carta * carta ) ;

    void AgregarCartaPRIMERA(Carta * carta ) ;

    void AgregarCartaSEGUNDA(Carta * carta ) ;

    Carta *MayorCartaRonda();

    bool CartaRepartida(Carta *carta);

    bool Evaluar();

    bool Empate();



    QList<Carta *> getJugadas();

private:

    QList<Carta*> CartasTotales;

    QList<Carta*>  Repartidas;

    QList<Carta*>  Jugadas;

    Carta *CartaVacia = new Carta(Carta::CartaVacia);
};

#endif // MAZO_H
