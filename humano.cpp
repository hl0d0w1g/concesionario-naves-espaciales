#include <iostream>
#include <cstring>
#include <fstream>
#include <humano.h>

Humano::Humano() : Propietario("No definido"){
    _nif = "NNNNNNNNL";
}

Humano::Humano(string planeta, string nif) : Propietario(planeta){
    _nif = nif;
}

void Humano::set_id(string nif){
    _nif = nif;
}

string Humano::get_id(){
    return _nif;
}

void Humano::mostrar(){
    std::cout << "HUMANO-> ";
    std::cout << "NIF: " << _nif;
    std::cout << " - ";
    std::cout << "Planeta de residencia: " << get_planeta() << std::endl;
}

void Humano::guardar(){
    ofstream sPropietarios("propietarios.txt", ios::out | ios::app);
    sPropietarios << "Humano " << this->_nif << " " << this->get_planeta() << std::endl;
    sPropietarios.close();
}

Humano::~Humano(){

}
