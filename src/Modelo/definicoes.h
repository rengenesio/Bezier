#ifndef DEFINICOES_H
#define DEFINICOES_H

#include "src/comum.h"

class Definicoes
{
public:
    Definicoes();

    float w_curva;
    float w_ponto;
    float w_tangente;
    float w_retatangente;

    int cor_curva[3];
    int cor_ponto[3];
    int cor_tangente[3];
    int cor_retatangente[3];
    int cor_fundo[3];
};

#endif // DEFINICOES_H
