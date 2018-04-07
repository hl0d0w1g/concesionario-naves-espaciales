#ifndef NAVES_H
#define NAVES_H

#include <cstring>
#include <armamento.h>
#include <string>

using namespace std;

class Naves{
    string _numeroRegistro;
    string _IDpropietarioNave;
    int _maximoTripulantes;
    int _precio;
    unsigned short _propulsion; // 1-Motor de curvatura   2-Compresor de traza   3-Motor FTL   4-Velas solares   5-Motor iónico
public:
    //constructores
    Naves();
    Naves(string numeroRegistro, int maximoTripulantes, int precio, unsigned short propulsion);
    //modificadores
    void set_numeroRegistro(string numeroRegistro);
    void set_propietarioNave(string _IDpropietarioNave);
    void set_maximoTripulantes(int maximoTripulantes);
    void set_precio(int precio);
    void set_propulsion(unsigned short propulsion);
    //consultores
    string get_numeroRegistro();
    string get_propietarioNave();
    int get_maximoTripulantes();
    int get_precio();
    unsigned short get_propulsion(bool mostrar);
    //funciones virtuales implementadas en clases derivadas
    virtual void mostrar();
    virtual void guardar() = 0;
    virtual int mostrarTipo(bool ) = 0; // 0-EstacionEspacial  1-Destructor  2-Caza  3-CargeroEspacial
    virtual void modificar() = 0;
    virtual int capacidad_ofensiva() = 0;
    //Destructores
    virtual ~Naves(); //Al declarar el destructor como virtual, primero llamara al destructor del tipo de la nave y luego a este
};

#endif // NAVES_H
