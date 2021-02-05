#ifndef BALA_UNO_H
#define BALA_UNO_H
#include "fisicas.h"

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>

class bala_uno: public QGraphicsItem
{
private:
    float angulo;
    float velocidad_inicial;
    float radio = 20;

    fisicas * fisicas_bala;

public:
    bala_uno(float angulo_, float velocidad_inicial_);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);

    void actualizar_bala(float poscx, float poscy, float tiempo, float limite_y);
    fisicas *getFisicas_bala() const;
};

#endif // BALA_UNO_H
