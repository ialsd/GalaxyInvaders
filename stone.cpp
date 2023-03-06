#include "stone.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include "game.h"

extern game *Game;

stone::stone(): QObject(), QGraphicsPixmapItem()//наследуемся от QObject
                                                //для того, чтобы исп метод connect
{
    if (Game->hl->getHealth() != 0)
    {
        int randomNumber = rand() % 500;
        setPos(randomNumber, 0);
        setPixmap(QPixmap(":/image/stone.png"));

        QTimer *timer = new QTimer(this);
        connect(timer,SIGNAL(timeout()),this,SLOT(move()));
        timer->start(100);
    }
}

void stone::move()
{
    setPos(x(), y() + 2);
    if (y() > 800)
    {
        Game->hl->decrease();
        scene()->removeItem(this);
        delete this;
    }
}
