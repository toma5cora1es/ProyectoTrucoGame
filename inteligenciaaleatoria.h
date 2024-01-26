#ifndef INTELIGENCIAALEATORIA_H
#define INTELIGENCIAALEATORIA_H

#include "modulointeligencia.h"
#include <QRandomGenerator>

class InteligenciaAleatoria : public ModuloInteligencia
{
public:
    InteligenciaAleatoria();


    // ModuloInteligencia interface
public:
    Carta *SeleccionarCarta() override;
};

#endif // INTELIGENCIAALEATORIA_H
