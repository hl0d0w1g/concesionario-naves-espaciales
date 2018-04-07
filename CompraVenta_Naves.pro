TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    propietario.cpp \
    naves.cpp \
    humano.cpp \
    extraterrestre.cpp \
    administracion.cpp \
    estacion_espacial.cpp \
    destructor.cpp \
    cargero_espacial.cpp \
    caza.cpp \
    armamento.cpp

HEADERS += \
    naves.h \
    propietario.h \
    humano.h \
    extraterrestre.h \
    administracion.h \
    estacion_espacial.h \
    destructor.h \
    cargero_espacial.h \
    caza.h \
    armamento.h \
    plantillas.h
