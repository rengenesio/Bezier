#include "limite.h"

Limite::Limite(QList<Curva> c) {
    this->c = c;
    calculaLimites();
}

Ponto Limite::getMin() {
    return min;
}

Ponto Limite::getMax() {
    return max;
}

void Limite::calculaLimites() {
    Ponto min(FLT_MAX, FLT_MAX);
    Ponto max(FLT_MIN, FLT_MIN);

    foreach (Curva curva, c) {
        foreach (Ponto p, curva.getParametricas()) {
            if(p.getX() < min.getX())
                min.setX(p.getX());
            if(p.getX() > max.getX())
                max.setX(p.getX());
            if(p.getY() < min.getY())
                min.setY(p.getY());
            if(p.getY() > max.getY())
                max.setY(p.getY());
        }
        foreach (Ponto p, curva.getPontos()) {
            if(p.getX() < min.getX())
                min.setX(p.getX());
            if(p.getX() > max.getX())
                max.setX(p.getX());
            if(p.getY() < min.getY())
                min.setY(p.getY());
            if(p.getY() > max.getY())
                max.setY(p.getY());
        }
        for(int i = 0 ; i < curva.getTangentes().size() ; i++) {
            Ponto t = curva.getTangentes()[i];
            Ponto p = curva.getPontos()[i];

            if(t.getX() + p.getX() < min.getX())
                min.setX(t.getX() + p.getX());
            if(t.getX() + p.getX() > max.getX())
                max.setX(t.getX() + p.getX());
            if(t.getY() + p.getY() < min.getY())
                min.setY(t.getY() + p.getY());
            if(t.getY() + p.getY() > max.getY())
                max.setY(t.getY() + p.getY());
        }
    }
    setMin(min);
    setMax(max);
}

void Limite::setMin(Ponto min) {
    this->min = min;
}

void Limite::setMax(Ponto max) {
    this->max = max;
}
