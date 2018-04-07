#ifndef CAZA_H
#define CAZA_H

#include <cstring>
#include <naves.h>
#include <armamento.h>

class Caza : public Naves{
    int _velocidadMaxima;
    Armamento _armamentoCaza;
public:
    //Constructores
    Caza();
    Caza(string numeroRegistro, string propietario, int maximoTripulantes, int precio, unsigned short propulsion,int velocidadMaxima, Armamento armamentoCaza);
    //Modificadores
    void set_velocidad(int velocidad);
    void set_armamento(Armamento armamento);
    //Consultores
    int get_velocidad();
    Armamento get_armamento();
    void mostrar();
    void guardar();
    int mostrarTipo(bool mostrar);
    void modificar();
    int capacidad_ofensiva();
    //Destructores
    ~Caza();
};
#endif // CAZA_H
