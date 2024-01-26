#include "game.h"

Game::Game(QObject *parent)
    : QObject{parent}
{

}

void Game::AgregarJugadorHumano()
{
    State->AgregarJugadorHumano();
}

void Game::AgregarJugadorDificil()
{
    State->AgregarJugadorIa(GameState::AGRESIVA);
}

void Game::AgregarJugadorFacil()
{
    State->AgregarJugadorIa(GameState::FACIL);
}

void Game::AgregarJugadorAleatorio()
{
    State->AgregarJugadorIa(GameState::ALEATORIA);
}
GameState *Game::getState()
{
    return State;
}
