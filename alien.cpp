#include "alien.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include "game.h"
#include "ball.h"

extern game *Game;

alien::alien(): QObject(), QGraphicsPixmapItem()
{
    if (Game->hl->getHealth() != 0)
    {
        int randomNumber = rand() % 500;
        setPos(randomNumber, 0);
        setPixmap(QPixmap(":/image/alien.png"));

        QTimer *timermove = new QTimer(this);
        connect(timermove,SIGNAL(timeout()),this,SLOT(move()));
        timermove->start(50);

        QTimer *timershoot = new QTimer(this);
        connect(timershoot,SIGNAL(timeout()),this,SLOT(shoot()));
        timershoot->start(4000);
    }
}

void alien::move()
{
    setPos(x(), y() + 2);
    if (y() > 800)
    {
        Game->hl->decrease();
        scene()->removeItem(this);
        delete this;
    }
}

void alien::shoot()
{
    ball *bl = new ball(1);
    bl->setPos(x() + 15, y() + 32);
    scene()->addItem(bl);
}
