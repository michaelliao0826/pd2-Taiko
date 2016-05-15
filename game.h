#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QLabel>
#include "drum.h"

class Game : public QGraphicsView
{
    Q_OBJECT
public:
    Game(QWidget *parent = NULL);

    void displayMainMenu();
    void finishPage();

    QGraphicsScene *scene;
    int s = 0;
public slots:
    void start();
private slots:
    void startGame();
    void timeChange();
    void returnMainMenu();
private:
    QLabel *timeLeft = new QLabel();
    QLabel *getScore = new QLabel();
    int t = 30;
};

#endif // GAME_H
