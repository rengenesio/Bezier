#-------------------------------------------------
#
# Project created by QtCreator 2011-05-03T19:52:53
#
#-------------------------------------------------

QT       += core gui

TARGET = release/Bezier
TEMPLATE = app


SOURCES +=\
    src/Modelo/curva.cpp \
    src/Modelo/ponto.cpp \
    src/Controle/xmlparser.cpp \
    src/Vista/janelaprincipal.cpp \
    src/Controle/limite.cpp \
    src/Vista/janelaopcoes.cpp \
    src/Modelo/definicoes.cpp \
    src/Main.cpp

HEADERS  += \
    src/Modelo/curva.h \
    src/Modelo/ponto.h \
    src/Controle/xmlparser.h \
    src/Vista/janelaprincipal.h \
    src/comum.h \
    src/Controle/limite.h \
    src/Vista/janelaopcoes.h \
    src/Modelo/definicoes.h

FORMS    +=
