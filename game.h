#ifndef GAME_H
#define GAME_H

#include "gamestate.h"
#include "ronda.h"
#include <QObject>

class Game : public QObject
{
    Q_OBJECT
public:
    explicit Game(QObject *parent = nullptr);

    void ConnectState(){

        QList<Jugador*> jugadores = State->getJugadores();

        for (int i = 0 ; i < jugadores.size() ; i++){

            if ( jugadores[i]->getType() == Jugador::IA ){
                connect(State,&GameState::TTurno,
                        jugadores[i],&Jugador::RTurno) ;
            }

            connect(jugadores[i], &Jugador::TCartaJugada
                    ,this,&Game::UpdateState );
        }

        connect(State,&GameState::TGameEnded,
                this,&Game::RGameEnded);

    };

    void ComenzarJuego(){
        State->IniciarJuego();
        emit StateUpdated(State);
    };

    void AgregarJugadorHumano();

    void AgregarJugadorDificil();

    void AgregarJugadorFacil();

    void AgregarJugadorAleatorio();


    GameState *getState();


signals:
    void StateUpdated( GameState *newState);
    void TJuegoTerminado();

public slots:

    void UpdateState(Carta *carta){
        State->updateState(carta);
        emit StateUpdated(State);
    };

    void RGameEnded(){
        emit TJuegoTerminado();
    };



private:
    GameState *State = new Ronda() ;

};

#endif // GAME_H
