#ifndef ESTACION_ESPACIAL_H
#define ESTACION_ESPACIAL_H

#include <cstring>
#include <naves.h>

class EstacionEspacial : public Naves{
    int _maximoPasajeros;
    int _hangares;
    bool _escudoEnergia;
public:
    //Constructores
    EstacionEspacial();
    EstacionEspacial(string numeroRegistro, string propietario, int maximoTripulantes, int precio, unsigned short propulsion, int maximoPasajeros, int hangares, bool escudoEnergia);
    //Modificadores
    void set_maximoPasajeros(int maximoPasajeros);
    void set_hangares(int hangares);
    void set_escudo(bool escudo);
    //Consultores
    int get_maximoPasajeros();
    int get_hangares();
    bool get_escudo();
    void mostrar();
    void guardar();
    int mostrarTipo(bool mostrar);
    void modificar();
    int capacidad_ofensiva();
    //Destructores
    ~EstacionEspacial();
};
#endif // ESTACION_ESPACIAL_H
