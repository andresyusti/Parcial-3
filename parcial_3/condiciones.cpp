#include "condiciones.h"

condiciones::condiciones()
{

}

void condiciones::ofensivo_golpe_defensivo(float posox, float posoy, float posdx, float posdy)
{
    cond = 0;
    for (velocidad_inicial = 0;velocidad_inicial < 400 ;velocidad_inicial +=1){
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

void condiciones::defensivo_defiende_ofensivo(float posox, float posoy, float posdx, float posdy, float vel_io, float angulo_o)
{
    float posbalaox, posbalaoy, velox, veloy, aux;
    cond = 0;
    for(velocidad_aux = velocidad_inicial; velocidad_aux < 400; velocidad_aux++){
        velox = vel_io*cos(angulo_o*3.14/180);
        veloy = vel_io*sin(angulo_o*3.14/180);
        for(angulo = 0; angulo < 180; angulo++){
            velbx = velocidad_aux*cos((270 - angulo)*3.14/180);
            velby = velocidad_aux*sin((270 - angulo)*3.14/180);
            for(t=2; ; t+=0.1){
                posbalaox = posox+velox*t;
                posbalaoy = posoy+veloy*t-(0.5*9.81*t*t);

                posbx = posdx+velbx*(t-2);
                posby = posdy+velby*(t-2)-(0.5*9.81*(t-2)*(t-2));
                if (sqrt(pow((posdx - posbalaox),2)+pow((posdy - posbalaoy),2)) <= (0.05*posdx)) break;
                if (sqrt(pow((posbalaox - posbx), 2) + pow((posbalaoy - posby), 2)) <= (0.025*(posdx))){
                    cond = 1;
                    break;
                }
            }
            if (cond == 1) break;
        }
        if (cond == 1) break;
    }
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
