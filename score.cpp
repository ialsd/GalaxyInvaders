#include "score.h"
#include <QFont>
#include "game.h"

extern game *Game;

score::score(): QGraphicsTextItem()
{
    Score = 0;
    setPlainText(QString("Score: ") + QString::number(Score));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",16));
}

void score::increase()
{
    if (Game->hl->getHealth() > 0)
    {
        Score += coef;
        setPlainText(QString("Score: ") + QString::number(Score));
    }
    if (Score > Game->highScore)
    {
        Game->highScore = Score;
    }
}

int score::getScore()
{
    return Score;
}
