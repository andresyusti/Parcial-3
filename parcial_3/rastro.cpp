#include "rastro.h"

rastro::rastro(int color_)
{
    color = color_;
}

QRectF rastro::boundingRect() const
{
    return QRectF(-1*3, -1*3, 2*3, 2*3);
}

void rastro::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(color == 1){
        painter->setBrush(Qt::green);
    }
    if(color == 2){
        painter->setBrush(Qt::red);
    }
    if(color == 3){
        painter->setBrush(Qt::black);
    }
    painter->drawEllipse(boundingRect());
}
