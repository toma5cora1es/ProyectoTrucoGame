#ifndef CARTA_H
#define CARTA_H

#include <QString>
#include <QObject>

class Carta
{
public:

    enum StateCarta{
        ACTIVA,
        INACTIVA
    };

    enum CartasEspeciales{
     CartaDadaVuelta,
     CartaVacia,
     CartaVisible
    };

    Carta();

    Carta(int palo, int numero);

    Carta(CartasEspeciales exception);

    virtual ~Carta();

    QString getNameCarta();

    int getPalo();

    int getNumero();

    bool equal( Carta c);

    int getValorEnvido();

    int getValorTruco();

    bool Activa();

    bool isDadaVuelta();

    bool isVacia();


private :
    int palo ;
    int numero ;
    StateCarta estado;
    CartasEspeciales exception;
};

#endif // CARTA_H
