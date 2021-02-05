#ifndef CONDICIONES_H
#define CONDICIONES_H
#include <math.h>

class condiciones
{
private:
    float velocidad_inicial = 0;
    float angulo = 0;
    float posbx;
    float posby;
    float velbx;
    float velby;


public:
    condiciones();
    void ofensivo_golpe_defensivo(float posox, float posoy, float posdx, float posdy);
    void defensivo_defiende_ofensivo();
    void ofensivo_defiende_defensivo();
    float getVelocidad_inicial() const;
    float getAngulo() const;
};

#endif // CONDICIONES_H
