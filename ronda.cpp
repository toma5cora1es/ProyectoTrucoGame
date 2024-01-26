#include "ronda.h"

Ronda::Ronda()
{

    this->CartasDeJuego = new Mazo() ;
    this->CartasDeJuego->ReiniciarCartasJugadas();
    this->CartasDeJuego->ReiniciarCartasRepartidas();

}

void Ronda::
updatePuntaje()
{
    Jugador *Ganador = GanadorMano();
    Ganador->AumentarPuntaje(1);
}
