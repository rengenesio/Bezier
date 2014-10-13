#ifndef CURVA_H
#define CURVA_H

#include <math.h>
#include <float.h>

#include "ponto.h"
#include "src/comum.h"

class Curva
{
public:
    bool selecionada;

    Curva();
    void addPonto(Ponto p);
    void addTangente(Ponto p);
    void calculaViewPort(Ponto min, Ponto max, int w, int h);
    short int getFormato();
    int getResolucao();
    QList<Ponto> getParametricas();
    QList<Ponto> getPontos();
    QList<Ponto> getTangentes();
    QList<Ponto> getVPParametricas();
    QList<Ponto> getVPPontos();
    QList<Ponto> getVPTangentes();
    void imprime();
    void parametriza();
    void setFormato(short int f);
    void setPontos(QList<Ponto> p);
    void setResolucao(int r);
    void setTangentes(QList<Ponto> t);
    void setVPParametricas(QList<Ponto> vp);
    void setVPPontos(QList<Ponto> vp);
    void setVPTangentes(QList<Ponto> vp);
    bool valida();
    void zera();

private:
    short int formato;
    int resolucao;
    QList<Ponto> pontos;
    QList<Ponto> vp_pontos;
    QList<Ponto> tangentes;

    QList<Ponto> vp_tangentes;
    QList<Ponto> parametricas;
    QList<Ponto> vp_parametricas;
};

#endif // CURVA_H
