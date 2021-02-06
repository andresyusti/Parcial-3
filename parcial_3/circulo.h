#ifndef CIRCULO_H
#define CIRCULO_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>

class circulo: public QGraphicsItem
{
private:
    float radio;
    float x;
    float y;

public:
    circulo(float radio_, float x_, float y_);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);
};

#endif // CIRCULO_H
