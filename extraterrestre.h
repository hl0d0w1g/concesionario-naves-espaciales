#ifndef EXTRATERRESTRE_H
#define EXTRATERRESTRE_H

#include <cstring>
#include <propietario.h>

class Extraterrestre : public Propietario{
    string _nie;
public:
    //Constructores
    Extraterrestre();
    Extraterrestre(string planeta, string nie);
    //Modificadores
    void set_id(string nie);
    //Consultores
    string get_id();
    void mostrar();
    void guardar();
    //Destructores
    ~Extraterrestre();
};

#endif // EXTRATERRESTRE_H
