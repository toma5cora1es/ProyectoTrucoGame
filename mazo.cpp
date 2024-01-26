#include "mazo.h"

Mazo::Mazo()
{
    for (int i = 1 ; i <= 4 ; i++) {
        for (int j = 1 ; j <= 12 ; j++) {
            Carta * auxCarta = new Carta(i,j);
            CartasTotales.append(auxCarta) ;
        }

    }
}


bool Mazo::CartaRepartida(Carta *carta)
{
    for (int i = 0 ; i < Repartidas.size() ; i++ )
        if ( carta->equal( *Repartidas[i] ) ) return true ;

    return false ;
}

bool Mazo::Evaluar()
{

    int ContadorCartasActivas = 0;

    for (int i = 0 ; i < Jugadas.size(); i++) {
        if ( Jugadas[i]->Activa() ) ContadorCartasActivas++;
    }

    if ( ContadorCartasActivas == 2 ) return true;


 return false ;
}

bool Mazo::Empate()
{
    QList<Carta*> cartasjugadas =  Jugadas ;

    for (int i = 0 ; i < cartasjugadas.size() - 1 ; i++) {

        if ( cartasjugadas[i]->getValorTruco() != cartasjugadas[i+1]->getValorTruco() ){
            return false ;
        }
    }

    return true;
}

 QList<Carta *> Mazo::getJugadas()
{
    return Jugadas;
}

QList<Carta*> Mazo::Repartir()
{
    Carta * AuxCarta  = nullptr ;

    QList<Carta*> AuxRepartir ;

    while ( AuxRepartir.size() < 3 ) {

        bool ask = true ;

        // bounded solicita un numero aleatorio
        AuxCarta = CartasTotales[QRandomGenerator::global()->bounded(48)] ;

        while ( ask ){

            // carta en mesa devuelve true si la carta esta en  la "mesa"
            // primero preguntamos por esta condicion , ya que si elegimos
            // una carta que ya habiamos elegido con el bounded debemos elegir de nuevo
            bool CartaNoRepetida =  !CartaRepartida(AuxCarta) ;
            bool No8 =  AuxCarta->getNumero() != 8  ;
            bool No9 =  AuxCarta->getNumero() != 9  ;

            if ( CartaNoRepetida && No8 && No9 ){
                AuxRepartir.append(AuxCarta);
                Repartidas.append(AuxCarta);
                ask = false ;
            } else {
                AuxCarta = CartasTotales[QRandomGenerator::global()->bounded(48)] ;
            }

        }

    }
    return AuxRepartir ;

}

void Mazo::ReiniciarCartasRepartidas()
{
    // lo que yo quiero es eliminar las referencias a las cartas en mesa
    // ya que estaran almacenadas en otra lista

    Repartidas.clear();
}

void Mazo::ReiniciarCartasJugadas()
{
    Jugadas.clear();
}

void Mazo::AgregarCartaJugada(Carta *carta)
{
    Jugadas.append(carta);
}

void Mazo::AgregarCartaPRIMERA(Carta *carta)
{

    if (Jugadas.size() == 0 ) {
        Jugadas.append(carta);
    }

    if (Jugadas.size() == 2 ) {
        Jugadas.removeFirst();
        Jugadas.prepend(carta);
    }

}

void Mazo::AgregarCartaSEGUNDA(Carta *carta)
{
    if (Jugadas.size() == 0 ) {
       Jugadas.append(CartaVacia);
       Jugadas.append(carta);
    }

    if (Jugadas.size() == 1 ) {
        Jugadas.append(carta);
    }

}

Carta *Mazo::MayorCartaRonda()
{
    QList<Carta*> cartasjugadas =  Jugadas ;

    Carta *Ganadora = cartasjugadas[0] ;

    for (int i = 1 ; i < cartasjugadas.size() ; i++) {

        if (cartasjugadas[i]->getValorTruco() > Ganadora->getValorTruco() ){
            Ganadora = cartasjugadas[i] ;
        }
    }

    return Ganadora ;
}


