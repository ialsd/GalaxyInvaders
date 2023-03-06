#ifndef ALIEN_H
#define ALIEN_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class alien: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    alien();
public slots:
    void move();
    void shoot();
};

#endif // ALIEN_H
