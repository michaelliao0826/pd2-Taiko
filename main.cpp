#include "mainwindow.h"
#include <QApplication>
#include "game.h"

Game *game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game = new Game();
    game->show();
    game->displayMainMenu();

    /*MainWindow w;
    w.show();*/

    return a.exec();
}
