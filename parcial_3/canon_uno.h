#ifndef CANON_UNO_H
#define CANON_UNO_H
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>

class canon_uno: public QGraphicsItem
{
private:
    float x;
    float y;
    float alto;
    float ancho;

public:
    canon_uno(float x_, float y_, float alto_, float ancho_);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);

    float getX() const;
    float getY() const;
};

#endif // CANON_UNO_H
