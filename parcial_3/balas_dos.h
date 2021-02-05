#ifndef BALAS_DOS_H
#define BALAS_DOS_H
#include "fisicas.h"

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>

class bala_dos: public QGraphicsItem
{
private:
    float angulo;
    float velocidad_inicial;
    float radio;
    float tiempo = 0;

    fisicas * fisicas_bala;

public:
    bala_dos(float angulo_, float velocidad_inicial_, float radio_);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);

    void actualizar_bala(float poscx, float poscy, float limite_y);
    fisicas *getFisicas_bala() const;
    void setTiempo(float value);
    float getTiempo() const;
};

#endif // BALAS_DOS_H
