#include "ball.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "stone.h"
#include "game.h"
#include "alien.h"
#include <QMovie>
#include <QLabel>
#include "gif.h"
#include "bonus.h"

extern game *Game;

ball::ball(bool Color): QObject(), QGraphicsPixmapItem()
{
    if (Color == 0)
    {
        setPixmap(QPixmap(":/image/ball.png"));
    }
    else
    {
        setPixmap(QPixmap(":/image/redball.png"));
    }
    flag = Color;
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

void ball::move()
{
    QList<QGraphicsItem*> colliding_items = collidingItems();//список элементов, которые сталкиваются с ball
    for (int i = 0; i < colliding_items.size(); ++i)
    {
        if (flag == 0 && (typeid(*colliding_items[i]) == typeid(stone) || typeid(*colliding_items[i]) == typeid(alien)))
        {
            Game->sc->increase();
            gif *boom = new gif(colliding_items[i]->x(), colliding_items[i]->y());

            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }
        else if (flag == 1 && (typeid(*colliding_items[i]) == typeid(player)))
        {
            Game->hl->decrease();
            scene()->removeItem(this);
            delete this;
            return;
        }
    }
    if (flag == 0)
    {
        setPos(x(),y() - 5);
        if (y() < 0)
        {
            scene()->removeItem(this);
            delete this;
        }
    }
    else
    {
        if (Game->pl->x() > x())
        {
            setPos(x() + Game->pl->x()/600,y() + Game->pl->y()/800 + 5);
        }
        else
        {
            setPos(x() - Game->pl->x()/600 - 1, y() + Game->pl->y()/800 + 5);

        }
        if (y() > 800)
        {
            scene()->removeItem(this);
            delete this;
        }
    }
}
