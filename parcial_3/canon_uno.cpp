#include "canon_uno.h"

float canon_uno::getX() const
{
    return x;
}

float canon_uno::getY() const
{
    return y;
}

canon_uno::canon_uno(float x_, float y_, float alto_, float ancho_)
{
    x = x_;
    y = y_;
    alto = alto_;
    ancho = ancho_;
}

QRectF canon_uno::boundingRect() const
{
    return QRectF(x-ancho/2, y-alto/2, alto, ancho);
}

void canon_uno::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::red);
    painter->drawRect(boundingRect());
}
