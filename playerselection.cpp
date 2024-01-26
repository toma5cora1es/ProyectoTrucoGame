#include "playerselection.h"
#include "ui_playerselection.h"

PlayerSelection::PlayerSelection(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlayerSelection)
{
    ui->setupUi(this);
}

PlayerSelection::~PlayerSelection()
{
    delete ui;
}

void PlayerSelection::SelectGameHumanVsIaAgresiva()
{
    emit HumanVsIaAgresiva();
}

void PlayerSelection::SelectGameHumanVsIaFacil()
{
    emit HumanVsIaFacil();
}

void PlayerSelection::SelectGameIaAgresivaVsIaFacil()
{
    emit IaAgresivaVsIaFacil();
}

void PlayerSelection::SelectGameIaAgresivaVsIaAleatoria()
{
    emit IaAgresivaVsIaAleatoria();
}

void PlayerSelection::SelectGameIaFacilVsIaAleatoria()
{
    emit IaFacilVsIaAleatoria();
}


