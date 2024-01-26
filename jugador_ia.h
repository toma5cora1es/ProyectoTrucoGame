#ifndef JUGADOR_IA_H
#define JUGADOR_IA_H

#include "Jugador.h"
#include "modulointeligencia.h"
#include "inteligenciaagresiva.h"
#include "inteligenciafacil.h"
#include "inteligenciaaleatoria.h"

class Jugador_IA : public Jugador
{
    Q_OBJECT

public:   
    Jugador_IA(){
        this->type = IA;
    }

    virtual ~Jugador_IA();

    void setInteligenciaAgresiva();

    void setInteligenciaFacil();

    void setInteligenciaAleatoria();


    void ActualizarEstado()
    {
        modulo->setMano( Mano);
        modulo->setRegistroMano( RegistroMano);
        modulo->setPuntaje(Puntaje);
        modulo->setRondasGanadas(RondasGanadas);
    }

    Carta * SeleccionarCarta()
    {
        return modulo->SeleccionarCarta();
    };

    void JugarCarta() override
    {
        ActualizarEstado();
        CartaJugada = SeleccionarCarta();
    };

protected:
   ModuloInteligencia * modulo = new InteligenciaAgresiva() ;
};

#endif // JUGADOR_IA_H
