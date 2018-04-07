#include <iostream>
#include <cstring>
#include <fstream>
#include <plantillas.h>
#include <caza.h>

Caza::Caza(){
    set_numeroRegistro("LNNNNLLL"); //Inicializa los atributos de la clase base
    set_propietarioNave("Indefinido");
    set_maximoTripulantes(1);
    set_precio(0);
    set_propulsion(0);
    _velocidadMaxima = 0;
    Armamento armamentoCaza;
    _armamentoCaza = armamentoCaza;
}

Caza::Caza(string numeroRegistro, string propietario, int maximoTripulantes, int precio, unsigned short propulsion, int velocidadMaxima, Armamento armamentoCaza){
    set_numeroRegistro(numeroRegistro); //Inicializa los atributos de la clase base
    set_propietarioNave(propietario);
    set_maximoTripulantes(maximoTripulantes);
    set_precio(precio);
    set_propulsion(propulsion);
    _velocidadMaxima = velocidadMaxima;
    _armamentoCaza = armamentoCaza;
}

void Caza::set_velocidad(int velocidad){
    _velocidadMaxima = velocidad;
}

void Caza::set_armamento(Armamento armamento){
    _armamentoCaza = armamento;
}

int Caza::get_velocidad(){
    return _velocidadMaxima;
}

Armamento Caza::get_armamento(){
    return _armamentoCaza;
}

void Caza::mostrar(){
    Naves::mostrar();
    std::cout << "Velocidad máxima: " << _velocidadMaxima << std::endl;
    _armamentoCaza.mostrar();
}

void Caza::guardar(){
    ofstream sNaves("naves.txt", ios::out | ios::app);
    sNaves << "Caza " << this->get_numeroRegistro() << " " << this->get_propietarioNave() << " " << this->get_maximoTripulantes() << " "
           << this->get_precio() << " " << this->get_propulsion(0) << " ";
    sNaves << this->_velocidadMaxima << " " << this->_armamentoCaza.get_canionPlasma() << " " << this->_armamentoCaza.get_misiles()
           << " " << this->_armamentoCaza.get_rayoLaser() << " " << this->_armamentoCaza.get_pem() << std::endl;
    sNaves.close();
}

int Caza::mostrarTipo(bool mostrar){ //Devuelve un entero para identificar el tipo de nave y lo muestra por pantalla si el parametro es true
    if(mostrar == true){
        std::cout << "Caza";
    }
    return 2;
}

void Caza::modificar(){
    int eleccion;
    std::cout << "  ¿Que parámetro desea modificar?" << std::endl;
    std::cout << "  1 - Precio " << std::endl;
    std::cout << "  2 - Tipo de propulsión" << std::endl;
    std::cout << "  3 - Velocidad máxima" << std::endl;
    std::cout << "  4 - Número de cañones de plasma" << std::endl;
    std::cout << "  5 - Número de misiles" << std::endl;
    std::cout << "  6 - Número de rayos laser" << std::endl;
    std::cout << "  7 - Número de PEMs" << std::endl;
    eleccion = validar(1,7,"");
    system("clear");
    switch(eleccion){
        case 1:{
            std::cout << "Precio actual: " << get_precio() << std::endl;
            this->set_precio(validar(1,1000000,"¿Cual es el nuevo precio de la nave?"));
            system("clear");
            std::cout << "Precio actualizado a: " << get_precio() << std::endl;
            break;
        }
        case 2:{
            std::cout << "Tipo de propulsión actual: ";
            get_propulsion(1);
            std::cout << "" << std::endl;
            std::cout << " 1-Motor de curvatura"<< std::endl;
            std::cout << " 2-Compresor de traza"<< std::endl;
            std::cout << " 3-Motor FTL"<< std::endl;
            std::cout << " 4-Velas solares"<< std::endl;
            std::cout << " 5-Motor iónico"<< std::endl;
            this->set_propulsion(validar(1,5,"¿Cual es el nuevo metodo de propulsión de la nave?"));
            system("clear");
            std::cout << "Tipo de propulsión actualizado a: ";
            get_propulsion(1);
            break;
        }
        case 3:{
            std::cout << "Velocidad máxima actual: " << get_velocidad() << std::endl;
            this->set_velocidad(validar(1,300000,"¿Cual es la nueva velocidad máxima de la nave?"));
            system("clear");
            std::cout << "Velocidad máxima actualizada a: " << get_velocidad() << std::endl;
            break;
        }
        case 4:{
            std::cout << "Número de cañones de plasma actual: " << get_armamento().get_canionPlasma() << std::endl;
            this->_armamentoCaza.set_canionPlasma(validar(0,100,"¿Cual es el nuevo número de cañones de plasma de la nave?"));
            system("clear");
            std::cout << "Número de cañones de plasma actualizado a: " << get_armamento().get_canionPlasma() << std::endl;
            break;
        }
        case 5:{
            std::cout << "Número de misiles actual: " << get_armamento().get_misiles() << std::endl;
            this->_armamentoCaza.set_misiles(validar(0,100,"¿Cual es el nuevo número de misiles de la nave?"));
            system("clear");
            std::cout << "Número de misiles actualizado a: " << get_armamento().get_misiles() << std::endl;
            break;
        }
        case 6:{
            std::cout << "Número de rayos laser actual: " << get_armamento().get_rayoLaser() << std::endl;
            this->_armamentoCaza.set_rayoLaser(validar(0,100,"¿Cual es el nuevo número de rayos laser de la nave?"));
            system("clear");
            std::cout << "Número de rayos laser actualizado a: " << get_armamento().get_rayoLaser() << std::endl;
            break;
        }
        case 7:{
            std::cout << "Número de PEMs actual: " << get_armamento().get_pem() << std::endl;
            this->_armamentoCaza.set_pem(validar(0,100,"¿Cual es el nuevo número de PEMs de la nave?"));
            system("clear");
            std::cout << "Número de PEMs actualizado a: " << get_armamento().get_pem() << std::endl;
            break;
        }
    }
}

int Caza::capacidad_ofensiva(){
    return _armamentoCaza.get_capacidadDestructiva();
}

Caza::~Caza(){

}
