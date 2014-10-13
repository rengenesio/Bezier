#ifndef XMLPARSER_H
#define XMLPARSER_H

#include <QFile>
#include <QXmlStreamReader>

#include "src/Modelo/curva.h"
#include "src/Modelo/ponto.h"
#include "src/comum.h"

class XMLParser
{
public:
    XMLParser(QString caminhoarquivo);
    QList<Curva> getCurvas();
    void addCurva(Curva c);
    void imprime();
    void parse(QString caminhoarquivo);

private:
    QList<Curva> curvas;
};

#endif // XMLPARSER_H
