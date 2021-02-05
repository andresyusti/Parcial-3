#include "balas_dos.h"

bala_dos::bala_dos(float angulo_, float velocidad_inicial_, float radio_)
{
    radio = radio_;
    angulo = angulo_;
    velocidad_inicial = velocidad_inicial_;
    fisicas_bala = new fisicas;
}

fisicas *bala_dos::getFisicas_bala() const
{
    return fisicas_bala;
}

void bala_dos::setTiempo(float value)
{
    tiempo = value;
}

float bala_dos::getTiempo() const
{
    return tiempo;
}

QRectF bala_dos::boundingRect() const
{
    return QRectF(-1*radio, -1*radio, 2*radio, 2*radio);
}

void bala_dos::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::blue);
    painter->drawEllipse(boundingRect());
}

void bala_dos::actualizar_bala(float poscx, float poscy, float limite_y)
{
    fisicas_bala->actualizar_fisicas(velocidad_inicial, angulo, poscx, poscy, tiempo);
    setPos(fisicas_bala->getPosx(), limite_y - fisicas_bala->getPosy());
}
