#include "circulo.h"

circulo::circulo(float radio_, float x_, float y_)
{
    radio = radio_;
    x = x_;
    y = y_;
}

QRectF circulo::boundingRect() const
{
    return QRectF(x-1*radio, y-1*radio, 2*radio, 2*radio);
}

void circulo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::transparent);
    QPen pain (Qt::black);
    painter->drawEllipse(boundingRect());
}
