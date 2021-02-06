#ifndef RASTRO_H
#define RASTRO_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>

class rastro: public QGraphicsItem
{
private:
    int color;

public:
    rastro(int color_);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);
};

#endif // RASTRO_H
