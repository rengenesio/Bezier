#include "curva.h"

Curva::Curva()
{
    selecionada = false;
}

void Curva::addPonto(Ponto p) {
    pontos.append(p);
}

void Curva::addTangente(Ponto t) {
    tangentes.append(t);
}

void Curva::calculaViewPort(Ponto min, Ponto max, int w, int h) {
    vp_parametricas.clear();
    vp_pontos.clear();
    vp_tangentes.clear();

    foreach (Ponto p, getParametricas()) {
        Ponto vpponto;
        vpponto.setX((w - 2*W_PONTO) * (p.getX() - min.getX()) / (max.getX() - min.getX()) + W_PONTO);
        vpponto.setY((h - 2*W_PONTO) * (p.getY() - min.getY()) / (max.getY() - min.getY()) + W_PONTO);
        vp_parametricas.append(vpponto);
    }

    foreach (Ponto p, getPontos()) {
        Ponto vpponto;
        vpponto.setX((w - 2*W_PONTO) * (p.getX() - min.getX()) / (max.getX() - min.getX()) + W_PONTO);
        vpponto.setY((h - 2*W_PONTO) * (p.getY() - min.getY()) / (max.getY() - min.getY()) + W_PONTO);
        vp_pontos.append(vpponto);
    }

    for(int i = 0 ; i < getTangentes().size() ; i++) {
        Ponto t = getTangentes()[i];
        Ponto p = getPontos()[i];
        Ponto vpponto;
        vpponto.setX((w - 2*W_PONTO) * (p.getX()+t.getX() - min.getX()) / (max.getX() - min.getX()) + W_PONTO);
        vpponto.setY((h - 2*W_PONTO) * (p.getY()+t.getY() - min.getY()) / (max.getY() - min.getY()) + W_PONTO);
        vp_tangentes.append(vpponto);
    }
}

short int Curva::getFormato() {
    return this->formato;
}

int Curva::getResolucao() {
    return this->resolucao;
}

QList<Ponto> Curva::getParametricas() {
    return this->parametricas;
}

QList<Ponto> Curva::getPontos() {
    return this->pontos;
}

QList<Ponto> Curva::getTangentes() {
    return this->tangentes;
}

QList<Ponto> Curva::getVPParametricas() {
    return this->vp_parametricas;
}

QList<Ponto> Curva::getVPPontos() {
    return this->vp_pontos;
}

QList<Ponto> Curva::getVPTangentes() {
    return this->vp_tangentes;
}

void Curva::imprime() {
    if(formato == 0) {
        qDebug() << "Bezier";
        qDebug() << "Pontos:";

        for(int i = 0 ; i < pontos.size() ; i++) {
            pontos[i].imprime();
        }
    }
    else if(formato == 1) {
        qDebug() << "Hermit";
        for(int i = 0 ; i < pontos.size() ; i++) {
            qDebug() << "Ponto:";
            pontos[i].imprime();
            qDebug() << "Tangente:";
            tangentes[i].imprime();
        }
    }
    else
        qDebug() << "Formato nao reconhecido";
}

void Curva::parametriza() {
    if(getFormato() == BEZIER) {
        for(int i = 1 ; i < getPontos().size() ; i+=3) {
            Ponto p1, p2, p3, p4;
            p1 = getPontos()[i-1];
            p2 = getPontos()[i];
            p3 = getPontos()[i+1];
            p4 = getPontos()[i+2];

            for(int j = 0 ; j <= getResolucao() ; j++) {
                float t = j/(float)getResolucao();

                Ponto p;
                p.setX(p1.getX() * pow((1-t), 3) +
                        p2.getX() * pow((1-t), 2) * 3 * t +
                        p3.getX() * pow(t, 2) * 3 * (1-t) +
                        p4.getX() * pow(t,3));
                p.setY(p1.getY() * pow((1-t), 3) +
                        p2.getY() * pow((1-t), 2) * 3 * t +
                        p3.getY() * pow(t, 2) * 3 * (1-t) +
                        p4.getY() * pow(t,3));
                parametricas.append(p);
            }
        }
    }
    else if(getFormato() == HERMIT) {
        for(int i = 1 ; i < getPontos().size() ; i+=1) {
            Ponto p1, p2, r1, r2;
            p1 = getPontos()[i-1];
            p2 = getPontos()[i];
            r1 = getTangentes()[i-1];
            r2 = getTangentes()[i];

            for(int j = 0 ; j <= getResolucao() ; j++) {
                float t = j/(float)getResolucao();

                Ponto p;
                p.setX(p1.getX() * (2*(pow(t,3)) - 3*(pow(t,2)) + 1) +
                       p2.getX() * (3*(pow(t,2)) - 2*(pow(t,3))) +
                       r1.getX() * (pow(t,3) - 2*(pow(t,2)) + t) +
                       r2.getX() * (pow(t,3) - (pow(t,2))));
                p.setY(p1.getY() * (2*(pow(t,3)) - 3*(pow(t,2)) + 1) +
                       p2.getY() * (3*(pow(t,2)) - 2*(pow(t,3))) +
                       r1.getY() * (pow(t,3) - 2*(pow(t,2)) + t) +
                       r2.getY() * (pow(t,3) - (pow(t,2))));

                parametricas.append(p);
            }
        }
    }
}

void Curva::setFormato(short int f) {
    this->formato = f;
}

void Curva::setPontos(QList<Ponto> p) {
    this->pontos = p;
}

void Curva::setResolucao(int r) {
    this->resolucao = r;
}

void Curva::setTangentes(QList<Ponto> t) {
    this->tangentes = t;
}

void Curva::setVPParametricas(QList<Ponto> vp) {
    this->vp_parametricas = vp;
}

void Curva::setVPPontos(QList<Ponto> vp) {
    this->vp_pontos = vp;
}

void Curva::setVPTangentes(QList<Ponto> vp) {
    this->vp_tangentes = vp;
}

bool Curva::valida() {
    if (formato == BEZIER) {
        qDebug() << pontos.size();
        if(pontos.size()-1 % 3 && pontos.size() >= 4)
            return false;
        else
            return true;
    }
    else if (formato == HERMIT) {
        qDebug() << pontos.size();
        if(pontos.size() == tangentes.size() && pontos.size() >=2)
            return true;
        else
            return false;
    }
    else {
        qDebug() << "Curva invalida";
    }
    return false;
}

void Curva::zera() {
    formato = -1;
    resolucao = 0;
    pontos.clear();
    tangentes.clear();
}
