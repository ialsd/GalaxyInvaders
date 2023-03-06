#ifndef BUTTON_H
#define BUTTON_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

class button: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    button(QString name, int w, int h);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    QGraphicsTextItem* text;
signals:
    void clicked();
};

#endif // BUTTON_H
