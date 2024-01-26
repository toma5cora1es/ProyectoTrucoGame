#include "jugador_ia.h"


Jugador_IA::~Jugador_IA()
{
    
}

void Jugador_IA::setInteligenciaAgresiva()
{
   delete modulo;
   modulo = new InteligenciaAgresiva();
}

void Jugador_IA::setInteligenciaFacil()
{    
    delete modulo;
    modulo = new InteligenciaFacil();
}

void Jugador_IA::setInteligenciaAleatoria()
{
    delete modulo;
    modulo = new InteligenciaAleatoria();
    
}

