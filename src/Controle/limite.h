#ifndef LIMITE_H
#define LIMITE_H

#include <float.h>
#include "src/Modelo/curva.h"
#include "src/Modelo/ponto.h"

class Limite
{
public:
    Limite(QList<Curva> c);
    Ponto getMin();
    Ponto getMax();
    void calculaLimites();
    void setMin(Ponto min);
    void setMax(Ponto max);

private:
    QList<Curva> c;
    Ponto min;
    Ponto max;
};

#endif // LIMITE_H
