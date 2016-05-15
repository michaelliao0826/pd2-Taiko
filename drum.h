#ifndef DRUM_H
#define DRUM_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QLabel>
#include "game.h"

class Drum : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:

private slots:
    void generate();
    void move();
    void keyPressEvent(QKeyEvent *event);

private:
    int drumType = 0;
    //0 represent red / 1 represent blue


};


#endif // DRUM_H
