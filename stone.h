#ifndef STONE_H
#define STONE_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class stone: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    stone();
public slots:
    void move();
};

#endif // STONE_H
