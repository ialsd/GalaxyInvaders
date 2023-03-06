#ifndef HEALTH_H
#define HEALTH_H


#include <QGraphicsTextItem>

class health: public QGraphicsTextItem
{
public:
    health();
    void decrease();
    void increase();
    int getHealth();
    int Health;
};
#endif // HEALTH_H
