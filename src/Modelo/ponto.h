#ifndef PONTO_H
#define PONTO_H

#include "src/comum.h"

class Ponto
{
private:
    float x, y;

public:
    Ponto();
    Ponto(float x, float y);
    void imprime();
    float getX();
    float getY();
    void setX(float x);
    void setY(float y);
};

#endif // PONTO_H
