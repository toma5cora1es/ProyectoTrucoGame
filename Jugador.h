#ifndef JUGADOR_H
#define JUGADOR_H

#include "carta.h"
#include <QList>
#include <QObject>
#include <QDebug>

class Jugador : public QObject
{
    Q_OBJECT


public:

    enum JUGADOR_TYPE { IA,HUMANO };

    enum JUGADOR_ORDER { PRIMERO , SEGUNDO,TERCERO,CUARTO};

    virtual ~Jugador(){
        delete CartaVacia;
    };

    QList<Carta *> getMano();

    virtual void JugarCarta() = 0;

    void QuitarCartaDeMano(Carta * C);

    bool CartaEnMano(Carta * C);

    void setMano( QList<Carta *> newMano);

    JUGADOR_ORDER getOrder();
    void setOrder(JUGADOR_ORDER newOrder);

    JUGADOR_TYPE getType();

    void ReiniciarRondasGanadas(){
        setRondasGanadas(0);
    }

    void AumentarRondasGanadas(){
        setRondasGanadas( getRondasGanadas() + 1 );
    }

    void AumentarPuntaje(int newPuntaje ){
        setPuntaje( getPuntaje() + newPuntaje );
    }

    int getPuntaje() ;
    void setPuntaje(int newPuntaje);

    int getRondasGanadas() const;
    void setRondasGanadas(int newRondasGanadas);

signals:
    void TCartaJugada(Carta* CartaJugada);

public slots:

    void RTurno(JUGADOR_ORDER order)
    {
        if ( this->order == order ){
            JugarCarta();

            QuitarCartaDeMano(CartaJugada);

            emit TCartaJugada(CartaJugada);
        }
    }

protected:

    Carta* CartaVacia = new Carta(Carta::CartaVacia);

    Carta * CartaJugada = CartaVacia;

    QList<Carta*> Mano ;

    QList<Carta*> RegistroMano ;

    int Puntaje = 0;

    int RondasGanadas = 0 ;

    JUGADOR_ORDER order ;

    JUGADOR_TYPE type ;


};





#endif // JUGADOR_H
