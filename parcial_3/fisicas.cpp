#include "fisicas.h"
fisicas::fisicas()
{
    posx = 300;
    posy = 400;
}

void fisicas::actualizar_fisicas(float velocidad_inicial, float angulo, float poscx, float poscy, float tiempo)
{
    velx = velocidad_inicial*cos(angulo*3.14/180);
    vely = velocidad_inicial*sin(angulo*3.14/180);
    posx = poscx+velx*tiempo;
    posy = poscy+vely*tiempo-(0.5*9.81*tiempo*tiempo);
}


float fisicas::getPosx() const
{
    return posx;
}

float fisicas::getPosy() const
{
    return posy;
}

