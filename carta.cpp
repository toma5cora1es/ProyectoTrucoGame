#include "carta.h"


Carta::Carta()
{
}


Carta::~Carta()
{

}


Carta::Carta(int palo, int numero) : palo(palo),
    numero(numero) , estado(ACTIVA), exception(CartaVisible)
{
}

Carta::Carta(CartasEspeciales exception):
    palo(0),numero(0) , estado(INACTIVA), exception(exception)
{
}


QString Carta::getNameCarta()
{
    if (exception == CartaDadaVuelta ) {
    return "carta-dada-vuelta.png";
    }

    if (exception == CartaVacia) {
    return "carta-vacia.png";
    }

    QString aux = "" ;

    switch( palo )
    {
    case 1:
        aux = aux + "espada" ;
        break ;
    case 2 :
        aux = aux + "basto" ;
        break ;
    case 3 :
        aux = aux + "oro" ;
        break ;
    case 4 :
        aux = aux + "copa" ;
        break ;
    }

    aux =  QString::number(numero) + "-" + aux + ".png" ;

    return aux ;
}


bool Carta::equal(Carta c)
{
    if ( ( numero == c.getNumero() ) && ( palo == c.getPalo() ) ) {
        return true ;
    } else {
        return false ;
    } ;
}

int Carta::getValorEnvido()
{
    if ( numero < 10 ) {return 20 + numero ;}else{return 20;}
}

int Carta::getValorTruco()
{
    switch( numero )
    {
    case 1: // ancho

        switch( palo )
        {
        case 1: // espada
            return 100 ;
            break ;
        case 2 : // basto
            return 80 ;
            break ;
        case 3: // oro
            return 20 ;
            break ;
        case 4 :// copa
            return 20 ;
            break ;
        }

        break ;
    case 7 :// siete

        switch( palo )
        {
        case 1: // espada
            return 70 ;
            break ;
        case 2 : // basto
            return numero ;
            break ;
        case 3: // oro
            return 60 ;
            break ;
        case 4 :// copa
            return numero ;
            break ;
        }

        break ;
    case 3 : // los 3
        return 30 ; // devuelvo un valor arbitrario
        break ;
    case 2 :
        return 30 ; // devuelvo un valor arbitrario
        break ;

    default:
        return numero ;
    }

    return 0 ;
}

bool Carta::Activa()
{
    if ( estado == ACTIVA){
        return true;
    }
    return false ;
}

bool Carta::isDadaVuelta()
{
    if ( exception == CartaDadaVuelta){
        return true;
    }
    return false ;
}

bool Carta::isVacia()
{
    if ( exception == CartaVacia){
        return true;
    }
    return false ;
}


int Carta::getPalo()
{
    return palo;
}

int Carta::getNumero()
{
    return numero;
}





