#include "janelaopcoes.h"

JanelaOpcoes::JanelaOpcoes(QWidget *parent, Definicoes *def)
{
    tela = new QDialog(parent);
    tela->setWindowTitle(TITULO_OPCOES);
    tela->setGeometry(0, 0, 500, 500);
    this->def = def;
    escreve();
    tela->show();
}

void JanelaOpcoes::escreve() {
    QLabel *lbl;

    lbl = new QLabel("Curva:", tela);
    lbl->setGeometry(10, 15, 0, 0); lbl->adjustSize();
    lbl->show();

    lbl = new QLabel("Cor:", tela);
    lbl->setGeometry(40, 45, 0, 0); lbl->adjustSize();
    lbl->show();

    lbl = new QLabel("R:", tela);
    lbl->setGeometry(85, 45, 0, 0); lbl->adjustSize();
    lbl->show();

    lbl = new QLabel("G:", tela);
    lbl->setGeometry(180, 45, 0, 0); lbl->adjustSize();
    lbl->show();

    lbl = new QLabel("B:", tela);
    lbl->setGeometry(275, 45, 0, 0); lbl->adjustSize();
    lbl->show();

    for(int i = 0 ; i < 3 ; i++) {
        sb_corcurva[i] = new QSpinBox(tela);
        sb_corcurva[i]->setRange(0, 255);
        sb_corcurva[i]->setValue(def->cor_curva[i]);
        sb_corcurva[i]->setGeometry(100 + 95*i, 40, 0, 0); sb_corcurva[i]->adjustSize();
    }

    lbl = new QLabel("Largura:", tela);
    lbl->setGeometry(40, 85, 0, 0); lbl->adjustSize();
    lbl->show();

    sb_larguracurva = new QSpinBox(tela);
    sb_larguracurva->setRange(0, 10);
    sb_larguracurva->setValue(def->w_curva);
    sb_larguracurva->setGeometry(107, 80, 0, 0); sb_larguracurva->adjustSize();

    lbl = new QLabel("Ponto:", tela);
    lbl->setGeometry(10, 125, 0, 0); lbl->adjustSize();
    lbl->show();

    lbl = new QLabel("Cor:", tela);
    lbl->setGeometry(40, 155, 0, 0); lbl->adjustSize();
    lbl->show();

    lbl = new QLabel("R:", tela);
    lbl->setGeometry(85, 155, 0, 0); lbl->adjustSize();
    lbl->show();

    lbl = new QLabel("G:", tela);
    lbl->setGeometry(180, 155, 0, 0); lbl->adjustSize();
    lbl->show();

    lbl = new QLabel("B:", tela);
    lbl->setGeometry(275, 155, 0, 0); lbl->adjustSize();
    lbl->show();

    for(int i = 0 ; i < 3 ; i++) {
        sb_corponto[i] = new QSpinBox(tela);
        sb_corponto[i]->setRange(0, 255);
        sb_corponto[i]->setValue(def->cor_ponto[i]);
        sb_corponto[i]->setGeometry(100 + 95*i, 150, 0, 0); sb_corponto[i]->adjustSize();
    }

    lbl = new QLabel("Largura:", tela);
    lbl->setGeometry(40, 195, 0, 0); lbl->adjustSize();
    lbl->show();

    sb_larguraponto = new QSpinBox(tela);
    sb_larguraponto->setRange(0, 10);
    sb_larguraponto->setValue(def->w_ponto);
    sb_larguraponto->setGeometry(107, 190, 0, 0); sb_larguraponto->adjustSize();

    lbl = new QLabel("Ponto Tangente:", tela);
    lbl->setGeometry(10, 235, 0, 0); lbl->adjustSize();
    lbl->show();

    lbl = new QLabel("Cor:", tela);
    lbl->setGeometry(40, 265, 0, 0); lbl->adjustSize();
    lbl->show();

    lbl = new QLabel("R:", tela);
    lbl->setGeometry(85, 265, 0, 0); lbl->adjustSize();
    lbl->show();

    lbl = new QLabel("G:", tela);
    lbl->setGeometry(180, 265, 0, 0); lbl->adjustSize();
    lbl->show();

    lbl = new QLabel("B:", tela);
    lbl->setGeometry(275, 265, 0, 0); lbl->adjustSize();
    lbl->show();

    for(int i = 0 ; i < 3 ; i++) {
        sb_cortangente[i] = new QSpinBox(tela);
        sb_cortangente[i]->setRange(0, 255);
        sb_cortangente[i]->setValue(def->cor_tangente[i]);
        sb_cortangente[i]->setGeometry(100 + 95*i, 260, 0, 0); sb_cortangente[i]->adjustSize();
    }

    lbl = new QLabel("Largura:", tela);
    lbl->setGeometry(40, 305, 0, 0); lbl->adjustSize();
    lbl->show();

    sb_larguratangente = new QSpinBox(tela);
    sb_larguratangente->setRange(0, 10);
    sb_larguratangente->setValue(def->w_tangente);
    sb_larguratangente->setGeometry(107, 300, 0, 0); sb_larguratangente->adjustSize();

    lbl = new QLabel("Reta Tangente:", tela);
    lbl->setGeometry(10, 345, 0, 0); lbl->adjustSize();
    lbl->show();

    lbl = new QLabel("Cor:", tela);
    lbl->setGeometry(40, 375, 0, 0); lbl->adjustSize();
    lbl->show();

    lbl = new QLabel("R:", tela);
    lbl->setGeometry(85, 375, 0, 0); lbl->adjustSize();
    lbl->show();

    lbl = new QLabel("G:", tela);
    lbl->setGeometry(180, 375, 0, 0); lbl->adjustSize();
    lbl->show();

    lbl = new QLabel("B:", tela);
    lbl->setGeometry(275, 375, 0, 0); lbl->adjustSize();
    lbl->show();

    for(int i = 0 ; i < 3 ; i++) {
        sb_corretatangente[i] = new QSpinBox(tela);
        sb_corretatangente[i]->setRange(0, 255);
        sb_corretatangente[i]->setValue(def->cor_retatangente[i]);
        sb_corretatangente[i]->setGeometry(100 + 95*i, 370, 0, 0); sb_corretatangente[i]->adjustSize();
    }

    lbl = new QLabel("Largura:", tela);
    lbl->setGeometry(40, 415, 0, 0); lbl->adjustSize();
    lbl->show();

    sb_larguraretatangente = new QSpinBox(tela);
    sb_larguraretatangente->setRange(0, 10);
    sb_larguraretatangente->setValue(def->w_retatangente);
    sb_larguraretatangente->setGeometry(107, 410, 0, 0); sb_larguraretatangente->adjustSize();

    lbl = new QLabel("Fundo:", tela);
    lbl->setGeometry(10, 455, 0, 0); lbl->adjustSize();
    lbl->show();

    lbl = new QLabel("Cor:", tela);
    lbl->setGeometry(40, 485, 0, 0); lbl->adjustSize();
    lbl->show();

    lbl = new QLabel("R:", tela);
    lbl->setGeometry(85, 485, 0, 0); lbl->adjustSize();
    lbl->show();

    lbl = new QLabel("G:", tela);
    lbl->setGeometry(180, 485, 0, 0); lbl->adjustSize();
    lbl->show();

    lbl = new QLabel("B:", tela);
    lbl->setGeometry(275, 485, 0, 0); lbl->adjustSize();
    lbl->show();

    for(int i = 0 ; i < 3 ; i++) {
        sb_corfundo[i] = new QSpinBox(tela);
        sb_corfundo[i]->setRange(0, 255);
        sb_corfundo[i]->setValue(def->cor_fundo[i]);
        sb_corfundo[i]->setGeometry(100 + 95*i, 480, 0, 0); sb_corfundo[i]->adjustSize();
    }

    ok = new QPushButton("&Ok", tela);
    ok->setGeometry(110, 540, 0, 0); ok->adjustSize();

    cancela = new QPushButton("&Cancela", tela);
    cancela->setGeometry(210, 540, 0, 0); cancela->adjustSize();

    tela->adjustSize();
}
