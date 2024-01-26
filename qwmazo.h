#ifndef QWMAZO_H
#define QWMAZO_H

#include "game.h"
#include "gamestate.h"
#include "qwcarta.h"
#include <QWidget>
#include <QDir>
#include <QDebug>
#include <QPainter>


namespace Ui {
class QWMazo;
}

class QWMazo : public QWidget
{
    Q_OBJECT

public:
    explicit QWMazo(QWidget *parent = nullptr);

    ~QWMazo();

    void paintEvent(QPaintEvent * event) override;

    void Connectar(Game * newGame);


public slots:

    void updateState(GameState *state);

private:
    Ui::QWMazo *ui;

    GameState * State ;

    QString ImagePath ;

    QList<QWCarta*> Humano;

    QList<QWCarta*> Ia;

    QList<QWCarta*> Jugadas;


    void setPath(){

        QDir direccion( QDir::currentPath() ) ;

        direccion.cdUp();

        direccion.cd("PROYECTO_TRUCO");

        direccion.cd("IMAGENES_TABLERO");

        QString path = "/IMAGEN-TABLERO.jpeg" ;

        ImagePath = direccion.path() + path ;
    }


};

#endif // QWMAZO_H
