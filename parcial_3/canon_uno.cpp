#include "canon_uno.h"

float canon_uno::getX() const
{
    return x;
}

float canon_uno::getY() const
{
    return y;
}

canon_uno::canon_uno(float x_, float y_, float alto_, float ancho_, float rango_)
{
    x = x_;
    y = y_;
    alto = alto_;
    ancho = ancho_;
    rango = rango_;
}

QRectF canon_uno::boundingRect() const
{
    return QRectF(x-ancho/2, y-alto/2, alto, ancho);
}

void canon_uno::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::blue);
    painter->drawRect(boundingRect());
    painter->setBrush(Qt::green);
    painter->drawEllipse(boundingRect().center(), 3, 3);
//    painter->setBrush(Qt::transparent);
//    QPen pain (Qt::black);
//    painter->drawEllipse(boundingRect().center(), rango, rango);

}
