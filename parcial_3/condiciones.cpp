#include "condiciones.h"

bool condiciones::getVerificar_m() const
{
    return verificar_m;
}

float condiciones::getT() const
{
    return t;
}

void condiciones::setVerificar_m(bool value)
{
    verificar_m = value;
}

condiciones::condiciones()
{

}

void condiciones::ofensivo_golpe_defensivo(float posox, float posoy, float posdx, float posdy)
{
    cond = 0;
    for (velocidad_inicial = 0;velocidad_inicial < 400 ;velocidad_inicial +=1){
        for (angulo=90; angulo > -90; angulo--){
            velbx = velocidad_inicial*cos((360+angulo)*3.14/180);
            velby = velocidad_inicial*sin((360+angulo)*3.14/180);
            for(t=0; ;t+=0.1){
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

void condiciones::defensivo_defiende_ofensivo(float posox, float posoy, float posdx, float posdy, float vel_io, float vel_ox, float vel_oy, float tiempo)
{
    float posbalaox, posbalaoy, t_aux;
    cond = 0;
    for(velocidad_inicial = vel_io; velocidad_inicial < 400; velocidad_inicial++){
        for(angulo = 0; angulo < 180; angulo++){
            velbx = velocidad_inicial*cos((270 - angulo)*3.14/180);
            velby = velocidad_inicial*sin((270 - angulo)*3.14/180);
            t_aux = 0;
            for(t=tiempo; t <= 50; t+=0.1){
                posbalaox = posox+vel_ox*t;
                posbalaoy = posoy+vel_oy*t-(0.5*9.81*t*t);

                posbx = posdx+velbx*(t_aux);
                posby = posdy+velby*(t_aux)-(0.5*9.81*(t_aux)*(t_aux));

                t_aux += 0.1;
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

void condiciones::ofensivo_defiende_defensivo(float vel_ox, float vel_oy, float vel_dx, float vel_dy, float posox, float posoy, float posdx, float posdy, float tiempo)
{
    cond = 0;
    float posbalaox, posbalaoy, posbaladx, posbalady, t_aux;
    for(velocidad_inicial = 0; velocidad_inicial < 800; velocidad_inicial++){
        for(angulo = 0; angulo < 90; angulo++){
            velbx = velocidad_inicial*cos(angulo*3.14/180);
            velby = velocidad_inicial*sin(angulo*3.14/180);
            t_aux = 1;
            for(t = tiempo; t <= 50; t += 0.1){
                //Aqui saco las posiciones de las tres balas
                posbalaox = posox+vel_ox*t;                             //Primera bala ofensiva
                posbalaoy = posoy+vel_oy*t-(0.5*9.81*t*t);

                posbaladx = posdx+vel_dx*(t_aux);                         //Bala defensiva
                posbalady = posdy+vel_dy*(t_aux)-(0.5*9.81*(t_aux)*(t_aux));

                posbx = posox+velbx*(t_aux-1);                              //Segunda bala ofensiva
                posby = posoy+velby*(t_aux-1)-(0.5*9.81*(t_aux-1)*(t_aux-1));
                //------------------------------------------------------
                t_aux += 0.1;

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

void condiciones::verificar_manual(float angulo_, float velocidad_inicial_, float posox, float posoy, float posdx, float posdy)
{
    velbx = velocidad_inicial_*cos(angulo_*3.14/180);
    velby = velocidad_inicial_*sin(angulo_*3.14/180);
    for(t = 0; t <= 50; t += 0.1){
        posbx = posox+velbx*(t);
        posby = posoy+velby*(t)-(0.5*9.81*(t)*(t));
        if (posby < 0) break;
        if (sqrt(pow((posdx - posbx), 2)+pow((posdy - posby), 2)) <= (0.05*posdx)){
            verificar_m = true;
            break;
        }
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
