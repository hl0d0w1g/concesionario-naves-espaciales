#include <iostream>
#include <cstring>
#include <propietario.h>

Propietario::Propietario(){
    _planeta = "No definido";
}

Propietario::Propietario(string planeta){
    _planeta = planeta;
}

void Propietario::set_planeta(string planeta){
    _planeta = planeta;
}

string Propietario::get_planeta(){
    return _planeta;
}

Propietario::~Propietario(){
}
