#ifndef CARGERO_ESPACIAL_H
#define CARGERO_ESPACIAL_H

#include <cstring>
#include <naves.h>

class CargeroEspacial : public Naves{
    int _maximaCarga;
    int _velocidadCrucero;
    bool _escudoEnergia;
public:
    //Constructores
    CargeroEspacial();
    CargeroEspacial(string numeroRegistro, string propietario, int maximoTripulantes,int precio,unsigned short propulsion,int maximaCarga, int velocidadCrucero, bool escudoEnergia);
    //Modificadores
    void set_maximaCarga(int carga);
    void set_velocidad(int velocidad);
    void set_escudo(bool escudo);
    //Consultores
    int get_maximaCarga();
    int get_velocidad();
    bool get_escudo();
    void guardar();
    void mostrar();
    int mostrarTipo(bool mostrar);
    void modificar();
    int capacidad_ofensiva();
    //Destructores
    ~CargeroEspacial();
};
#endif // CARGERO_ESPACIAL_H
