#include "modulointeligencia.h"


Carta *ModuloInteligencia::CartaMasAlta()
{
    Carta *Alta = Mano[0] ;

    for (int i = 0 ; i < Mano.size() ; i++) {
        if ( Mano[i]->getValorTruco() > Alta->getValorTruco() )
            Alta =  Mano[i] ;
    }

    return Alta;
}

Carta *ModuloInteligencia::CartaMasBaja()
{
    Carta *Baja = Mano[0] ;

    for (int i = 0 ; i < Mano.size() ; i++) {
        if ( Mano[i]->getValorTruco() < Baja->getValorTruco() )
            Baja =  Mano[i] ;
    }

    return Baja;
}

void ModuloInteligencia::setMano( QList<Carta *> &newMano)
{
    Mano = newMano;
}

void ModuloInteligencia::setRegistroMano( QList<Carta *> &newRegistroMano)
{
    RegistroMano = newRegistroMano;
}

void ModuloInteligencia::setPuntaje(int newPuntaje)
{
    Puntaje = newPuntaje;
}

void ModuloInteligencia::setRondasGanadas(int newRondasGanadas)
{
    RondasGanadas = newRondasGanadas;
}
