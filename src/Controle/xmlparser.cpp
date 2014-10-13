#include "xmlparser.h"

XMLParser::XMLParser(QString caminhoarquivo) {
    parse(caminhoarquivo);
}

void XMLParser::addCurva(Curva c) {
    curvas.append(c);
}

QList <Curva> XMLParser::getCurvas() {
    return curvas;
}

void XMLParser::imprime() {
    for (int i = 0 ; i < curvas.size() ; i++) {
        qDebug() << "Curva" << i;
        curvas[i].imprime();
    }
}

void XMLParser::parse(QString caminhoarquivo) {
    QFile arquivo(caminhoarquivo);
    QXmlStreamReader reader;
    reader.setDevice(&arquivo);

    Curva c;
    Ponto p;
    Ponto min(FLT_MAX, FLT_MAX);
    Ponto max(FLT_MIN, FLT_MIN);

    if(arquivo.open(QFile::ReadOnly | QFile::Text)) {
        while(!reader.atEnd()) {
            reader.readNext();
            if(reader.isStartElement()) {
                if(reader.name() == "curva") {
                    if(reader.attributes().value("formato").toString().toLower() == "bezier") {
                        c.setFormato(BEZIER);
                    }
                    else if(reader.attributes().value("formato").toString().toLower() == "hermit")
                        c.setFormato(HERMIT);

                    c.setResolucao(reader.attributes().value("resolucao").toString().toInt(NULL, 10));
                }
                else if(reader.name() == "x") {
                    p.setX(reader.readElementText().toFloat(NULL));
                }
                else if(reader.name() == "y") {
                    p.setY(reader.readElementText().toFloat(NULL));
                }
            }
            else if(reader.isEndElement()) {
                if(reader.name() == "curva") {
                    //if(c.valida())
                        curvas.append(c);
                    c.zera();
                }
                else if(reader.name() == "ponto") {
                    c.addPonto(p);
                }
                else if(reader.name() == "tangente") {
                    c.addTangente(p);
                }
            }

        }
    }
}
