#include "bala_uno.h"

bala_uno::bala_uno(float angulo_, float velocidad_inicial_)
{
    angulo = angulo_;
    velocidad_inicial = velocidad_inicial_;
    fisicas_bala = new fisicas;
}

QRectF bala_uno::boundingRect() const
{
    return QRectF(-1*radio, -1*radio, 2*radio, 2*radio);
}

void bala_uno::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::blue);
    painter->drawEllipse(boundingRect());
}

void bala_uno::actualizar_bala(float poscx, float poscy, float tiempo, float limite_y)
{
    fisicas_bala->actualizar_fisicas(velocidad_inicial, angulo, poscx, poscy, tiempo);
    setPos(fisicas_bala->getPosx(), limite_y - fisicas_bala->getPosy());
}