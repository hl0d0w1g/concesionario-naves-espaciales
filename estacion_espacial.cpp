#include <iostream>
#include <cstring>
#include <fstream>
#include <plantillas.h>
#include <estacion_espacial.h>

EstacionEspacial::EstacionEspacial(){
    set_numeroRegistro("LNNNNLLL"); //Inicializa los atributos de la clase base
    set_propietarioNave("Indefinido");
    set_maximoTripulantes(0);
    set_precio(0);
    set_propulsion(0);
    _maximoPasajeros=0;
    _hangares=0;
    _escudoEnergia=false;
}

EstacionEspacial::EstacionEspacial(string numeroRegistro, string propietario, int maximoTripulantes, int precio, unsigned short propulsion, int maximoPasajeros, int hangares, bool escudoEnergia){
    set_numeroRegistro(numeroRegistro); //Inicializa los atributos de la clase base
    set_propietarioNave(propietario);
    set_maximoTripulantes(maximoTripulantes);
    set_precio(precio);
    set_propulsion(propulsion);
    _maximoPasajeros = maximoPasajeros;
    _hangares = hangares;
    _escudoEnergia = escudoEnergia;
}

void EstacionEspacial::set_maximoPasajeros(int maximoPasajeros){
    _maximoPasajeros = maximoPasajeros;
}

void EstacionEspacial::set_hangares(int hangares){
    _hangares = hangares;
}

void EstacionEspacial::set_escudo(bool escudo){
    _escudoEnergia = escudo;
}

int EstacionEspacial::get_maximoPasajeros(){
    return _maximoPasajeros;
}

int EstacionEspacial::get_hangares(){
    return _hangares;
}

bool EstacionEspacial::get_escudo(){
    return _escudoEnergia;
}

void EstacionEspacial::mostrar(){
    Naves::mostrar();
    std::cout << "Maximo de pasajeros: " << _maximoPasajeros << std::endl;
    std::cout << "Número de hangares: " << _hangares << std::endl;
    std::cout << "Escudo de energía: " << ((_escudoEnergia == 0)? "NO" : "SI") << std::endl;
    std::cout << "" << std::endl;
}

void EstacionEspacial::guardar(){
    ofstream sNaves("naves.txt", ios::out | ios::app);
    sNaves << "EstacionEspacial " << this->get_numeroRegistro() << " " << this->get_propietarioNave() << " " << this->get_maximoTripulantes() << " "
           << this->get_precio() << " " << this->get_propulsion(0) << " ";
    sNaves << this->_maximoPasajeros << " " << this->_hangares << " " << this->_escudoEnergia << " " << std::endl;
    sNaves.close();
}

int EstacionEspacial::mostrarTipo(bool mostrar){ //Devuelve un entero para identificar el tipo de nave y lo muestra por pantalla si el parametro es true
    if(mostrar == true){
        std::cout << "Estación Espacial";
    }
    return 0;
}

void EstacionEspacial::modificar(){
    int eleccion;
    std::cout << "  ¿Que parámetro desea modificar?" << std::endl;
    std::cout << "  1 - Precio " << std::endl;
    std::cout << "  2 - Tipo de propulsión" << std::endl;
    std::cout << "  3 - Máximo de tripulantes" << std::endl;
    std::cout << "  4 - Máximo de pasajeros" << std::endl;
    std::cout << "  5 - Número de hangares" << std::endl;
    std::cout << "  6 - " << ((_escudoEnergia == 0)? "Instalar" : "Desinstalar") <<" escudo de energía" << std::endl;
    eleccion = validar(1,6,"");
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
            std::cout << "Máximo de pasajeros actual: " << get_maximoPasajeros() << std::endl;
            this->set_maximoPasajeros(validar(1,10000,"¿Cual es el nuevo máximo de pasajeros de la nave?"));
            system("clear");
            std::cout << "Máximo de pasajeros actualizado a: " << get_maximoPasajeros() << std::endl;
            break;
        }
        case 5:{
            std::cout << "Número de hangares actual: " << get_hangares() << std::endl;
            this->set_hangares(validar(0,50,"¿Cual es el nuevo número de hangares de la nave?"));
            system("clear");
            std::cout << "Número de hangares actualizado a: " << get_hangares() << std::endl;
            break;
        }
        case 6:{
            if(_escudoEnergia == 0){
                _escudoEnergia = 1;
                system("clear");
                std::cout << "Escudo de energía instalado" << std::endl;
            }else{
                _escudoEnergia = 0;
                system("clear");
                std::cout << "Escudo de energía desinstalado" << std::endl;
            }
            break;
        }
    }
}

int EstacionEspacial::capacidad_ofensiva(){
    return 0;
}

EstacionEspacial::~EstacionEspacial(){

}
