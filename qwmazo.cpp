#include "qwmazo.h"
#include "ui_qwmazo.h"

QWMazo::QWMazo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QWMazo)
{
    ui->setupUi(this);
    this->setPath();

    Humano.append(ui->widget);
    Humano.append(ui->widget_2);
    Humano.append(ui->widget_3);

    Jugadas.append(ui->widget_4);
    Jugadas.append(ui->widget_5);

    Ia.append(ui->widget_6);
    Ia.append(ui->widget_7);
    Ia.append(ui->widget_8);
}

QWMazo::~QWMazo()
{
    delete ui;
}

void QWMazo::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    QImage imagen;

    imagen.load(ImagePath);

    painter.drawImage(this->rect(), imagen);
}

void QWMazo::Connectar(Game *game)
{
    State = game->getState() ;

    connect(game,&Game::StateUpdated,
            this, &QWMazo::updateState);

    Jugador_Humano *humano = State->getHumano();

    for (int i = 0 ; i < Humano.size() ; i ++ )
        connect(Humano[i] , &QWCarta::CartaClicked,
                humano, &Jugador_Humano::RCarta);


}

void QWMazo::updateState(GameState *state)
{
    State = state ;

    ui->textEdit->clear();
    ui->textEdit->setText(State->getInformacion());

    QList<Carta*> CartasHumano = State->getHumano()->getMano() ;

    for (int i = 0 ; i < Humano.size() ; i ++ ){
        Humano[i]->setStateVacia() ;
                Humano[i]->setGame(State);

    }

    for (int i = 0 ; i < CartasHumano.size() ; i ++ )
        Humano[i]->setState( CartasHumano[i] ) ;


    QList<Carta*> CartasJugadas = State->getJugadas();

    for (int i = 0 ; i < Jugadas.size() ; i ++ ){
        Jugadas[i]->setStateVacia();
        Jugadas[i]->setGame(State);
    }

    for (int i = 0 ; i < CartasJugadas.size() ; i ++ )
        Jugadas[i]->setState( CartasJugadas[i] ) ;


    QList<Carta*> CartasIa = State->getJugadores()[1]->getMano() ;

    for (int i = 0 ; i < Ia.size() ; i ++ ){
        Ia[i]->setStateVacia() ;
        Ia[i]->setGame(State);
    }

    for (int i = 0 ; i < CartasIa.size() ; i ++ )
        Ia[i]->setState( CartasIa[i] ) ;

}

