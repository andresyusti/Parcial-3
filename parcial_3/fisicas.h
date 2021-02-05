#ifndef FISICAS_H
#define FISICAS_H
#include<math.h>

class fisicas
{
private:

    float velx;
    float vely;
    float posx;
    float posy;

public:
    fisicas();

    void actualizar_fisicas(float velocidad_inicial, float angulo, float poscx, float poscy, float tiempo);


    float getPosx() const;
    float getPosy() const;
};

#endif // FISICAS_H
