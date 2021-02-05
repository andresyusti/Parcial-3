#include "condiciones.h"

condiciones::condiciones()
{

}

void condiciones::ofensivo_golpe_defensivo(float posox, float posoy, float posdx, float posdy)
{
    float t;
    int cond = 0;

    for (;velocidad_inicial < 400 ;velocidad_inicial +=1){
        for (angulo=0; angulo < 90; angulo++){
            velbx = velocidad_inicial*cos(angulo*3.14/180);
            velby = velocidad_inicial*sin(angulo*3.14/180);
            for(t=0;;t+=0.1){
                posbx = posox+velbx*t;
                posby = posoy+velby*t-(0.5*9.81*t*t);
                if (posby < 0) break;
                if (sqrt(pow((posdx - posbx), 2)+pow((posdy - posby), 2)) <= (0.05*posdx)){
                    cond = 1;
                    break;
                }
            }
            if (cond == 1) break;
        }
        if (cond == 1) break;
    }
}

void condiciones::defensivo_defiende_ofensivo()
{

}

void condiciones::ofensivo_defiende_defensivo()
{

}

float condiciones::getVelocidad_inicial() const
{
    return velocidad_inicial;
}

float condiciones::getAngulo() const
{
    return angulo;
}
