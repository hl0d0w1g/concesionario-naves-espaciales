#ifndef DESTRUCTOR_H
#define DESTRUCTOR_H

#include <cstring>
#include <naves.h>
#include <armamento.h>

class Destructor : public Naves{
    Armamento _armamentoDestructor;
public:
    //Constructores
    Destructor();
    Destructor(string numeroRegistro, string propietario, int maximoTripulantes, int precio, unsigned short propulsion,Armamento armamentoDestructor);
    //Modificadores
    void set_armamento(Armamento armamento);
    //Consultores
    Armamento get_armamento();
    void mostrar();
    void guardar();
    int mostrarTipo(bool mostrar);
    void modificar();
    int capacidad_ofensiva();
    //Destructores
    ~Destructor();
};
#endif // DESTRUCTOR_H
