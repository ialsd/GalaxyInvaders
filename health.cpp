#include "health.h"
#include <QFont>
#include "game.h"

extern game *Game;

health::health(): QGraphicsTextItem()
{
    Health = 3;
    setPlainText(QString("Health:  ") + QString::number(Health));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times", 16));
}

void health::decrease()
{
    if (Health > 0)
    {
        Health--;
        if (Health == 0)
        {
            Game->end();
        }
        setPlainText(QString("Health:  ") + QString::number(Health));
    }
}

void health::increase()
{
    Health++;
    setPlainText(QString("Health:  ") + QString::number(Health));
}

int health::getHealth()
{
    return Health;
}
