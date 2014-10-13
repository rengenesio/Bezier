#include "ponto.h"

Ponto::Ponto() {
}

Ponto::Ponto(float x, float y) {
    this->x = x;
    this->y = y;
}

void Ponto::imprime() {
    qDebug() << "X:" << getX() << "Y:" << getY();
}

float Ponto::getX() {
    return this->x;
}

float Ponto::getY() {
    return this->y;
}

void Ponto::setX(float x) {
    this->x = x;
}

void Ponto::setY(float y) {
    this->y = y;
}
