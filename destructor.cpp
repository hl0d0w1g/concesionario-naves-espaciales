#include <iostream>
#include <cstring>
#include <fstream>
#include <plantillas.h>
#include <destructor.h>

Destructor::Destructor(){
    set_numeroRegistro("LNNNNLLL"); //Inicializa los atributos de la clase base
    set_propietarioNave("Indefinido");
    set_maximoTripulantes(0);
    set_precio(0);
    set_propulsion(0);
    Armamento armamentoDestructor;
    _armamentoDestructor = armamentoDestructor;
}

Destructor::Destructor(string numeroRegistro, string propietario, int maximoTripulantes, int precio, unsigned short propulsion, Armamento armamentoDestructor){
    set_numeroRegistro(numeroRegistro); //Inicializa los atributos de la clase base
    set_propietarioNave(propietario);
    set_maximoTripulantes(maximoTripulantes);
    set_precio(precio);
    set_propulsion(propulsion);
    _armamentoDestructor = armamentoDestructor;
}

void Destructor::set_armamento(Armamento armamento){
    _armamentoDestructor = armamento;
}

Armamento Destructor::get_armamento(){
    return _armamentoDestructor;
}

void Destructor::mostrar(){
    Naves::mostrar();
    _armamentoDestructor.mostrar();
}

void Destructor::guardar(){
    ofstream sNaves("naves.txt", ios::out | ios::app);
    sNaves << "Destructor " << this->get_numeroRegistro() << " " << this->get_propietarioNave() << " " << this->get_maximoTripulantes() << " "
           << this->get_precio() << " " << this->get_propulsion(0) << " ";
    sNaves << this->_armamentoDestructor.get_canionPlasma() << " " << this->_armamentoDestructor.get_misiles()
           << " " << this->_armamentoDestructor.get_rayoLaser() << " " << this->_armamentoDestructor.get_pem() << std::endl;
    sNaves.close();
}

int Destructor::mostrarTipo(bool mostrar){ //Devuelve un entero para identificar el tipo de nave y lo muestra por pantalla si el parametro es true
    if(mostrar == true){
        std::cout << "Destructor";
    }
    return 1;
}

void Destructor::modificar(){
    int eleccion;
    std::cout << "  ¿Que parámetro desea modificar?" << std::endl;
    std::cout << "  1 - Precio " << std::endl;
    std::cout << "  2 - Tipo de propulsión" << std::endl;
    std::cout << "  3 - Máximo de tripulantes" << std::endl;
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
            std::cout << "Máximo de tripulantes actual: " << get_maximoTripulantes() << std::endl;
            this->set_maximoTripulantes(validar(1,100,"¿Cual es el nuevo máximo de tripulantes de la nave?"));
            system("clear");
            std::cout << "Máximo de tripulantes actualizado a: " << get_maximoTripulantes() << std::endl;
            break;
        }
        case 4:{
            std::cout << "Número de cañones de plasma actual: " << get_armamento().get_canionPlasma() << std::endl;
            this->_armamentoDestructor.set_canionPlasma(validar(0,100,"¿Cual es el nuevo número de cañones de plasma de la nave?"));
            system("clear");
            std::cout << "Número de cañones de plasma actualizado a: " << get_armamento().get_canionPlasma() << std::endl;
            break;
        }
        case 5:{
            std::cout << "Número de misiles actual: " << get_armamento().get_misiles() << std::endl;
            this->_armamentoDestructor.set_misiles(validar(0,100,"¿Cual es el nuevo número de misiles de la nave?"));
            system("clear");
            std::cout << "Número de misiles actualizado a: " << get_armamento().get_misiles() << std::endl;
            break;
        }
        case 6:{
            std::cout << "Número de rayos laser actual: " << get_armamento().get_rayoLaser() << std::endl;
            this->_armamentoDestructor.set_rayoLaser(validar(0,100,"¿Cual es el nuevo número de rayos laser de la nave?"));
            system("clear");
            std::cout << "Número de rayos laser actualizado a: " << get_armamento().get_rayoLaser() << std::endl;
            break;
        }
        case 7:{
            std::cout << "Número de PEMs actual: " << get_armamento().get_pem() << std::endl;
            this->_armamentoDestructor.set_pem(validar(0,100,"¿Cual es el nuevo número de PEMs de la nave?"));
            system("clear");
            std::cout << "Número de PEMs actualizado a: " << get_armamento().get_pem() << std::endl;
            break;
        }
    }
}

int Destructor::capacidad_ofensiva(){
    return _armamentoDestructor.get_capacidadDestructiva();
}

Destructor::~Destructor(){

}
