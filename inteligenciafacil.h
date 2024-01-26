#ifndef INTELIGENCIAFACIL_H
#define INTELIGENCIAFACIL_H

#include "modulointeligencia.h"

class InteligenciaFacil : public ModuloInteligencia
{
public:
    InteligenciaFacil();

    // ModuloInteligencia interface
public:
    Carta *SeleccionarCarta() override;
};

#endif // INTELIGENCIAFACIL_H
