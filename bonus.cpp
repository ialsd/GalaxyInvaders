#include "bonus.h"
#include <QTimer>
#include <stdlib.h>
#include "game.h"
#include <QGraphicsScene>
#include "ball.h"

extern game *Game;

bonus::bonus(): QObject(), QGraphicsPixmapItem()
{
    if (Game->hl->getHealth() != 0)
    {
        randomColor = rand() % 3;
        if (randomColor == 0)
        {
            setPixmap(QPixmap(":/image/bonus_speed.png"));
        }
        else if (randomColor == 1)
        {
            setPixmap(QPixmap(":/image/bonus_x2.png"));
        }
        else
        {
            setPixmap(QPixmap(":/image/bonus_life.png"));
        }
        int randomNumber = rand() % 500;
        setPos(randomNumber, 0);

        QTimer *timer = new QTimer(this);
        connect(timer,SIGNAL(timeout()),this,SLOT(move()));
        timer->start(100);
    }
}

void bonus::move()
{
    QList<QGraphicsItem*> colliding_items = collidingItems();
    for (int i = 0; i < colliding_items.size(); i++)
    {
        if (typeid(*colliding_items[i]) == typeid(player))
        {
            flag = 1;
            this->setPos(0, 810);
            if (randomColor == 0)
            {
                Game->pl->speed = 14;
                QTimer *timer = new QTimer(this);
                connect(timer,SIGNAL(timeout()),this,SLOT(speed()));
                timer->start(15000);
            }
            else if (randomColor == 1)
            {
                Game->sc->coef = 2;
                QTimer *timer = new QTimer(this);
                connect(timer,SIGNAL(timeout()),this,SLOT(coef()));
                timer->start(15000);
            }
            else if (randomColor == 2)
            {
                Game->hl->increase();
                scene()->removeItem(this);
                delete this;
            }
        }
    }
    setPos(x(), y() + 5);
    if (flag == 0 && y() > 800)
    {
        scene()->removeItem(this);
        delete this;
    }
}

void bonus::speed()
{
    Game->pl->speed = 7;
    scene()->removeItem(this);
    delete this;
}

void bonus::coef()
{
    Game->sc->coef = 1;
    scene()->removeItem(this);
    delete this;
}
