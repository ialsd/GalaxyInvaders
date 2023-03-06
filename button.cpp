#include "button.h"
#include <QGraphicsTextItem>
#include <QBrush>

button::button(QString name, int w, int h)
{
    setRect(0, 0, w, h);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkCyan);
    setBrush(brush);

    text = new QGraphicsTextItem(name,this);
    int xPos = rect().width()/2 - text->boundingRect().width()/2;
    int yPos = rect().height()/2 - text->boundingRect().height()/2;
    text->setPos(xPos,yPos);
}
void button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked();
}
