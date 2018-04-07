#ifndef ADMINISTRACION_H
#define ADMINISTRACION_H

#include <iostream>
#include <cstring>

#include <propietario.h>
#include <humano.h>
#include <extraterrestre.h>
#include <naves.h>
#include <estacion_espacial.h>
#include <destructor.h>
#include <caza.h>
#include <cargero_espacial.h>

class Administracion{
    unsigned int _nNaves;
    unsigned int _nPropietarios;
    Naves **_naves;
    Propietario **_propietarios;
public:
    //Constructores
    Administracion();
    //Menus
    void menuPrincipal();
    void menuPropietarios();
    void menuNaves();
    void menuCompra();
    void menuHistorico();
    void menuVentas();
    //Propietarios
    Propietario * altaPropietario();
    Humano * altaHumano();
    Extraterrestre * altaExtraterrestre();
    void modificarPropietario();
    void bajaPropietario();
    bool comprobarNIF(const string nif);
    bool comprobarNIE(const string nie);
    bool existe_id(const string id);
    //Naves
    Naves * altaNaves();
    EstacionEspacial * altaEstacionEspacial(string nRegistro, int maxTripulantes, int precio, unsigned short propulsion);
    Destructor * altaDestructor(string nRegistro, int maxTripulantes, int precio, unsigned short propulsion);
    Caza * altaCaza(string nRegistro, int precio, unsigned short propulsion);
    CargeroEspacial * altaCargeroEspacial(string nRegistro, int maxTripulantes, int precio, unsigned short propulsion);
    void modificarNave();
    void bajaNave();
    bool comprobar_nRegistro(const string registro);
    bool existe_nRegistro(const string registro);
    //Otros metodos
    void cargarDatos();
    void guardarDatos();
    string fecha(unsigned short formato); //0-Hora, 1-Fecha, 2-Hora y Fecha
    void espera();
    //Destructores
    ~Administracion();
};

#endif // ADMINISTRACION_H
