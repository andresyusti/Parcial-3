#include "canon_uno.h"

canon_uno::canon_uno(float x_, float y_, float alto_, float ancho_)
{
    x = x_;
    y = y_;
    alto = alto_;
    ancho = ancho_;
}

QRectF canon_uno::boundingRect() const
{
    return QRectF(0, 100, 70, 70);
}

void canon_uno::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::blue);
    painter->drawRect(boundingRect());
}
