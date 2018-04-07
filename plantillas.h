#ifndef PLANTILLAS_H
#define PLANTILLAS_H

#include <iostream>
#include <cstring>
#include <cstdlib>

template<typename X>
X validar(X valorMinimo, X valorMaximo, std::string pregunta){ //Comprueba si el valor contestado esta dentro del rango valido
    std::string respuesta = "";
    do{
        std::cout << pregunta << std::endl;
        std::cin >> respuesta;
        if((((atoi(respuesta.c_str())) == 0) && (respuesta[0] < 48 || respuesta[0] > 57)) || ((atoi(respuesta.c_str()))<valorMinimo) || ((atoi(respuesta.c_str()))>valorMaximo)){
            std::cout << "Valor incorrecto, pruebe con un valor entre " << valorMinimo << " y " << valorMaximo << std::endl;
        }
        std::cin.ignore(256, '\n');//limpiamos el buffer
    }while((((atoi(respuesta.c_str())) == 0) && (respuesta[0] < 48 || respuesta[0] > 57)) || ((atoi(respuesta.c_str()))<valorMinimo) || ((atoi(respuesta.c_str()))>valorMaximo));
    //Se repite hasta que se introduce un valor entre el minimo y el maximo
    //Como atoi devuelve 0 si el string empieza con un caracter diferente a un numero, se comprueba el motivo por el que devuelve un 0, si porque se introdujo un cero o un caracter distinto
    return (atoi(respuesta.c_str()));
    /*
     * atoi analiza el string y retorna un 0 si empieza con un caracter distinto de un numero o retorna el numero hasta el ultimo caracter que sea un numero,
     * con esto buscamos que no se puedan introducir letras en variables de tipo numerico o valores negativos en variables de tipo unsigned
     */

}

#endif // PLANTILLAS_H
