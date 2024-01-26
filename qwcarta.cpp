#include "qwcarta.h"
#include "ui_qwcarta.h"

QWCarta::QWCarta(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QWCarta)
{
    ui->setupUi(this);
    this->setStateVacia();
}

QWCarta::~QWCarta()
{
    delete ui;
    delete CartaVacia;
}

void QWCarta::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    QImage imagen;

    imagen.load(ImagePath);

    painter.drawImage(this->rect(), imagen);
}

void QWCarta::mouseReleaseEvent(QMouseEvent *event)
{
    if( State->Activa()
            && ( event->button() == Qt::LeftButton )
            && rect().contains( event->pos() )
            && EsMiTurno() )
        emit CartaClicked(State);

}

void QWCarta::setState(Carta *newState)
{
    if (State == newState)
        return;
    State = newState;

    this->setPath();

    update();
}

void QWCarta::setStateVacia()
{
    setState( CartaVacia ) ;
}

void QWCarta::setGame(GameState *newGame)
{
    if (Game == newGame)
        return;
    Game = newGame;
}
