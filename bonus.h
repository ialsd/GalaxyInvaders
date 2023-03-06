#ifndef BONUS_H
#define BONUS_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class bonus: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    bonus();
    int randomColor;
    int flag = 0;
public slots:
    void move();
    void speed();
    void coef();
};

#endif // BONUS_H
