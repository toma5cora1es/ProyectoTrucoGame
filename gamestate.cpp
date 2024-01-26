#include "gamestate.h"


Jugador *GameState::ProximoJugador()
{

    for (int i = 0 ; i < jugadores.size() - 1 ; i++) {
        if ( turno == jugadores[i] ){
            return jugadores[i+1] ;
        }
    }

    return jugadores[0] ;
}

void GameState::RepartirCartas()
{
    for (int i = 0 ; i < jugadores.size() ; i++) {
        jugadores[i]->setMano( CartasDeJuego->Repartir() ) ;
    }
}

void GameState::AgregarCartaJugada(Carta *CartaJugada)
{
    Jugador * aux = GetJugadorofCarta(CartaJugada);

    switch (aux->getOrder() ){
    case Jugador::PRIMERO :
        CartasDeJuego->AgregarCartaPRIMERA(CartaJugada);
        break;
    case Jugador::SEGUNDO :
        CartasDeJuego->AgregarCartaSEGUNDA(CartaJugada);
        break;
    case Jugador::TERCERO :
        break;
    case Jugador::CUARTO :
        break;

    }

}

void GameState::printInformacion()
{
    QStringList ListadeAcciones = informacion.split("\n")  ;
    for (int i = 0 ; i < ListadeAcciones.size() ;i++ ){
        qDebug() << ListadeAcciones[i] ;
    }

}

Jugador_Humano *GameState::getHumano()
{
    return Humano;
}



Jugador *GameState::getTurno()
{
    return turno;
}

Jugador *GameState::GanadorMano()
{
    Jugador *Ganador = jugadores[0] ;

    for (int i = 0 ; i < jugadores.size() ; i++) {
        if ( jugadores[i]->getRondasGanadas() > Ganador->getRondasGanadas() )
            Ganador =  jugadores[i] ;
    }

    return Ganador;
}

QString GameState::getOrden(Jugador *jugador)
{
    switch (jugador->getOrder() ){
    case Jugador::PRIMERO :
        return "PRIMER JUGADOR";
        break;
    case Jugador::SEGUNDO :
        return "SEGUNDO JUGADOR";
        break;
    case Jugador::TERCERO :
        return "TERCER JUGADOR";
        break;
    case Jugador::CUARTO :
        return "CUARTO JUGADOR";
        break;
    }
}

QList<Jugador *> GameState::getJugadores()
{
    return jugadores;
}

QList<Carta *> GameState::getJugadas()
{
    return CartasDeJuego->getJugadas();
}

QString GameState::getInformacion()
{
    return informacion;
}

bool GameState::PasarMano()
{
    for (int i = 0 ; i < jugadores.size() ; i++) {
        if ( jugadores[i]->getRondasGanadas() == MEJOR_DE_3 )
            return  true;
    }
    return false;
}

bool GameState::isGameEnded()
{
    for (int i = 0 ; i < jugadores.size() ; i++) {

        int puntaje = jugadores[i]->getPuntaje() ;

        if ( puntaje  >= JUEGO_A_15 ){
            informacion += "Ha ganado " + getOrden(jugadores[i]);
            printInformacion();
            emit TGameEnded();
            return  true;
        }
    }
    return false;
}


Jugador *GameState::GetJugadorofCarta( Carta *AuxCarta )
{
    for (int i = 0 ; i < jugadores.size() ; i++) {
        if ( jugadores[i]->CartaEnMano(AuxCarta) ){
            return  jugadores[i]  ;
        }
    }
    return nullptr ;
}



void GameState::updateState(Carta *CartaJugada)
{
    if (CartaJugada->Activa()) {

        AgregarCartaJugada(CartaJugada);
        informacion += getOrden(GetJugadorofCarta(CartaJugada)) + " jugo la carta " + CartaJugada->getNameCarta() + "\n";
        //Preguntamos si se deben de evaluar las Cartas
        if ( CartasDeJuego->Evaluar() ){

            //chekeamos que ocurra un empate
            if (CartasDeJuego->Empate()){
                //hubo empate
                ProximoTurno = Mano ;
                ProximoTurno->AumentarRondasGanadas();
                informacion += "Gano la Mano " + getOrden(ProximoTurno) + "\n" ;
            } else {
                //no hubo un empate
                Carta *CartaGanadora = CartasDeJuego->MayorCartaRonda();
                Jugador *Ganador = GetJugadorofCarta(CartaGanadora);
                ProximoTurno = Ganador ;
                ProximoTurno->AumentarRondasGanadas();
                informacion += "Gano la Carta : "+ CartaGanadora->getNameCarta() + " de "+ getOrden(ProximoTurno) + "\n" ;
            }
            //        una vez evaluadas las cartas
            //        debemos actualizar la ronda
            CartasDeJuego->ReiniciarCartasJugadas();
            updateRonda();
        } else {
            //No se deben de evaluar las cartas aun
            ProximoTurno = ProximoJugador();
        }

        setTurno(ProximoTurno);
    }
}

void GameState::updateRonda()
{
    if ( PasarMano() ) ProximaMano();
}

void GameState::ProximaMano()
{
    printInformacion();

    informacion  = " -------- \n";

    CartasDeJuego->ReiniciarCartasRepartidas();
    CartasDeJuego->ReiniciarCartasJugadas();

    for (int i = 0 ; i < jugadores.size() ; i++)
        jugadores[i]->setMano( CartasDeJuego->Repartir() );

    Mano = ProximoJugadorMano();

    updatePuntaje();

    for (int i = 0 ; i < jugadores.size() ; i++)
        informacion += getOrden(jugadores[i]) + " tiene puntos : " + QString::number(jugadores[i]->getPuntaje()) + "\n";
    informacion += "  \n" ;

    for (int i = 0 ; i < jugadores.size() ; i++)
        jugadores[i]->ReiniciarRondasGanadas();

}

void GameState::AgregarJugadorHumano()
{
        Jugador_Humano* humano = new Jugador_Humano();
        this->Humano = humano ;
        humano->setOrder(Jugador::PRIMERO);
        this->jugadores.append(Humano);
}

void GameState::AgregarJugadorIa(DIFICULTAD dificultad)
{
    Jugador_IA* IA = new Jugador_IA();

    switch ( jugadores.size() ) {
    case 0 :
        IA->setOrder(Jugador::PRIMERO);
        break;
    case 1 :
        IA->setOrder(Jugador::SEGUNDO);
        break;
    case 2 :
        IA->setOrder(Jugador::TERCERO);
        break;
    case 3 :
        IA->setOrder(Jugador::SEGUNDO);
        break;
    }

    switch ( dificultad ) {
    case AGRESIVA :
        IA->setInteligenciaAgresiva();
        break;
    case FACIL :
        IA->setInteligenciaFacil();
        break;
    case ALEATORIA :
        IA->setInteligenciaAleatoria();
        break;
    }

     this->jugadores.append(IA);
}



void GameState::IniciarJuego()
{
    EtapaActual = PRIMERA ;
    RepartirCartas();
    Mano = turno ;
    setTurno(jugadores[QRandomGenerator::global()->bounded(jugadores.size())]);
}

Jugador *GameState::ProximoJugadorMano()
{
    for (int i = 0 ; i < jugadores.size() - 1 ; i++) {
        if ( Mano == jugadores[i] ){
            return jugadores[i+1] ;
        }
    }

    return jugadores[0] ;
}








