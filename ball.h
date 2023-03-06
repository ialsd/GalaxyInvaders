#ifndef BALL_H
#define BALL_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class ball: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    ball(bool Color);
    bool flag;
public slots:
    void move();
};

#endif // BALL_H
