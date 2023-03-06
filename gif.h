#ifndef GIF_H
#define GIF_H
#include <QObject>
#include <QWidget>
#include <QMovie>
#include <QLabel>
#include <QGraphicsProxyWidget>

class gif: public QWidget
{
    Q_OBJECT
public:
    gif(qreal x, qreal y);
    QGraphicsProxyWidget *proxy;
    QLabel *label;
    QMovie *movie;
public slots:
    void removeGif();
};

#endif // GIF_H
