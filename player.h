#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class player: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    player();
    void keyPressEvent(QKeyEvent *event);
    int speed = 7;
public slots://для того, чтобы исп сигналы и слоты
             //класс должен быть производным от QObject + макрос
    void spawnStone();
    void spawnAlien();
    void collide();
    void spawnBonus();
};

#endif // PLAYER_H
