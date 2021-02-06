#include "bala_uno.h"

float bala_uno::getAngulo() const
{
    return angulo;
}

float bala_uno::getVelocidad_inicial() const
{
    return velocidad_inicial;
}

bala_uno::bala_uno(float angulo_, float velocidad_inicial_, float radio_)
{
    radio = radio_;
    angulo = angulo_;
    velocidad_inicial = velocidad_inicial_;
    fisicas_bala = new fisicas;
}

fisicas *bala_uno::getFisicas_bala() const
{
    return fisicas_bala;
}

void bala_uno::setTiempo(float value)
{
    tiempo = value;
}

float bala_uno::getTiempo() const
{
    return tiempo;
}

QRectF bala_uno::boundingRect() const
{
    return QRectF(-1*radio, -1*radio, 2*radio, 2*radio);
}

void bala_uno::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::red);
    painter->drawEllipse(boundingRect());
    painter->setBrush(Qt::green);
    painter->drawEllipse(boundingRect().center(), 3, 3);
}

void bala_uno::actualizar_bala(float poscx, float poscy, float limite_y)
{
    fisicas_bala->actualizar_fisicas(velocidad_inicial, angulo, poscx, poscy, tiempo);
    setPos(fisicas_bala->getPosx(), limite_y - fisicas_bala->getPosy());
    QGraphicsItem::update();
}
