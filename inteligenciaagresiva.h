#ifndef INTELIGENCIAAGRESIVA_H
#define INTELIGENCIAAGRESIVA_H

#include "modulointeligencia.h"

class InteligenciaAgresiva : public ModuloInteligencia
{
public:
    InteligenciaAgresiva();

public:
    Carta *SeleccionarCarta() override{
        return CartaMasAlta();
    };

};

#endif // INTELIGENCIAAGRESIVA_H
