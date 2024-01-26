#include "qwgame.h"
#include "ui_qwgame.h"

QWGame::QWGame(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QWGame)
{
    ui->setupUi(this);
}

void QWGame::ConectarState(Game *newgame)
{
    ui->widgetMazo->Connectar(newgame);

}

QWGame::~QWGame()
{
    delete ui;
}
