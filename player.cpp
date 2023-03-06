#include "player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "ball.h"
#include "stone.h"
#include "alien.h"
#include "game.h"
#include <QTimer>
#include "bonus.h"

extern game *Game;

player::player(): QGraphicsPixmapItem()//уст растр изобр игрока
{
    setPixmap(QPixmap(":/image/player.png"));
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(collide()));
    timer->start(50);
}

void player::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_A)
    {
        if (x() > 10 && Game->hl->getHealth() > 0)
        {
            setPos(x() - speed, y());
        }
    }
    else if (event->key() == Qt::Key_D)
    {
        if (x() + 40 < 600 && Game->hl->getHealth() > 0)
        {
            setPos(x() + speed, y());
        }
    }
    else if (event->key() == Qt::Key_Space)
    {
        if (Game->hl->getHealth() > 0)
        {
            ball *bl = new ball(0);
            bl->setPos(x() + 15,y());
            scene()->addItem(bl);
        }
    }
}

void player::collide()
{
    QList<QGraphicsItem*> colliding_items = collidingItems();
    for (int i = 0; i < colliding_items.size(); i++)
    {
        if (typeid(*colliding_items[i]) == typeid(stone) || typeid(*colliding_items[i]) == typeid(alien))
        {
            Game->hl->decrease();
            scene()->removeItem(colliding_items[i]);
            delete colliding_items[i];
            return;
        }
    }
}

void player::spawnBonus()
{
    bonus *bn = new bonus();
    scene()->addItem(bn);
}

void player::spawnStone()
{
    stone *st = new stone();
    scene()->addItem(st);
}

void player::spawnAlien()
{
    alien *pl = new alien();
    scene()->addItem(pl);
}

