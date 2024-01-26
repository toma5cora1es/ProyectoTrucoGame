#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "Jugador.h"
#include "jugador_ia.h"
#include "jugador_humano.h"
#include "botones.h"
#include "mazo.h"
#include <QObject>
#include <QRandomGenerator>

#define JUEGO_A_15 3
#define MEJOR_DE_3 2

class GameState : public QObject
{
    Q_OBJECT

signals:
    void TTurno(Jugador::JUGADOR_ORDER orden);
    void TGameEnded();

public:

    enum DIFICULTAD { AGRESIVA, FACIL, ALEATORIA };

    virtual ~GameState(){
       delete CartasDeJuego;
    };

    virtual void updatePuntaje() = 0;

    void updateState( Carta * CartaJugada );

    void updateRonda();

    void ProximaMano();

    void AgregarJugadorHumano();

    void AgregarJugadorIa(DIFICULTAD dificultad);

    void IniciarJuego();

    void RepartirCartas();

    void AgregarCartaJugada(Carta *CartaJugada);

    void printInformacion();

    Jugador *ProximoJugadorMano();

    Jugador *ProximoJugador();

    Jugador *GetJugadorofCarta( Carta *AuxCarta );

    Jugador *getTurno();

    Jugador *GanadorMano();

    Jugador_Humano *getHumano();

    QList<Jugador*> getJugadores();

    QList<Carta*> getJugadas();

    QString getOrden(Jugador* jugador);

    QString getInformacion();

    bool isGameEnded();

    bool PasarMano();

protected:

    enum RONDA {PRIMERA , SEGUNDA, TERCERA};

    void setTurno( Jugador* nextTurno ){

        if ( !isGameEnded() ){
            turno = nextTurno ;

            if ( turno->getType() == Jugador::IA ) {
                emit TTurno(turno->getOrder());
            }
        }
    };

    Mazo *CartasDeJuego ;

    QList<Jugador*> jugadores ;    

    Jugador * Mano ;

    Jugador * turno ;

    Jugador * ProximoTurno ;

    Jugador_Humano * Humano ;

    RONDA EtapaActual;

    QString informacion = "" ;

};

#endif // GAMESTATE_H
