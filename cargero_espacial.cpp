#include <iostream>
#include <cstring>
#include <fstream>
#include <plantillas.h>
#include <cargero_espacial.h>

CargeroEspacial::CargeroEspacial(){
    set_numeroRegistro("LNNNNLLL"); //Inicializa los atributos de la clase base
    set_propietarioNave("Indefinido");
    set_maximoTripulantes(0);
    set_precio(0);
    set_propulsion(0);
    _maximaCarga = 0;
    _velocidadCrucero = 0;
    _escudoEnergia = false;
}

CargeroEspacial::CargeroEspacial(string numeroRegistro, string propietario, int maximoTripulantes,int precio,unsigned short propulsion,int maximaCarga, int velocidadCrucero, bool escudoEnergia){
    set_numeroRegistro(numeroRegistro); //Inicializa los atributos de la clase base
    set_propietarioNave(propietario);
    set_maximoTripulantes(maximoTripulantes);
    set_precio(precio);
    set_propulsion(propulsion);
    _maximaCarga = maximaCarga;
    _velocidadCrucero = velocidadCrucero;
    _escudoEnergia = escudoEnergia;
}

void CargeroEspacial::set_maximaCarga(int carga){
    _maximaCarga = carga;
}

void CargeroEspacial::set_velocidad(int velocidad){
    _velocidadCrucero = velocidad;
}

void CargeroEspacial::set_escudo(bool escudo){
    _escudoEnergia = escudo;
}

int CargeroEspacial::get_maximaCarga(){
    return _maximaCarga;
}

int CargeroEspacial::get_velocidad(){
    return _velocidadCrucero;
}

bool CargeroEspacial::get_escudo(){
    return _escudoEnergia;
}

void CargeroEspacial::guardar(){
    ofstream sNaves("naves.txt", ios::out | ios::app);
    sNaves << "CargeroEspacial " << this->get_numeroRegistro() << " " << this->get_propietarioNave() << " " << this->get_maximoTripulantes() << " "
           << this->get_precio() << " " << this->get_propulsion(0) << " ";
    sNaves << this->_maximaCarga << " " << this->_velocidadCrucero << " " << this->_escudoEnergia << " " << std::endl;
    sNaves.close();
}

void CargeroEspacial::mostrar(){
    Naves::mostrar();
    std::cout << "Maxima carga (en toneladas): " << _maximaCarga << std::endl;
    std::cout << "Velocidad de crucero: " << _velocidadCrucero << std::endl;
    std::cout << "Escudo de energía: " << ((_escudoEnergia == 0)? "NO" : "SI") << std::endl;
    std::cout << "" << std::endl;
}

int CargeroEspacial::mostrarTipo(bool mostrar){ //Devuelve un entero para identificar el tipo de nave y lo muestra por pantalla si el parametro es true
    if(mostrar == true){
        std::cout << "Cargero Espacial";
    }
    return 3;
}

void CargeroEspacial::modificar(){
    int eleccion;
    std::cout << "  ¿Que parámetro desea modificar?" << std::endl;
    std::cout << "  1 - Precio " << std::endl;
    std::cout << "  2 - Tipo de propulsión" << std::endl;
    std::cout << "  3 - Máximo de tripulantes" << std::endl;
    std::cout << "  4 - Carga máxima" << std::endl;
    std::cout << "  5 - Velocidad de crucero" << std::endl;
    std::cout << "  6 - " << ((_escudoEnergia == 0)? "Instalar" : "Desinstalar") <<" escudo de energía" << std::endl;
    eleccion = validar(1,6,"");
    system("clear");
    switch(eleccion){
        case 1:{
            std::cout << "Precio actual: " << get_precio() << std::endl;
            this->set_precio(validar(1,1000000,"¿Cual es el nuevo precio de la nave (en miles de millones de creditos espaciales)?"));
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
            std::cout << "Carga máxima actual: " << get_maximaCarga() << std::endl;
            this->set_maximaCarga(validar(1,10000,"¿Cual es la nueva capacidad de carga de la nave (en toneladas)?"));
            system("clear");
            std::cout << "Carga máxima actualizada a: " << get_maximaCarga() << std::endl;
            break;
        }
        case 5:{
            std::cout << "Velocidad de crucero actual: " << get_velocidad() << std::endl;
            this->set_velocidad(validar(1,10000,"¿Cual es la nueva velocidad de crucero de la nave?"));
            system("clear");
            std::cout << "Velocidad de crucero actualizada a: " << get_velocidad() << std::endl;
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

int CargeroEspacial::capacidad_ofensiva(){
    return 0;
}

CargeroEspacial::~CargeroEspacial(){

}
