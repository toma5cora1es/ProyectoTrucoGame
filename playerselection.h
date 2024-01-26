#ifndef PLAYERSELECTION_H
#define PLAYERSELECTION_H

#include "game.h"
#include <QWidget>
#include <QDebug>

namespace Ui {
class PlayerSelection;
}

class PlayerSelection : public QWidget
{
    Q_OBJECT

public:
    explicit PlayerSelection(QWidget *parent = nullptr);
    ~PlayerSelection();

public slots:
    void SelectGameHumanVsIaAgresiva();
    void SelectGameHumanVsIaFacil();
    void SelectGameIaAgresivaVsIaFacil();
    void SelectGameIaAgresivaVsIaAleatoria();
    void SelectGameIaFacilVsIaAleatoria();

signals:
    void HumanVsIaAgresiva();
    void HumanVsIaFacil();
    void IaAgresivaVsIaFacil();
    void IaAgresivaVsIaAleatoria();
    void IaFacilVsIaAleatoria();

private:
    Ui::PlayerSelection *ui;

};

#endif // PLAYERSELECTION_H
