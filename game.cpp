#include "game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "stone.h"
#include "alien.h"
#include <QBrush>
#include <QImage>
#include "button.h"
#include "bonus.h"

game::game()
{
    scene = new QGraphicsScene();//создание сцены, нужно стобы управлять элементами
    scene->setSceneRect(0,0,600,800);//прямоугольник, ограничивающий сцену
    setBackgroundBrush(QBrush(QImage(":/image/background.png")));//фон

    setScene(scene);//уст сцену
    setFixedSize(600,800);//фикс размер
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//убирает полосы прокрутки
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void game::end()
{
    QGraphicsTextItem *textsc = new QGraphicsTextItem;
    textsc->setPlainText(QString("Your score: ") + QString::number(sc->getScore()));
    textsc->setDefaultTextColor(Qt::white);
    textsc->setFont(QFont("times",25));
    textsc->setPos(160, 375);
    scene->addItem(textsc);

    QGraphicsTextItem *text = new QGraphicsTextItem;
    text->setPlainText(QString("Press ESC to menu"));
    text->setDefaultTextColor(Qt::white);
    text->setFont(QFont("times",25));
    text->setPos(130, 410);
    scene->addItem(text);
}

void game::menu()
{
    scene->clear();

    button *play = new button(QString("Play"), 100, 50);
    play->setPos(275, 370);
    QObject::connect(play, SIGNAL(clicked()), this, SLOT(startGame()));
    scene->addItem(play);

    button *stats = new button(QString("High Score"), 100, 50);
    stats->setPos(275, 445);
    QObject::connect(stats, SIGNAL(clicked()), this, SLOT(showStat()));
    scene->addItem(stats);

    button *exit = new button(QString("Exit"), 100, 50);
    exit->setPos(275, 520);
    QObject::connect(exit, SIGNAL(clicked()), this, SLOT(close()));
    scene->addItem(exit);
    show();
}

void game::startGame()
{
    scene->clear();

    pl = new player();
    pl->setPos(300,750);//уст поз
    pl->setFlag(QGraphicsItem::ItemIsFocusable);//без флага нельзя получить фокус
    pl->setFocus();//фокус ввода с клав
    scene->addItem(pl);//доб на сцену

    QTimer *timerst = new QTimer();//создание таймера для появления камней
    QObject::connect(timerst,SIGNAL(timeout()),pl,SLOT(spawnStone()));
    timerst->start(2000);

    QTimer *timeral = new QTimer();
    QObject::connect(timeral,SIGNAL(timeout()),pl,SLOT(spawnAlien()));
    timeral->start(7000);

    QTimer *timerbn = new QTimer();
    QObject::connect(timerbn,SIGNAL(timeout()),pl,SLOT(spawnBonus()));
    timerbn->start(30000);

    hl = new health();
    hl->setPos(hl->x(),hl->y()+25);
    scene->addItem(hl);

    sc = new score();
    sc->setPos(sc->x(),sc->y());
    scene->addItem(sc);

    button *esc = new button("ESC", 30, 30);
    esc->setPos(0, 55);
    QObject::connect(esc, SIGNAL(clicked()), this, SLOT(menu()));
    scene->addItem(esc);

    show();
}

void game::showStat()
{
    scene->clear();

    QGraphicsTextItem *textsc = new QGraphicsTextItem;
    textsc->setPlainText(QString("High Score: ") + QString::number(highScore));
    textsc->setDefaultTextColor(Qt::white);
    textsc->setFont(QFont("times",25));
    textsc->setPos(160, 375);
    scene->addItem(textsc);

    button *esc = new button("ESC", 30, 30);
    esc->setPos(0, 0);
    QObject::connect(esc, SIGNAL(clicked()), this, SLOT(menu()));
    scene->addItem(esc);
    show();
}

void game::close()
{
    delete scene;
    delete this;
}
