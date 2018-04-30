#include <iostream>
#include <administracion.h>

using namespace std;

int main()
{
    Administracion *concesionario = new Administracion();
    concesionario->menuPrincipal();
    delete concesionario;

    return 0;
}

/*
 *
 * El programa es una aplicacion que
 * estaria instalada en el ordenador de un concesionario
 * de naves espaciales y que solo manejaria el responsable
 * de ventas
 *
 */
