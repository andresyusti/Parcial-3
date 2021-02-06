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
    float t;
    int cond = 0;
    bool verificar_m = false;


public:
    condiciones();
    void ofensivo_golpe_defensivo(float posox, float posoy, float posdx, float posdy);
    void defensivo_defiende_ofensivo(float posox, float posoy, float posdx, float posdy, float vel_io, float vel_ox, float vel_oy, float tiempo);
    void ofensivo_defiende_defensivo(float vel_ox, float vel_oy, float vel_dx, float vel_dy, float posox, float posoy, float posdx, float posdy, float tiempo);
    void verificar_manual(float angulo_, float velocidad_inicial_, float posox, float posoy, float posdx, float posdy);

    float getVelocidad_inicial() const;
    float getAngulo() const;
    bool getVerificar_m() const;
    float getT() const;
    void setVerificar_m(bool value);
};

#endif // CONDICIONES_H
