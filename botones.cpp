#include "botones.h"


Botones::Botones()
{
    BotonesCompletos.append( new Boton( "ELEGIR TRUCO" , Qt:: green  ) ) ;
    BotonesCompletos.append( new Boton( "TRUCO" , Qt:: red) ) ;
    BotonesCompletos.append( new Boton( "VALE CUATRO" , Qt:: cyan ) ) ;
    BotonesCompletos.append( new Boton( "ELEGIR ENVIDO" , Qt:: yellow ) ) ;
    BotonesCompletos.append( new Boton( "REAL ENVIDO" , Qt:: blue  ) ) ;
    BotonesCompletos.append( new Boton( "FALTA ENVIDO" , Qt:: lightGray) ) ;
    BotonesCompletos.append( new Boton( "FLOR" , Qt:: darkGreen ) ) ;
    BotonesCompletos.append( new Boton( "ME VOY AL MAZO" , Qt:: darkMagenta  ) ) ;
    BotonesCompletos.append( new Boton( "QUIERO" , Qt:: magenta ) ) ;
    BotonesCompletos.append( new Boton( "NO QUIERO" , Qt:: darkYellow ) ) ;
    BotonesCompletos.append( new Boton( "RE TRUCO" , Qt:: red) ) ;
    BotonesCompletos.append( new Boton( "VALE TRUCO" , Qt:: red) ) ;
}

Botones::~Botones()
{
}


void Botones::EstadoInicial( )
{
    /**/ListaBotonesVisibles.clear();
    /*elegir truco*/ListaBotonesVisibles.append( BotonesCompletos[0] ) ;
    /*elegir envido*/ListaBotonesVisibles.append( BotonesCompletos[3] ) ;
    /*me voy al mazo*/ListaBotonesVisibles.append( BotonesCompletos[7] ) ;

}

void Botones::EstadoTruco()
{
    /**/ListaBotonesVisibles.clear();
    /*elegir QUIERO*/ListaBotonesVisibles.append( BotonesCompletos[8] ) ;
    /*elegir NO QUIERO*/ListaBotonesVisibles.append( BotonesCompletos[9] ) ;
     /*elegir VALE CUATRO*/ListaBotonesVisibles.append( BotonesCompletos[10] ) ;

}

void Botones::EstadoReTruco()
{
    /**/ListaBotonesVisibles.clear();
    /*elegir QUIERO*/ListaBotonesVisibles.append( BotonesCompletos[8] ) ;
    /*elegir NO QUIERO*/ListaBotonesVisibles.append( BotonesCompletos[9] ) ;
    /*elegir VALE CUATRO*/ListaBotonesVisibles.append( BotonesCompletos[11] ) ;

}

void Botones::EstadoValeCuatro()
{
    /**/ListaBotonesVisibles.clear();
    /*elegir QUIERO*/ListaBotonesVisibles.append( BotonesCompletos[8] ) ;
    /*elegir NO QUIERO*/ListaBotonesVisibles.append( BotonesCompletos[9] ) ;

}


void Botones::EstadoDesicion()
{
    /**/ListaBotonesVisibles.clear();
    /*elegir QUIERO*/ListaBotonesVisibles.append( BotonesCompletos[8] ) ;
    /*elegir NO QUIERO*/ListaBotonesVisibles.append( BotonesCompletos[9] ) ;

}


