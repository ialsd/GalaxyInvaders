#include "gif.h"
#include <QMovie>
#include <QLabel>
#include <QGraphicsProxyWidget>
#include "game.h"
#include <QGraphicsScene>
extern game *Game;
gif::gif(qreal x, qreal y)
{
    movie = new QMovie(":/image/boom.gif");
    label = new QLabel();
    label->setGeometry(x,y,32,32);
    label->setMovie(movie);
    label->setAttribute(Qt::WA_NoSystemBackground);
    movie->start();
    proxy = Game->scene->addWidget(label);
    connect(movie, SIGNAL(finished()), this, SLOT(removeGif()));
}

void gif::removeGif()
{
    Game->scene->removeItem(proxy);
    delete label;
    delete movie;
    delete this;
}
