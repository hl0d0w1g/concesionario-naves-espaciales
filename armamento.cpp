#include <iostream>
#include <cstring>
#include <plantillas.h>
#include <armamento.h>

Armamento::Armamento(){
    _canionPlasma = 0;
    _misiles = 0;
    _rayoLaser = 0;
    _PEM = 0;
    calcular_capacidadDestructiva();
}

Armamento::Armamento(int canionPlasma, int misiles, int rayoLaser, int PEM){
    _canionPlasma = canionPlasma;
    _misiles = misiles;
    _rayoLaser = rayoLaser;
    _PEM = PEM;
    calcular_capacidadDestructiva();
}

void Armamento::set_canionPlasma(int canionPlasma){
    _canionPlasma = canionPlasma;
    calcular_capacidadDestructiva();
}

void Armamento::set_misiles(int misiles){
    _misiles = misiles;
    calcular_capacidadDestructiva();
}

void Armamento::set_rayoLaser(int rayoLaser){
    _rayoLaser = rayoLaser;
    calcular_capacidadDestructiva();
}

void Armamento::set_pem(int pem){
    _PEM = pem;
    calcular_capacidadDestructiva();
}

void Armamento::set_capacidadDestructiva(int capacidadDestructiva){
    _capacidadDestructiva = capacidadDestructiva;
}

void Armamento::pedirArmas(){
    _canionPlasma = validar(0,100,"¿Cuantos cañones de plasa tiene?");
    _misiles = validar(0,100,"¿Cuantos misiles tiene?");
    _rayoLaser = validar(0,100,"¿Cuantos rayos laser tiene?");
    _PEM = validar(0,100,"¿Cuantos PEMs tiene?");
    calcular_capacidadDestructiva();
}

int Armamento::get_canionPlasma(){
    return _canionPlasma;
}

int Armamento::get_misiles(){
    return _misiles;
}

int Armamento::get_rayoLaser(){
    return _rayoLaser;
}

int Armamento::get_pem(){
    return _PEM;
}

int Armamento::get_capacidadDestructiva(){
    return _capacidadDestructiva;
}

void Armamento::calcular_capacidadDestructiva(){
    _capacidadDestructiva = ((_canionPlasma*10)+(_misiles*20)+(_rayoLaser*5)+(_PEM*15));
}

void Armamento::mostrar(){
    std::cout << "Esta nave va equipada con el siguiente armamento (" << _capacidadDestructiva << "): " << std::endl; //Se muestra entre parentesis su "puntuacion destructiva"
    std::cout << " Cañones de plasma: " << _canionPlasma << std::endl;
    std::cout << " Misiles: " << _misiles << std::endl;
    std::cout << " Rayos laser: " << _rayoLaser << std::endl;
    std::cout << " PEMs: " << _PEM << std::endl;
    std::cout << "" << std::endl;
}

Armamento::~Armamento(){

}
