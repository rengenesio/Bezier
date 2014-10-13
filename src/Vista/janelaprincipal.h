#ifndef JanelaPrincipal_H
#define JanelaPrincipal_H

#include <QFileDialog>
#include <QMenuBar>
#include <QMouseEvent>
#include <QPainter>
#include <QToolBar>

#include "src/comum.h"
#include "src/Controle/xmlparser.h"
#include "src/Controle/limite.h"
#include "src/Modelo/definicoes.h"
#include "janelaopcoes.h"


#define JANELA_W        800
#define JANELA_H        600
#define JANELA_X        10
#define JANELA_Y        10

#define MARGEM_ESQ  5
#define MARGEM_DIR  5
#define MARGEM_SUP  5
#define MARGEM_INF  5


class JanelaPrincipal : public QMainWindow
{
    Q_OBJECT
public:
    JanelaPrincipal();
    ~JanelaPrincipal();

private:
    bool tela_ocupada;
    Definicoes def;
    JanelaOpcoes *j;
    QAction *act_abrir, *act_salvar, *act_fechar;
    QAction *act_opcoes;
    QLabel *lbl_img;
    QList<Curva> c;
    QMenu *menu_arquivo;
    QMenu *menu_config;
    QPainter painter;
    QImage img;
    QToolBar *tb;

    void apagaCurvas();
    void conectaSlots();
    void criaActions();
    void criaFerramentas();
    void criaMenu();
    void criaCanvas();
    void desenha();
    void desenhaCurvas();
    void desenhaPontos();
    void desenhaTangentes();
    float distancia(int x, int y, Ponto p1, Ponto p2);
    float mod(float f);
    void mousePressEvent(QMouseEvent *e);
    void procuraCurva(int x, int y);
    void keyPressEvent(QKeyEvent *e);
    void resizeEvent(QResizeEvent *);
    QPen penCurva();
    QPen penPonto();
    QPen penTangente();
    QPen penRetaTangente();

private slots:
    void abreArquivo();
    void opcoes();
    void salvaArquivo();
    void salvaConfiguracoes();
};

#endif // JanelaPrincipal_H
