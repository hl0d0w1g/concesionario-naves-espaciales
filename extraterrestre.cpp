#include <iostream>
#include <cstring>
#include <fstream>
#include <extraterrestre.h>

Extraterrestre::Extraterrestre() : Propietario("No definido"){
    _nie = "NNNNNNNNN";
}

Extraterrestre::Extraterrestre(string planeta, string nie) : Propietario(planeta){
    _nie = nie;
}

void Extraterrestre::set_id(string nie){
    _nie = nie;
}

string Extraterrestre::get_id(){
    return _nie;
}

void Extraterrestre::mostrar(){
    std::cout << "EXTRATERRESTRE-> ";
    std::cout << "NIE: " << _nie;
    std::cout << " - ";
    std::cout << "Planeta de residencia: " << get_planeta() << std::endl;
}

void Extraterrestre::guardar(){
    ofstream sPropietarios("propietarios.txt", ios::out | ios::app);
    sPropietarios << "Extraterrestre " << this->_nie << " " << this->get_planeta() << std::endl;
    sPropietarios.close();
}

Extraterrestre::~Extraterrestre(){

}
