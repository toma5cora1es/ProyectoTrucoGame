#include "Jugador.h"


void Jugador::QuitarCartaDeMano(Carta *C)
{
    for (int i = 0 ; i < Mano.size() ; i ++ ){
        if( Mano[i]->equal( *C ) ){
            Mano.remove(i);
        }
    }

}

bool Jugador::CartaEnMano(Carta *C)
{
     for (int i = 0 ; i < RegistroMano.size() ; i++ ){
        if ( C->equal( *RegistroMano[i] ) ){
            return true ;
        }
    }
    return false ;
}

QList<Carta *> Jugador::getMano()
{
   return Mano;
}

void Jugador::setMano(QList<Carta *> newMano)
{
    RegistroMano.clear();

    for (int i = 0 ; i < newMano.size() ; i++ ){
        RegistroMano.append(newMano[i]);        
    }

    Mano = newMano;
}

Jugador::JUGADOR_ORDER Jugador::getOrder()
{
    return order;
}

void Jugador::setOrder(JUGADOR_ORDER newOrder)
{
    order = newOrder;
}

Jugador::JUGADOR_TYPE Jugador::getType()
{
    return type;
}

int Jugador::getPuntaje()
{
    return Puntaje;
}

void Jugador::setPuntaje(int newPuntaje)
{
    Puntaje = newPuntaje;
}

int Jugador::getRondasGanadas() const
{
    return RondasGanadas;
}

void Jugador::setRondasGanadas(int newRondasGanadas)
{
    RondasGanadas = newRondasGanadas;
}



