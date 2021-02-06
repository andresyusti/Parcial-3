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

void condiciones::defensivo_defiende_ofensivo(float posox, float posoy, float posdx, float posdy, float vel_io, float vel_ox, float vel_oy)
{
    float posbalaox, posbalaoy;
    cond = 0;
    for(velocidad_inicial = vel_io; velocidad_inicial < 400; velocidad_inicial++){
        for(angulo = 0; angulo < 180; angulo++){
            velbx = velocidad_inicial*cos((270 - angulo)*3.14/180);
            velby = velocidad_inicial*sin((270 - angulo)*3.14/180);
            for(t=2; ; t+=0.1){
                posbalaox = posox+vel_ox*t;
                posbalaoy = posoy+vel_oy*t-(0.5*9.81*t*t);

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

void condiciones::ofensivo_defiende_defensivo(float vel_ox, float vel_oy, float vel_dx, float vel_dy, float posox, float posoy, float posdx, float posdy)
{
    cond = 0;
    float posbalaox, posbalaoy, posbaladx, posbalady;
    for(velocidad_inicial = 0; velocidad_inicial < 400; velocidad_inicial++){
        for(angulo = 0; angulo < 90; angulo++){
            velbx = velocidad_inicial*cos(angulo*3.14/180);
            velby = velocidad_inicial*sin(angulo*3.14/180);
            for(t = 3; ; t += 0.1){
                //Aqui saco las posiciones de las tres balas
                posbalaox = posox+vel_ox*t;                             //Primera bala ofensiva
                posbalaoy = posoy+vel_oy*t-(0.5*9.81*t*t);

                posbaladx = posdx+vel_dx*(t-2);                         //Bala defensiva
                posbalady = posdy+vel_dy*(t-2)-(0.5*9.81*(t-2)*(t-2));

                posbx = posox+velbx*(t-3);                              //Segunda bala ofensiva
                posby = posoy+velby*(t-3)-(0.5*9.81*(t-3)*(t-3));
                //------------------------------------------------------

                if (sqrt(pow((posbalaox - posbaladx), 2)+pow((posbalaoy - posbalady), 2)) < 0.025*posdx) break;

                else if (sqrt(pow((posbaladx - posbx), 2)+pow((posbalady - posby), 2)) <= 0.005*posdx){
                    cond = 1;
                    break;
                }

            }
            if (cond == 1) break;
        }
        if (cond == 1) break;
    }
}

float condiciones::getVelocidad_inicial() const
{
    return velocidad_inicial;
}

float condiciones::getAngulo() const
{
    return angulo;
}
