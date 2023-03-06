#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "player.h"
#include "health.h"
#include "score.h"


class game: public QGraphicsView
{
    Q_OBJECT
public:
    game();
    QGraphicsScene *scene;
    player *pl;
    health *hl;
    score *sc;
    void end();
    int highScore = 0;
public slots:
    void startGame();
    void showStat();
    void close();
    void menu();
};

#endif // GAME_H
