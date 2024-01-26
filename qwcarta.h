#ifndef QWCARTA_H
#define QWCARTA_H

#include <QWidget>
#include <QDir>
#include <QDebug>
#include <QPainter>
#include <QMouseEvent>

#include "carta.h"
#include "gamestate.h"

namespace Ui {
class QWCarta;
}

class QWCarta : public QWidget
{
    Q_OBJECT

public:
    explicit QWCarta(QWidget *parent = nullptr);

    ~QWCarta();

    void paintEvent(QPaintEvent * event) override;

    void mouseReleaseEvent(QMouseEvent *event)override;

    void setGame(GameState *newGame);

    void setState(Carta *newState);

    void setStateVacia();


signals:
    void StateChanged();

    void CartaClicked(Carta * carta);

public slots:
    void updateState(GameState *State)
    {
       this->Game = State;
       update();
    }

private:

    Ui::QWCarta *ui;

    GameState * Game ;

    Carta *State;

    Carta * CartaVacia = new Carta ( Carta::CartaVacia );

    QString ImagePath ;

    bool EsMiTurno(){
        if( Game->getTurno()->CartaEnMano( this->State) ) {
            return true;
        };
        return false;
    }

    void setPath(){

        QDir direccion( QDir::currentPath() ) ;

        direccion.cdUp();

        direccion.cd("PROYECTO_TRUCO");

        direccion.cd("IMAGENES_CARTAS");

        ImagePath = direccion.path() + "/" + State->getNameCarta() ;

    }



};

#endif // QWCARTA_H
