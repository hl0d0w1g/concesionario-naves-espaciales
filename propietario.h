#ifndef PROPIETARIO_H
#define PROPIETARIO_H

#include <cstring>

using namespace std;

class Propietario{
    string _planeta;
public:
    //Contructores
    Propietario();
    Propietario(string planeta);
    //Modificadores
    void set_planeta(string planeta);
    virtual void set_id(string id) = 0;
    //Consultores
    string get_planeta();
    virtual void mostrar() = 0;
    virtual void guardar() = 0;
    virtual string get_id() = 0;
    //Destructores
    virtual ~Propietario(); //Al declarar el destructor como virtual, primero llamara al destructor del tipo de propietario y luego a este
};

#endif // PROPIETARIO_H
