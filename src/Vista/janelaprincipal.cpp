#include "janelaprincipal.h"



JanelaPrincipal::JanelaPrincipal() {
    this->setGeometry(JANELA_X, JANELA_Y, JANELA_W, JANELA_H);
    this->setMinimumSize(100, 100);
    setEnabled(true);
    tela_ocupada = false;
    criaFerramentas();
    criaMenu();
}

JanelaPrincipal::~JanelaPrincipal() {
}

/* MÉTODOS PRIVATE */
void JanelaPrincipal::conectaSlots() {
    connect(act_abrir, SIGNAL(triggered()), this, SLOT(abreArquivo()));
    connect(act_salvar, SIGNAL(triggered()), this, SLOT(salvaArquivo()));
    connect(act_fechar, SIGNAL(triggered()), this, SLOT(close()));
    connect(act_opcoes, SIGNAL(triggered()), this, SLOT(opcoes()));
}

void JanelaPrincipal::criaActions() {
    act_abrir = new QAction("&Abrir", this);
    act_salvar = new QAction("&Salvar", this);
    act_salvar->setEnabled(false);
    act_fechar = new QAction("&Fechar", this);

    act_opcoes = new QAction("&Opcoes", this);
}

void JanelaPrincipal::criaCanvas() {
    lbl_img = new QLabel(this);
    lbl_img->setGeometry(tb->size().width() + MARGEM_ESQ, menuBar()->size().height() + MARGEM_SUP, this->size().width() - tb->size().width() - MARGEM_ESQ - MARGEM_DIR, this->size().height() - menuBar()->size().height() - MARGEM_SUP - MARGEM_INF);
}

void JanelaPrincipal::criaFerramentas() {
    tb = new QToolBar(this);
    tb->setGeometry(0, menuBar()->size().height(), 30, 500);
    tb->addAction("H:");
}

void JanelaPrincipal::criaMenu() {
    menu_arquivo = menuBar()->addMenu("&Arquivo");
    menu_config = menuBar()->addMenu("&Configuracoes");

    criaActions();
    conectaSlots();

    menu_arquivo->addAction(act_abrir);
    menu_arquivo->addAction(act_salvar);
    menu_arquivo->addSeparator();
    menu_arquivo->addAction(act_fechar);
    menu_arquivo->adjustSize();
    menu_config->addAction(act_opcoes);
    menu_config->adjustSize();
}

void JanelaPrincipal::resizeEvent(QResizeEvent *e) {
    e->ignore();
    if(tela_ocupada) {
        criaCanvas();
        desenha();
        this->repaint();
    }
}

void JanelaPrincipal::mousePressEvent(QMouseEvent *e) {
    if(e->buttons() & Qt::LeftButton)
        procuraCurva(e->x() - lbl_img->x(), e->y() - lbl_img->y());
}

void JanelaPrincipal::keyPressEvent(QKeyEvent *e) {
    if(e->key() == 16777223) {
        apagaCurvas();
    }
}

/* FIM MÉTODOS PRIVATE */

/* SLOTS */

void JanelaPrincipal::apagaCurvas() {
    for(int i = 0 ; i < c.size() ; i++) {
        if(c[i].selecionada) {
            c.removeAt(i);
            i = -1;
        }
    }
    desenha();
}

void JanelaPrincipal::abreArquivo() {
    act_salvar->setEnabled(true);
    QString nome = QFileDialog::getOpenFileName(this, TITULO_ABRIR, PATH_ABRIR, FORMATO_ABRIR);
    if(nome.size() > 0) {
        XMLParser p(nome);
        c = p.getCurvas();
    }
    criaCanvas();
    desenha();
    tela_ocupada = true;
}

void JanelaPrincipal::opcoes() {
    j = new JanelaOpcoes(this, &def);
    connect(j->ok, SIGNAL(clicked()), this, SLOT(salvaConfiguracoes()));
    connect(j->cancela, SIGNAL(clicked()), j->tela, SLOT(close()));
}

void JanelaPrincipal::salvaArquivo() {
    QString nome = QFileDialog::getSaveFileName(this, TITULO_SALVAR, PATH_SALVAR, FORMATO_SALVAR);
    if(nome.size() > 0)
        img.save(nome);
}

void JanelaPrincipal::salvaConfiguracoes() {
    for(int i = 0 ; i < 3 ; i++) {
        def.cor_curva[i] = j->sb_corcurva[i]->value();
        def.cor_ponto[i] = j->sb_corponto[i]->value();
        def.cor_retatangente[i] = j->sb_corretatangente[i]->value();
        def.cor_tangente[i] = j->sb_cortangente[i]->value();
        def.cor_fundo[i] = j->sb_corfundo[i]->value();
    }
    def.w_curva = j->sb_larguracurva->value();
    def.w_ponto = j->sb_larguraponto->value();
    def.w_retatangente = j->sb_larguraretatangente->value();
    def.w_tangente = j->sb_larguratangente->value();
    j->tela->close();
    if(tela_ocupada)
        desenha();
}

/* FIM SLOTS */

