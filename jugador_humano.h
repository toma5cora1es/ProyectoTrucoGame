#ifndef JUGADOR_HUMANO_H
#define JUGADOR_HUMANO_H
#include <QDebug>
#include "Jugador.h"

class Jugador_Humano : public Jugador
{
    Q_OBJECT

public slots:

    void RCarta(Carta *CartaClikeada){
        CartaJugada = CartaClikeada ;        

        QuitarCartaDeMano(CartaJugada);

        emit TCartaJugada(CartaJugada);

        CartaJugada = CartaVacia;
    };

public:
    Jugador_Humano(){
        this->type = HUMANO;
    }

    virtual ~Jugador_Humano();

    void JugarCarta() override{

    };

};

#endif // JUGADOR_HUMANO_H
