#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include "game.h"
#include "playerselection.h"
#include "qwgame.h"

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = nullptr);
    ~GameWindow();
    void SetUpSelection();

public slots:
    void GameHumanVsIaAgresiva();
    void GameHumanVsIaFacil();

    void GameIaAgresivaVsIaFacil();
    void GameIaAgresivaVsIaAleatoria();
    void GameIaFacilVsIaAleatoria();

    void GameEndedIaVsIa();
    void GameEndedHumanVsIa();

private:
    PlayerSelection * selection ;
    QWidget *centralwidget;
    QWGame * widgetgame ;
    Game * TrucoArgentino ;
};

#endif // GAMEWINDOW_H
