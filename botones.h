#ifndef BOTONES_H
#define BOTONES_H

#include "boton.h"
#include <QList>

class Botones
{
public:

    Botones();    

    virtual ~Botones();

    QList< Boton* > getBotones();

    void EstadoInicial();
    void EstadoTruco();
    void EstadoReTruco();
    void EstadoValeCuatro();
    void EstadoDesicion();

private:
    QList< Boton* >  ListaBotonesVisibles ;

    QList< Boton* >  BotonesCompletos ;


};

#endif // BOTONES_H
