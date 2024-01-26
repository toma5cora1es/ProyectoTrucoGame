#ifndef RONDA_H
#define RONDA_H

#include "gamestate.h"
#include "jugador_ia.h"
#include "jugador_humano.h"
#include <QRandomGenerator>
#include "Jugador.h"

class Ronda : public GameState
{
signals:

public slots:

public:
    Ronda();

    virtual ~Ronda(){};


    // GameState interface
public:
    void updatePuntaje() override;
};

#endif // RONDA_H
