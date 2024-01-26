#ifndef MODULOINTELIGENCIA_H
#define MODULOINTELIGENCIA_H


#include "carta.h"


class ModuloInteligencia
{
public:

    virtual ~ModuloInteligencia(){

    }

    virtual Carta * SeleccionarCarta() = 0;

    Carta *CartaMasAlta();

    Carta *CartaMasBaja();

    void setMano( QList<Carta *> &newMano);
    void setRegistroMano( QList<Carta *> &newRegistroMano);
    void setPuntaje(int newPuntaje);
    void setRondasGanadas(int newRondasGanadas);

protected:
    QList<Carta*> Mano ;

    QList<Carta*> RegistroMano ;

    int Puntaje = 0;

    int RondasGanadas = 0 ;
};

#endif // MODULOINTELIGENCIA_H
