#include <iostream>
#include <cstring>
#include <naves.h>

Naves::Naves(){
    _numeroRegistro = "LNNNNLLL";
    _IDpropietarioNave = "Indefinido"; //Se crea sin propietario y se añade en el proceso de compra
    _maximoTripulantes = 0;
    _precio = 0;
    _propulsion = 0;
}

Naves::Naves(string numeroRegistro, int maximoTripulantes, int precio, unsigned short propulsion){
    _numeroRegistro = numeroRegistro;
    _IDpropietarioNave = "Indefinido"; //Se crea sin propietario y se añade en el proceso de compra
    _maximoTripulantes = maximoTripulantes;
    _precio = precio;
    _propulsion = propulsion;
}

void Naves::set_numeroRegistro(string numeroRegistro){
    _numeroRegistro = numeroRegistro;
}

void Naves::set_propietarioNave(string IDpropietarioNave){
    _IDpropietarioNave = IDpropietarioNave;
}

void Naves::set_maximoTripulantes(int maximoTripulantes){
    _maximoTripulantes = maximoTripulantes;
}

void Naves::set_precio(int precio){
    _precio = precio;
}

void Naves::set_propulsion(unsigned short propulsion){
    _propulsion = propulsion;
}

string Naves::get_numeroRegistro(){
    return _numeroRegistro;
}

string Naves::get_propietarioNave(){
    return _IDpropietarioNave;
}

int Naves::get_maximoTripulantes(){
    return _maximoTripulantes;
}

int Naves::get_precio(){
    return _precio;
}

unsigned short Naves::get_propulsion(bool mostrar){
    if(mostrar ==1){
        switch (_propulsion) {
        case 1:
            std::cout << "Motor de curvatura";
            break;
        case 2:
            std::cout << "Compresor de traza";
            break;
        case 3:
            std::cout << "Motor FTL";
            break;
        case 4:
            std::cout << "Velas solares";
            break;
        case 5:
            std::cout << "Motor iónico";
            break;
        default:
            std::cout << "No definido";
            break;
        }
    }
    return _propulsion;
}

void Naves::mostrar(){
    std::cout << "------------------------------------------------------------------------------" << std::endl;
    mostrarTipo(true);
    std::cout << " " << _numeroRegistro << std::endl;
    std::cout << "------------------------------------------------------------------------------" << std::endl;
    std::cout << "Dueño: " << _IDpropietarioNave << std::endl;
    std::cout << "Precio de la nave: " << _precio << std::endl;
    std::cout << "Máximo de tripulantes: " << _maximoTripulantes << std::endl;
    std::cout << "Tipo de propulsión: ";
    get_propulsion(1);
    std::cout << std::endl;
}

Naves::~Naves(){
}
