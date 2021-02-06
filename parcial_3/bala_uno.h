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
    float radio;
    float tiempo = 0;
    int rastro = 1;

    fisicas * fisicas_bala;

public:
    explicit bala_uno(float angulo_, float velocidad_inicial_, float radio_);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);

    void actualizar_bala(float poscx, float poscy, float limite_y);
    fisicas *getFisicas_bala() const;
    void setTiempo(float value);
    float getTiempo() const;
    float getAngulo() const;
    float getVelocidad_inicial() const;
    int getRastro() const;
    void setRastro(int value);

};

#endif // BALA_UNO_H
