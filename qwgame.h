#ifndef QWGAME_H
#define QWGAME_H

#include <QWidget>
#include "game.h"

namespace Ui {
class QWGame;
}

class QWGame : public QWidget
{
    Q_OBJECT

public:
    explicit QWGame(QWidget *parent = nullptr);

    void ConectarState(Game* newgame);

    ~QWGame();

private:
    Ui::QWGame *ui;
};

#endif // QWGAME_H