void JanelaPrincipal::desenha() {
    for(int i = 0 ; i < c.size() ; i++) {
        if(c[i].getParametricas().size() == 0)
            c[i].parametriza();
    }

    Limite l(c);

    for(int i = 0 ; i < c.size() ; i++) {
        c[i].calculaViewPort(l.getMin(), l.getMax(), lbl_img->size().width(), lbl_img->size().height());
    }

    img = QImage(lbl_img->size().width(), lbl_img->size().height(), QImage::Format_RGB32);
    for(int i = 0 ; i < lbl_img->width() ; i++) {
        for(int j = 0 ; j < lbl_img->height() ; j++) {
            img.setPixel(i, j, qRgb(def.cor_fundo[0], def.cor_fundo[1], def.cor_fundo[2]));
        }
    }
    painter.begin(&img);
  //  painter.eraseRect(0, 0, img.size().width(), img.size().height());
    /*QColor color(def.cor_fundo[0], def.cor_fundo[1], def.cor_fundo[2]);
    painter.fillRect(0, 0, img.width(), img.height(), color);*/

    desenhaCurvas();
    desenhaPontos();
    desenhaTangentes();

    painter.end();
    criaCanvas();
    QPixmap pixmap;
    pixmap = QPixmap::fromImage(img);
    lbl_img->setPixmap(pixmap);
    lbl_img->show();
}

void JanelaPrincipal::desenhaCurvas() {
    painter.setPen(penCurva());
    foreach (Curva curva, c) {
        for(int i = 0 ; i < curva.getVPParametricas().size() -1 ; i++) {
            painter.drawLine(curva.getVPParametricas()[i].getX(), curva.getVPParametricas()[i].getY(), curva.getVPParametricas()[i+1].getX(), curva.getVPParametricas()[i+1].getY());
        }

    }
}

void JanelaPrincipal::desenhaPontos() {
    painter.setPen(penPonto());
    foreach (Curva curva, c) {
        if (curva.selecionada) {
            for(int i = 0 ; i < curva.getVPPontos().size() ; i++) {
                painter.drawPoint(curva.getVPPontos()[i].getX(), curva.getVPPontos()[i].getY());
            }
        }
    }
}

void JanelaPrincipal::desenhaTangentes() {
    foreach (Curva curva, c) {
        if (curva.selecionada) {
            for(int i = 0 ; i < curva.getVPTangentes().size() ; i++) {
                painter.setPen(penTangente());
                painter.drawPoint(curva.getVPTangentes()[i].getX(), curva.getVPTangentes()[i].getY());
                painter.setPen(penRetaTangente());
                painter.drawLine(curva.getVPTangentes()[i].getX(), curva.getVPTangentes()[i].getY(), curva.getVPPontos()[i].getX(), curva.getVPPontos()[i].getY());
            }
        }
    }
}

QPen JanelaPrincipal::penCurva() {
    QPen p;
    p.setWidth(def.w_curva);
    p.setColor(*(new QColor(def.cor_curva[0], def.cor_curva[1], def.cor_curva[2])));
    return p;
}

QPen JanelaPrincipal::penPonto() {
    QPen p;
    p.setWidth(def.w_ponto);
    p.setColor(*(new QColor(def.cor_ponto[0], def.cor_ponto[1], def.cor_ponto[2])));
    return p;
}

QPen JanelaPrincipal::penTangente() {
    QPen p;
    p.setWidth(def.w_tangente);
    p.setColor(*(new QColor(def.cor_tangente[0], def.cor_tangente[1], def.cor_tangente[2])));
    return p;
}

QPen JanelaPrincipal::penRetaTangente() {
    QPen p;
    p.setWidth(def.w_retatangente);
    p.setColor(*(new QColor(def.cor_retatangente[0], def.cor_retatangente[1], def.cor_retatangente[2])));
    return p;
}

void JanelaPrincipal::procuraCurva(int x, int y) {
    for(int i = 0 ; i < c.size() ; i++) {
        for(int j = 0 ; j < c[i].getVPParametricas().size() -1 ; j++) {
            Ponto p1 = c[i].getVPParametricas()[j];
            Ponto p2 = c[i].getVPParametricas()[j+1];
            if(distancia(x, y, p1, p2) < 7 && (sqrt(pow(x - p1.getX(), 2) + pow(y - p1.getY(), 2)) < 7 || sqrt(pow(x - p2.getX(), 2) + pow(y - p2.getY(), 2)) < 7))  {
                if(c[i].selecionada == true)
                    c[i].selecionada = false;
                else
                    c[i].selecionada = true;
                desenha();
                return;
            }
        }
    }
    desenha();
}

float JanelaPrincipal::mod(float f) {
   if(f < 0)
       return -f;
   return f;
}

float JanelaPrincipal::distancia(int x, int y, Ponto p1, Ponto p2) {
    float a = (p1.getY() - p2.getY());
    float b = (p2.getX() - p1.getX());
    float c = (p1.getX() * p2.getY() - p2.getX() * p1.getY());

    return (mod(a*x + b*y + c) / (mod(a) + mod(b)));
}
