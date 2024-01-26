#include <QApplication>
#include "gamewindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GameWindow Game;
    Game.show();
    return a.exec();
}
