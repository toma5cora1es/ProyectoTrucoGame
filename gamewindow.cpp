#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "ui_qwmazo.h"


GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent)
{
    SetUpSelection();

    centralwidget = selection ;

    setCentralWidget(centralwidget);

    selection->show() ;
}

void GameWindow::SetUpSelection()
{
    selection =  new PlayerSelection() ;

    connect(selection,&PlayerSelection::HumanVsIaAgresiva,
            this,&GameWindow::GameHumanVsIaAgresiva);

    connect(selection,&PlayerSelection::HumanVsIaFacil,
            this,&GameWindow::GameHumanVsIaFacil);

    connect(selection,&PlayerSelection::IaAgresivaVsIaFacil,
            this,&GameWindow::GameIaAgresivaVsIaFacil );

    connect(selection,&PlayerSelection::IaAgresivaVsIaAleatoria,
            this,&GameWindow::GameIaAgresivaVsIaAleatoria );

    connect(selection,&PlayerSelection::IaFacilVsIaAleatoria,
            this,&GameWindow::GameIaFacilVsIaAleatoria );


}

void GameWindow::GameHumanVsIaAgresiva()
{
    widgetgame = new QWGame();

    selection->hide();

    centralwidget = widgetgame  ;

    TrucoArgentino = new Game();

    TrucoArgentino->AgregarJugadorHumano();

    TrucoArgentino->AgregarJugadorDificil();

    TrucoArgentino->ConnectState();

    widgetgame->ConectarState(TrucoArgentino);

    connect(TrucoArgentino,&Game::TJuegoTerminado,
            this,&GameWindow::GameEndedHumanVsIa);

    TrucoArgentino->ComenzarJuego();

    widgetgame->show();
}

void GameWindow::GameHumanVsIaFacil()
{
    widgetgame = new QWGame();

    selection->hide();

    centralwidget = widgetgame  ;

    TrucoArgentino = new Game();

    TrucoArgentino->AgregarJugadorHumano();

    TrucoArgentino->AgregarJugadorFacil();

    TrucoArgentino->ConnectState();

    widgetgame->ConectarState(TrucoArgentino);

    connect(TrucoArgentino,&Game::TJuegoTerminado,
            this,&GameWindow::GameEndedHumanVsIa);

    TrucoArgentino->ComenzarJuego();

    widgetgame->show();
}

void GameWindow::GameIaAgresivaVsIaFacil()
{
    selection->hide();

    TrucoArgentino = new Game();

    TrucoArgentino->AgregarJugadorDificil();

    TrucoArgentino->AgregarJugadorFacil();

    TrucoArgentino->ConnectState();

    connect(TrucoArgentino,&Game::TJuegoTerminado,
            this,&GameWindow::GameEndedIaVsIa);

    TrucoArgentino->ComenzarJuego();
}

void GameWindow::GameIaAgresivaVsIaAleatoria()
{
    selection->hide();

    TrucoArgentino = new Game();

    TrucoArgentino->AgregarJugadorDificil();

    TrucoArgentino->AgregarJugadorAleatorio();

    TrucoArgentino->ConnectState();

    connect(TrucoArgentino,&Game::TJuegoTerminado,
            this,&GameWindow::GameEndedIaVsIa);

    TrucoArgentino->ComenzarJuego();
}

void GameWindow::GameIaFacilVsIaAleatoria()
{
    selection->hide();

    TrucoArgentino = new Game();

    TrucoArgentino->AgregarJugadorFacil();

    TrucoArgentino->AgregarJugadorAleatorio();

    TrucoArgentino->ConnectState();

    connect(TrucoArgentino,&Game::TJuegoTerminado,
            this,&GameWindow::GameEndedIaVsIa);

    TrucoArgentino->ComenzarJuego();
}


GameWindow::~GameWindow()
{
    delete widgetgame;
    delete selection;
}





void GameWindow::GameEndedHumanVsIa()
{
    delete TrucoArgentino;

    centralwidget = selection ;

    widgetgame->hide();

    delete widgetgame;

    selection->show();
}

void GameWindow::GameEndedIaVsIa()
{
    delete TrucoArgentino;

    selection->show();
}
