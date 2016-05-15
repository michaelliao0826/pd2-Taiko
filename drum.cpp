#include "drum.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include "game.h"
#include <QTimer>
#include "time.h"

#include <QDebug>

void Drum::generate()
{
    //create drum
    Drum *hit = new Drum();
    scene()->addItem(hit);
    hit->setPos(480, 85);
    srand(time(NULL));
    hit->drumType = rand()%2;
    if(hit->drumType == 0)
    {
        hit->setPixmap(QPixmap(":/image/red.png"));
    }
    if(hit->drumType == 1)
    {
        hit->setPixmap(QPixmap(":/image/blue.png"));
    }


    //make Drum focusable
    hit->setFlag(QGraphicsItem::ItemIsFocusable);

    //make drum move left per 0.01 sec
    QTimer *timer3 = new QTimer(this);
    connect(timer3, SIGNAL(timeout()), hit, SLOT(move()));
    timer3->start(10);

}

void Drum::move()
{
    //move left 1 pixel
    setPos(x()-1,y());

    //set the drum which is at checkpoint focus
    if(pos().x() < 120 && pos().x() > 98)
    {
        setFocus();
    }

    //delete drum if out of border
    if(pos().x() < 65)
    {
        scene()->removeItem(this);
        delete this;
    }

}
void Drum::keyPressEvent(QKeyEvent *event)
{
    Game *game = new Game();
    if(event->key() == Qt::Key_D && drumType == 0)
    {
        scene()->removeItem(this);
        delete this;
        game->s++;
    }

    if(event->key() == Qt::Key_K && drumType == 1)
    {

        scene()->removeItem(this);
        delete this;
        game->s++;
    }

}
