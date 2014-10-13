#ifndef JANELAOPCOES_H
#define JANELAOPCOES_H

#include <QDialog>
#include <QLabel>
#include <QMainWindow>
#include <QPushButton>
#include <QSpinBox>

#include <QFileDialog>
#include <QMenuBar>
#include <QMouseEvent>
#include <QPainter>
#include <QToolBar>


#include "src/comum.h"
#include "src/Modelo/definicoes.h"

class JanelaOpcoes
{
public:
    JanelaOpcoes(QWidget *parent, Definicoes *def);

    Definicoes *def;
    QDialog *tela;



    QPushButton *ok, *cancela;
    QSpinBox *sb_corcurva[3];
    QSpinBox *sb_larguracurva;
    QSpinBox *sb_corponto[3];
    QSpinBox *sb_larguraponto;
    QSpinBox *sb_corretatangente[3];
    QSpinBox *sb_larguraretatangente;
    QSpinBox *sb_cortangente[3];
    QSpinBox *sb_larguratangente;
    QSpinBox *sb_corfundo[3];

    void escreve();
};

#endif // JANELAOPCOES_H
