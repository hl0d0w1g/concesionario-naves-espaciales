#ifndef HUMANO_H
#define HUMANO_H

#include <cstring>
#include <propietario.h>

class Humano : public Propietario{
    string _nif;
public:
    //Constructores
    Humano();
    Humano(string planeta, string nif);
    //Modificadores
    void set_id(string nif);
    //Consultores
    string get_id();
    void mostrar();
    void guardar();
    //Destructores
    ~Humano();
};
#endif // HUMANO_H
