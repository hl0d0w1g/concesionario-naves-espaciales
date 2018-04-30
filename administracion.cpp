#include <administracion.h>
#include <humano.h>
#include <extraterrestre.h>
#include <estacion_espacial.h>
#include <destructor.h>
#include <caza.h>
#include <cargero_espacial.h>
#include <armamento.h>
#include <plantillas.h>
#include <iostream>
#include <cstdlib> //Libreria para la funcion system que se utiliza para "limpiar" la pantalla y la funcion atoi para convertir strings en ints
#include <cstring> //Libreria para trabajar con strings
#include <ctime> //Libreria para trabajar con la fecha y la hora
#include <fstream> //Libreria para trabajar con ficheros

/////////////////////////////////////////Constructores/////////////////////////////////////////
Administracion::Administracion(){
    cargarDatos();
}

/////////////////////////////////////////Menus/////////////////////////////////////////
void Administracion::menuPrincipal(){ //Este metodo muestra el menu principal para que el usuario eliga que hacer
    std::cout << "*******************************************************************************" << std::endl;
    std::cout << "*******************************************************************************" << std::endl;
    std::cout << "***********************  CONCESIONARIO NAVES ESPACIALES  **********************" << std::endl;
    std::cout << "*****************  venta de naves espaciales de segunda mano  *****************" << std::endl;
    std::cout << "*****************                 ¡Bienvenido!                *****************" << std::endl;
    std::cout << "*******************************************************************************" << std::endl;
    std::cout << "*******************************************************************************" << std::endl;
    std::cout << std::endl;
    int opcion;
    do{
        std::cout << "  ¿Que desea hacer?" << std::endl;
        std::cout << "------------------------------------------------------------------------------" << std::endl;
        std::cout << "  1 - Gestionar propietarios" << std::endl;
        std::cout << "  2 - Gestionar naves" << std::endl;
        std::cout << "  3 - Realizar operaciones de compra" << std::endl;
        std::cout << "  4 - Visualizar histórico de ventas" << std::endl;
        std::cout << "  5 - Buscar ventas" << std::endl;
        std::cout << "" << std::endl;
        std::cout << "  0 - Salir" << std::endl;
        opcion = validar(0,5,""); //Funcion validar declarada en plantillas.h
        system("clear");
            switch (opcion){
            case 1:{ //Gestionar propietarios
                menuPropietarios(); //Se llama al sub menu que gestiona las decisiones que tienen que ver con propietarios
                break;
            }
            case 2:{ //Gestionar naves
                menuNaves(); //Se llama al sub menu que gestiona las decisiones que tienen que ver con naves
                break;
            }
            case 3:{ //Compra
                menuCompra(); //Se llama al sub menu que gestiona las decisiones que tienen que ver con el proceso de compra de una nave por un propietario
                break;
            }
            case 4:{ //Se llama al sub menu que gestiona el historico de ventas
                menuHistorico();
                break;
            }
            case 5:{ //Se llama al sub menu que gestiona las ventas
                menuVentas();
                break;
            }
            case 0:{ //Salir
                system("clear");
                std::cout << "------------------------------------------------------------------------------" << std::endl;
                std::cout << "Gracias por su visita" << std::endl;
                std::cout << "------------------------------------------------------------------------------" << std::endl;
                std::cout << "" << std::endl;
                break;
            }
            default:{
                break;
            }
            };
    }while(opcion != 0);
}
void Administracion::menuPropietarios(){ //Este metodo muestra un sub menu referente a propietarios para que el usuario eliga que hacer
    int opcion;
    do{
        std::cout << "  ¿Que desea hacer?" << std::endl;
        std::cout << "------------------------------------------------------------------------------" << std::endl;
        std::cout << "  1 - Dar de alta un propietario" << std::endl;
        std::cout << "  2 - Modificar un propietario" << std::endl;
        std::cout << "  3 - Dar de baja un propietario" << std::endl;
        std::cout << "  4 - Visualizar los propietarios registrados en el sistema" << std::endl;
        std::cout << "" << std::endl;
        std::cout << "  0 - Atras" << std::endl;
        opcion = validar(0,4,"");
        system("clear");
            switch (opcion){
            case 1:{ //Dar de alta un propietario
                Propietario *nuevoPropietario = altaPropietario();
                this->_propietarios[_nPropietarios] = nuevoPropietario; //Se introduce en el array el nuevo propietario
                system("clear");
                std::cout << "********************* Ha sido dado de alta correctamente *********************" << std::endl;
                this->_propietarios[_nPropietarios]->mostrar();
                this->_nPropietarios++; //Se aumenta el numero de propietarios existentes
                std::cout << "" << std::endl;
                break;
            }
            case 2:{ //Modificar un propietario, el numero identificador no se puede cambiar al igual que no podemos cambiar nosotros de DNI
                if(_nPropietarios == 0){
                    std::cout << "------------------------------------------------------------------------------" << std::endl;
                    std::cout << "No hay propietarios registrados en el sistema" << std::endl;
                    std::cout << "------------------------------------------------------------------------------" << std::endl;
                    std::cout << "" << std::endl;
                    break;
                }
                modificarPropietario();
                espera();
                break;
            }
            case 3:{ //Dar de baja un propietario
                if(_nPropietarios == 0){
                    std::cout << "------------------------------------------------------------------------------" << std::endl;
                    std::cout << "No hay propietarios registrados en el sistema" << std::endl;
                    std::cout << "------------------------------------------------------------------------------" << std::endl;
                    std::cout << "" << std::endl;
                    break;
                }
                bajaPropietario();
                std::cin.ignore(256, '\n');
                espera();
                break;
            }
            case 4:{ //Visualizar propietarios en el sistema
                if(_nPropietarios == 0){
                    std::cout << "------------------------------------------------------------------------------" << std::endl;
                    std::cout << "No hay propietarios registrados en el sistema" << std::endl;
                    std::cout << "------------------------------------------------------------------------------" << std::endl;
                    std::cout << "" << std::endl;
                    break;
                }
                std::cout << "Propietarios registrados en el sistema" << std::endl;
                std::cout << "------------------------------------------------------------------------------" << std::endl;
                for(unsigned int i = 0; i<_nPropietarios; i++){
                    _propietarios[i]->mostrar();
                }
                std::cout << "------------------------------------------------------------------------------" << std::endl;
                std::cout << "" << std::endl;
                espera();
                break;
            }
            default:{
                break;
            }
            };
    }while(opcion != 0);
}
void Administracion::menuNaves(){ //Este metodo muestra un sub menu referente a naves para que el usuario eliga que hacer
    int opcion;
    do{
        std::cout << "¿Que desea hacer?" << std::endl;
        std::cout << "------------------------------------------------------------------------------" << std::endl;
        std::cout << "  1 - Dar de alta una nave" << std::endl;
        std::cout << "  2 - Modificar una nave" << std::endl;
        std::cout << "  3 - Dar de baja una nave" << std::endl;
        std::cout << "  4 - Visualizar las naves registradas en el sistema" << std::endl;
        std::cout << "" << std::endl;
        std::cout << "  0 - Atras" << std::endl;
        opcion = validar(0,4,"");
        system("clear");
            switch (opcion){
            case 1:{ //Dar de alta una nave
                Naves *nuevaNave = altaNaves();
                this->_naves[_nNaves] = nuevaNave; //Se introduce en el array la nueva nave
                system("clear");
                std::cout << "********************* Ha sido dada de alta correctamente *********************" << std::endl;
                this->_naves[_nNaves]->mostrar();
                this->_nNaves++; //se aumenta el numero de naves existentes
                break;
            }
            case 2:{ //Modificar una nave
                if(_nNaves==0){
                    std::cout << "------------------------------------------------------------------------------" << std::endl;
                    std::cout << "No hay ninguna nave registrada en el sistema" << std::endl;
                    std::cout << "------------------------------------------------------------------------------" << std::endl;
                    std::cout << "" << std::endl;
                    break;
                }
                modificarNave();
                std::cin.ignore(256, '\n');
                espera();
                break;
            }
            case 3:{ //Dar de baja una nave
                if(_nNaves==0){
                    std::cout << "------------------------------------------------------------------------------" << std::endl;
                    std::cout << "No hay ninguna nave registrada en el sistema" << std::endl;
                    std::cout << "------------------------------------------------------------------------------" << std::endl;
                    std::cout << "" << std::endl;
                    break;
                }
                bajaNave();
                std::cin.ignore(256, '\n');
                espera();
                break;
            }
            case 4:{ //Visualizar naves registradas en el sistema
                if(_nNaves==0){
                    std::cout << "------------------------------------------------------------------------------" << std::endl;
                    std::cout << "No hay ninguna nave registrada en el sistema" << std::endl;
                    std::cout << "------------------------------------------------------------------------------" << std::endl;
                    std::cout << "" << std::endl;
                    break;
                }
                std::cout << "Naves registradas en el sistema:" << std::endl;
                for(unsigned int i = 0; i<_nNaves; i++){ //Se ordenan las naves de mayor a menor capacidad ofensiva
                    for(unsigned int j = 0; j<(_nNaves-1); j++){
                        if(_naves[j]->capacidad_ofensiva()<_naves[j+1]->capacidad_ofensiva()){
                            Naves *temp = _naves[j+1];
                            _naves[j+1] = _naves[j];
                            _naves[j] = temp;
                        }
                    }
                }
                for(unsigned int i = 0; i<_nNaves; i++){
                    _naves[i]->mostrar();
                }
                std::cout << "------------------------------------------------------------------------------" << std::endl;
                std::cout << "" << std::endl;
                std::cout << "" << std::endl;
                espera();
                break;
            }
            default:{
                break;
            }
        };
    }while(opcion != 0);
}
void Administracion::menuCompra(){ //Este metodo muestra un sub menu referente al proceso de compra para que el usuario eliga que hacer

    if(_nPropietarios == 0 || _nNaves == 0){ //Da informacion de los requisitos que faltan para realizar una compra
        std::cout << "------------------------------------------------------------------------------" << std::endl;
        if(_nPropietarios == 0 && _nNaves == 0){
            std::cout << "No hay propietarios o naves registrados en el sistema" << std::endl;
        }else if(_nPropietarios != 0 && _nNaves == 0){
            std::cout << "No hay naves registradas en el sistema" << std::endl;
        }else if(_nPropietarios == 0 && _nNaves != 0){
            std::cout << "No hay propietarios registrados en el sistema" << std::endl;
        }
        std::cout << "------------------------------------------------------------------------------" << std::endl;
        std::cout << "" << std::endl;
    }else{
        string nRegistro, id;
        bool tipoPropietario = 0; //Si vale 0 es estraterrestre, si vale 1 es humano
        unsigned int i = 0, n = 0;
        unsigned short x = 0;
        std::cout << "¿Cual es la identificación del comprador?" << std::endl;
        std::cin >> id;
        for(; i<_nPropietarios; i++){
            if(_propietarios[i]->get_id() == id){
                break;
            }
        }
        if(i == _nPropietarios){ //Si el bucle anterior llega al final significa que no ha encontrado esa identificacion
            std::cout << "------------------------------------------------------------------------------" << std::endl;
            std::cout << "El número de identificacion no coincide con ningun usuario" << std::endl;
            std::cout << "------------------------------------------------------------------------------" << std::endl;
            std::cout << "" << std::endl;
        }else{
            if(comprobarNIF(id) == true){ //Si la identificacion tiene formato de NIF es humano, sino sera extraterrestre
                tipoPropietario = 1;
            }
            system("clear");
            std::cout << "Informacion del propietario que va a realizar la compra" << std::endl;
            std::cout << "------------------------------------------------------------------------------" << std::endl;
            _propietarios[i]->mostrar();
            std::cout << "" << std::endl;
            std::cout << "Naves disponibles para la venta" << std::endl; //Se muestras las naves que puede comprar en funcion de si es humano o extraterrestre
            std::cout << "------------------------------------------------------------------------------" << std::endl;
            for(; n<_nNaves; n++){
                if((tipoPropietario == 1)&&(_naves[n]->mostrarTipo(0) != 1)&&(_naves[n]->get_propietarioNave() == "Indefinido")){
                    //Si es propietario tipo 1 (humano) se muestran todas las naves diferentes a las de tipo 1 (destructor) que no tengan dueño
                    _naves[n]->mostrarTipo(1);
                    std::cout << "-> " << _naves[n]->get_numeroRegistro() << std::endl;
                    x++;
                }
                if((tipoPropietario == 0)&&(_naves[n]->mostrarTipo(0) != 0)&&(_naves[n]->get_propietarioNave() == "Indefinido")){
                    //Si el propietario es tipo 0 (extraterrestre) se muestras todas las naves diferentes a las de tipo 0 (estacion espacial) q no tengan dueño
                    _naves[n]->mostrarTipo(1);
                    std::cout << "-> " << _naves[n]->get_numeroRegistro() << std::endl;
                    x++;
                }

            }
            if(x == 0){ //Si en el bucle anterior no entra en ningun if significa que no ha encontrado naves que ese tipo de propietario pueda comprar
                std::cout << "No hay naves disponibles para este tipo de propietario" << std::endl;
                std::cout << "------------------------------------------------------------------------------" << std::endl;
                std::cout << "" << std::endl;
                espera();
            }else{
                std::cout << "------------------------------------------------------------------------------" << std::endl;
                std::cout << "" << std::endl;
                do{
                    std::cout << "¿Cual es la matricula de la nave que desea comprar?" << std::endl;
                    std::cin >> nRegistro;
                    for(n = 0; n<_nNaves; n++){
                        if(tipoPropietario == 1){ //Se comprueba que la matricula introducida esta entre las mostradas anteriormente para evitar que un propietario compre una nave que no puede
                            if((_naves[n]->get_numeroRegistro() == nRegistro)&&(_naves[n]->mostrarTipo(0) != 1)&&(_naves[n]->get_propietarioNave() == "Indefinido")){
                                break;
                            }
                        }else{
                            if((_naves[n]->get_numeroRegistro() == nRegistro)&&(_naves[n]->mostrarTipo(0) != 0)&&(_naves[n]->get_propietarioNave() == "Indefinido")){
                                break;
                            }
                        }
                    }
                    if(n == _nNaves){ //Si el bucle anterior llega al final significa que la matricula introducida no esta estre las que puede comprar o directamente no existe
                        std::cout << "La matricula no coincide con ninguna nave" << std::endl;
                        std::cout << "" << std::endl;
                    }
                }while(n == _nNaves); //Si hay naves disponibles para comprar por ese propietario, se repite hasta que eliga una valida
                system("clear");
                _naves[n]->set_propietarioNave(_propietarios[i]->get_id());
                std::cout << "INFORMACIÓN DE LA VENTA" << std::endl;
                std::cout << "------------------------------------------------------------------------------" << std::endl;
                std::cout << "El propietario de tipo ";
                _propietarios[i]->mostrar();
                std::cout << "" << std::endl;
                std::cout << "Ahora es dueño de la nave:" << std::endl;
                _naves[n]->mostrar();
                std::cout << "" << std::endl;
                ofstream sVentas("ventas.txt", ios::out | ios::app); //Seguarda la informacion de la venta en el registro
                if(sVentas.is_open()){                               //Si se da de baja una nave o propietario, las ventas en las que aparecen no se eliminan,
                    sVentas << fecha(1) + "    ";                    //ya que es algo que ocurrió aunque ya no esten guardados en el sistema
                    if(tipoPropietario == 1){
                        sVentas << "Humano ";
                    }else{
                        sVentas << "Extraterrestre ";
                    }
                    sVentas << _naves[n]->get_propietarioNave() + "    ";
                    switch(_naves[n]->mostrarTipo(0)){
                    case 0:{
                        sVentas << "EstacionEspacial ";
                        break;
                    }
                    case 1:{
                        sVentas << "Destructor ";
                        break;
                    }
                    case 2:{
                        sVentas << "Caza ";
                        break;
                    }
                    case 3:{
                        sVentas << "CargeroEspacial ";
                        break;
                    }
                    }
                    sVentas << _naves[n]->get_numeroRegistro() << std::endl;
                }else{
                    std::cout << "Error al guardar los datos de la aplicacion" << std::endl;
                    std::cout << "" << std::endl;
                }
                sVentas.close();
                std::cin.ignore(256, '\n');
                espera();
            }
        }
    }
}
void Administracion::menuHistorico(){ //Este metodo muestra el historico de ventas
    char cadena[100];
    ifstream eVentas("ventas.txt", ios::in);
    if(eVentas.is_open()){ //Se comprueba que el archivo se ha abierto correctamente
        std::cout << "Fecha        Propietario         Nave" << std::endl;
        std::cout << "------------------------------------------------------------------------------" << std::endl;
        while(!eVentas.eof()){ //Se lee el archivo completo
            eVentas.getline(cadena,100);
            std::cout << cadena << std::endl;
        }
    }else{
        std::cout << "Los datos no se cargaron correctamente" << std::endl;
        std::cout << "" << std::endl;
    }
    eVentas.close();
    espera();
    system("clear");
}
void Administracion::menuVentas(){ //Este sub menu permite realizar busquedas de ventas por fechas o propietarios
    int opcion;
    string respuesta;
    string fecha, tipoPropietario, idPropietario, tipoNave, idNave;
    string dd, mm, aa;
    do{
        ifstream eVentas("ventas.txt", ios::in);
        if(eVentas.is_open()){ //Se comprueba que el archivo se ha abierto correctamente
            std::cout << "  ¿Que desea hacer?" << std::endl;
            std::cout << "------------------------------------------------------------------------------" << std::endl;
            std::cout << "  1 - Buscar ventas en una fecha concreta" << std::endl;
            std::cout << "  2 - Buscar ventas en un intervalo de tiempo" << std::endl;
            std::cout << "  3 - Buscar ventas realizadas a un propietario" << std::endl;
            std::cout << "" << std::endl;
            std::cout << "  0 - Atras" << std::endl;
            opcion = validar(0,3,"");
            system("clear");
                switch (opcion){
                case 1:{
                    int d, m, a;
                    d = validar(1,31,"¿De que día desea ver las ventas?");
                    m = validar(1,12,"¿De que mes?");
                    a = validar(1900,2017,"¿Y de que año?");
                    system("clear");
                    respuesta = std::to_string(d) + " " + std::to_string(m) + " " + std::to_string(a); // Se transforma la fecha en string para la comparacion
                    std::cout << "Ventas del día " << d << "/" << m << "/" << a << std::endl;
                    std::cout << std::endl;
                    while(!eVentas.eof()){
                        eVentas >> dd >> mm >> aa >> tipoPropietario >> idPropietario >> tipoNave >> idNave; //Se extraen los parametros del archivo
                        fecha = dd + " " + mm + " " + aa;
                        if((respuesta == fecha)&&(!eVentas.eof())){
                            std::cout << tipoPropietario << " " << idPropietario << " -- " << tipoNave << " " << idNave << std::endl;
                        }
                    }
                    std::cout << std::endl;
                    espera();
                    system("clear");
                    break;
                }
                case 2:{
                    int d1, m1, a1;
                    int d2, m2, a2;
                    bool imprimir = false;
                    std::cout << "¿Fecha de inicio de busqueda?" << std::endl;
                    d1 = validar(1,31,"Día:");
                    m1 = validar(1,12,"Mes:");
                    a1 = validar(1900,2017,"Año:");
                    std::cout << std::endl;
                    std::cout << "¿Fecha de finalizacion de busqueda?" << std::endl;
                    d2 = validar(1,31,"Día:");
                    m2 = validar(1,12,"Mes:");
                    a2 = validar(a1,2017,"Año:"); //Comprobamos que el año que se introduce es como minimo igual al de inicio de busqueda
                    system("clear");
                    std::cout << "Ventas desde el día " << d1 << "/" << m1 << "/" << a1 << " hasta el día " << d2 << "/" << m2 << "/" << a2 << std::endl;
                    std::cout << std::endl;
                    while(!eVentas.eof()){
                        eVentas >> dd >> mm >> aa >> tipoPropietario >> idPropietario >> tipoNave >> idNave;
                        fecha = dd + "/" + mm + "/" + aa;
                        //Se buscan todas las fechas que que esten entre la inicial y la final y se muestran
                        if((atoi(aa.c_str()) > a1) && (atoi(aa.c_str()) < a2)){
                            //Si el año extraido del fichero es mayor o menor que os de la busqueda sabemos que la fecha esta en el intervalo
                            imprimir = true;
                        }else if((atoi(aa.c_str()) == a1) && (atoi(aa.c_str()) == a2)){
                            //Si los años de inicio y final de busqueda fuesen iguales, pasamos a comprobar el mes
                            if((atoi(mm.c_str()) > m1) && (atoi(mm.c_str()) < m2)){
                                //Si siendo los años iguales, el mes extraido del fichero esta entre los dos de la busqueda sabemos que esta en el intervalo
                                imprimir = true;
                            }else if((atoi(mm.c_str()) == m1) && (atoi(mm.c_str()) == m2)){
                                //Si ademas del año coincidiese el mes, pasamos a comprobar el dia
                                if((atoi(dd.c_str()) >= d1) && (atoi(dd.c_str()) <= d2)){
                                    imprimir = true;
                                }
                            }
                        }else if((atoi(aa.c_str()) == a1) && (atoi(mm.c_str()) >= m1)){
                            //Al ser un condicional else if, a estos apartados solo llega si no ha entrado en los anteriores, de modo que comprobamos la fecha
                            //si solo coincidiese con el año de inicio de busqueda
                            if((atoi(mm.c_str()) > m1)){
                                //Si solo coincide con el año de inicio de busqueda, sabemos que pertenecera al intervalo si es mayor al mes de inicio de busqueda
                                imprimir = true;
                            }else if((atoi(mm.c_str()) == m1) && (atoi(dd.c_str()) >= d1)){
                                //Si el mes fuese igual pasamos a comprobar el dia
                                imprimir = true;
                            }
                        }else if((atoi(aa.c_str()) == a2) && (atoi(mm.c_str()) <= m2)){
                            //Hacemos lo mismo que para el año inicial pero ahora con el final
                            if((atoi(mm.c_str()) < m2)){
                                imprimir = true;
                            }else if((atoi(mm.c_str()) == m2) && (atoi(dd.c_str()) <= d2)){
                                imprimir = true;
                            }
                        }
                        if((imprimir == true)&&(!eVentas.eof())){
                            //Finalmente si cumplio las condiciones que certifican que la fecha extraida del fichero esta entre las introducidas se imprime
                            std::cout << fecha << "    " << tipoPropietario << " " << idPropietario << " -- " << tipoNave << " " << idNave << std::endl;
                            imprimir = false;
                        }
                    }
                    std::cout << std::endl;
                    espera();
                    system("clear");
                    break;
                }
                case 3:{
                    std::cout << "¿Cual es la identificación del propietario?" << std::endl;
                    std::cin >> respuesta;
                    system("clear");
                    std::cout << "Ventas realizadas al propietario " << respuesta << std::endl;
                    std::cout << std::endl;
                    while(!eVentas.eof()){
                        eVentas >> dd >> mm >> aa >> tipoPropietario >> idPropietario >> tipoNave >> idNave;
                        fecha = dd + "/" + mm + "/" + aa;
                        if((respuesta == idPropietario)&&(!eVentas.eof())){
                            std::cout << fecha << "    " << tipoPropietario << " " << idPropietario << " -- " << tipoNave << " " << idNave << std::endl;
                        }
                    }
                    std::cout << std::endl;
                    std::cin.ignore(256, '\n');
                    espera();
                    system("clear");
                    break;
                }
                default:{
                    break;
                }
                };
        }else{
            std::cout << "El fichero no se abrió correctamente" << std::endl;
            std::cout << std::endl;
        }
        eVentas.close();
    }while(opcion != 0);
}

/////////////////////////////////////////Funciones referentes al menu propietarios/////////////////////////////////////////
Propietario *Administracion::altaPropietario(){ //Se seleciona que tipo de propietario es y se llama a la funcion correspondiente
    string eleccion;
    if(_nPropietarios == 0){ // Si hay cero propietarios, se crea un primer array de una sola posicion
        this->_propietarios = new Propietario*[this->_nPropietarios+1];
        for(unsigned int i = 0; i<_nPropietarios+1; i++){ //Se inicializa el array
            this->_propietarios[i] = NULL;
        }
    }else{ //Si hay uno o mas propietarios se crea un array auxiliar de n+1 posiciones
        unsigned int i = 0;
        Propietario **arrayAuxiliar = new Propietario*[this->_nPropietarios+1]; //Se crea un array donde volcar la informacion
        Propietario **punteroAuxiliar; //Se crea un puntero de punteros para poder liberar memoria mas tarde
        for(i = 0; i<_nPropietarios+1; i++){ //Se inicializa a null el nuevo array
            arrayAuxiliar[i] = NULL;
        }
        for(i = 0; i<_nPropietarios; i++){ //Se copian los punteros al array auxiliar
            arrayAuxiliar[i] = _propietarios[i];
        }
        //A continuacion, se copia la direccion de memoria a donde apunta _propietarios, q es la primera posicion del array q contiene los punteros
        //q apuntan a las direcciones de memoria donde estan los porpietarios, a un puntero auxiliar.
        punteroAuxiliar = this->_propietarios;
        //Luego se hace que _propietarios apunte a la primera direccion de memoria del nuevo array mas grande.
        this->_propietarios = arrayAuxiliar;
        //Se pasa la direccion de memoria a la que apuntaba _propietarios, que es la direccion de memoria de la primera posicion del array antiguo.
        arrayAuxiliar = punteroAuxiliar;
        //Por ultimo, se liberan esas direcciones de memoria que contenian los punteros del primer array para que el sistema pueda disponer de ellas
        if(arrayAuxiliar != NULL){
            delete[] arrayAuxiliar;
        }
    }
    do{
        std::cout << "¿Que tipo de propietario desea dar de alta? Humano o Extraterrestre (H/E)" << std::endl;
        std::cin >> eleccion;
        if(eleccion == "H" || eleccion == "h"){ //Si se selecciona una H o h el propietario es humano
             return this->altaHumano();
        }else if(eleccion == "E" || eleccion == "e") { //Si se selecciona una E o e el propietario es extraterrestre
            return this->altaExtraterrestre();
        }else{
            std::cout << "Por favor eliga entre Humano o Extraterrestre (H/E)" << std::endl;
        }
    }while(eleccion != "H" || eleccion != "h" || eleccion == "E" || eleccion == "e");
    return NULL; //Si por cualquier motivo saliese del bucle devuelve null para no generar una indeterminacion
}
Humano *Administracion::altaHumano(){ //Recoge los datos de un nuevo humano y reserva memoria
    string planeta = "", nif = "";
    std::cout << "¿Cual es su planeta de residencia?" << std::endl;
    std::cin.ignore(256, '\n');//limpiamos el buffer
    getline(cin, planeta);
    do{
        std::cout << "¿Cual es su NIF?" << std::endl;
        std::cin >> nif;
        std::cin.ignore(256, '\n');//limpiamos el buffer
    }while((comprobarNIF(nif) == false)||(existe_id(nif) == true)); //Se llama a la funcion para comprobar que el nif tiene el formato correcto y que no existe
    return new Humano(planeta, nif);
}
Extraterrestre *Administracion::altaExtraterrestre(){ //Recoge los datos de un nuevo estraterrestre y reserva memoria
    string planeta = "", nie = "";
    std::cout << "¿Cual es su planeta de residencia?" << std::endl;
    std::cin.ignore(256, '\n');//limpiamos el buffer
    getline(cin, planeta);
    do{
        std::cout << "¿Cual es su NIE?" << std::endl;
        std::cin >> nie;
        std::cin.ignore(256, '\n');//limpiamos el buffer
    }while((comprobarNIE(nie) == false)||(existe_id(nie) == true)); //Se llama a la funcion para comprobar que el nie tiene el formato correcto y que no existe
    return new Extraterrestre(planeta, nie);
}
void Administracion::modificarPropietario(){ //Modifica el planeta de residencia de los propietarios
    string planeta;
    string id;
    std::cout << "¿Cual es la identificación del propietario a modificar?" << std::endl;
    std::cin >> id;
    unsigned int i = 0;
    for(; i<_nPropietarios; i++){
        if(_propietarios[i]->get_id() == id){
            break;
        };
    }
    if(i == _nPropietarios){ //Si el bucle anterior llega al final significa que no exite esa identificacion
        std::cout << "------------------------------------------------------------------------------" << std::endl;
        std::cout << "El número de identificacion no coincide con ningun usuario" << std::endl;
        std::cout << "------------------------------------------------------------------------------" << std::endl;
        std::cout << "" << std::endl;
    }else{
        std::cout << "Planeta de residencia actual: " << _propietarios[i]->get_planeta() << std::endl;
        std::cout << "¿Cual es el nuevo planeta de residencia?" << std::endl;
        std::cin.ignore(256, '\n');//limpiamos el buffer
        getline(cin, planeta);
        _propietarios[i]->set_planeta(planeta);
        system("clear");
        std::cout << "Información actual del propietario" << std::endl;
        std::cout << "------------------------------------------------------------------------------" << std::endl;
        _propietarios[i]->mostrar();
        std::cout << "" << std::endl;
    }
}
void Administracion::bajaPropietario(){ //Elimina un propietario y reajusta el array
    string id;
    std::cout << "¿Cual es la identificación del propietario que desea dar de baja?" << std::endl;
    std::cin >> id;
    unsigned int posicionPropietario;
    unsigned int i;
    for(i = 0; i<_nPropietarios; i++){
        if(_propietarios[i]->get_id() == id){
            posicionPropietario = i;
            break;
        };
    }
    if(i == _nPropietarios){
        std::cout << "------------------------------------------------------------------------------" << std::endl;
        std::cout << "El número de identificacion no coincide con ningun usuario" << std::endl;
        std::cout << "------------------------------------------------------------------------------" << std::endl;
        std::cout << "" << std::endl;
    }else{
        system("clear");
        _propietarios[posicionPropietario]->mostrar();
        if(_nPropietarios == 1){ //Si solo hay un propietario, al eliminarlo no habra ninguno por lo que directamente se borra el array y se libera memoria
            for(unsigned int i=0; i<this->_nPropietarios; i++){
                if (this->_propietarios[i] != NULL){
                    delete this->_propietarios[i]; //Aqui se estaria llamando al destructor de humano/extraterrestre y luego al de propietarios
                }
            }
            if(this->_propietarios != NULL){
                delete[] this->_propietarios; //se librean las direcciones de memoria que ocupaban los punteros del array
            }
        }else{
            Propietario **arrayAuxiliar = new Propietario*[this->_nPropietarios-1]; //Se crea un array donde volcar la informacion
            Propietario **punteroAuxiliar; //Se crea un puntero de punteros para poder liberar memoria mas tarde
            for(unsigned int i = 0; i<_nPropietarios-1; i++){ //Se inicializa a null el nuevo array
                arrayAuxiliar[i] = NULL;
            }
            for(unsigned int i = 0; i<_nPropietarios; i++){ //Se copian los punteros al array auxiliar
                if(posicionPropietario != i){ //Se copian todos menos el que queremos eliminar
                    arrayAuxiliar[((i < posicionPropietario)? i : (i-1))] = _propietarios[i];
                }
            }
            if (this->_propietarios[posicionPropietario] != NULL){
                delete this->_propietarios[posicionPropietario]; //Se libera la memoria que ocupa el propietario a eliminar
            }
            //A continuacion, se copia la direccion de memoria a donde apunta _propietarios, q es la primera posicion del array q contiene los punteros
            //q apuntan a las direcciones de memoria donde estan los porpietarios, a un puntero auxiliar.
            punteroAuxiliar = this->_propietarios;
            //Luego se hace que _propietarios apunte a la primera direccion de memoria del nuevo array mas grande.
            this->_propietarios = arrayAuxiliar;
            //Se pasa la direccion de memoria a la que apuntaba _propietarios, que es la direccion de memoria de la primera posicion del array antiguo.
            arrayAuxiliar = punteroAuxiliar;
            //Por ultimo, se liberan esas direcciones de memoria que contenian los punteros del primer array para que el sistema pueda disponer de ellas
            if(arrayAuxiliar != NULL){
                delete[] arrayAuxiliar;
            }
        }
        std::cout << "********************* Ha sido dado de baja correctamente *********************" << std::endl;
        std::cout << "" << std::endl;
        this->_nPropietarios--;
    }
}
bool Administracion::comprobarNIF(const string nif){ //Comprueba que el nif esta formado por 8 numeros naturales y una letra mayuscula al final
    char NIF [10];
    if(nif.size() > 9){ //El nif solo pueden ser 9 caracteres
        std::cout << "NIF no valido, el NIF debe contener 8 numeros naturales y una letra mayuscula 'NNNNNNNNL'" << std::endl;
        std::cout << "" << std::endl;
        return false;
    }
    strcpy(NIF, nif.c_str()); //Se copia el string en una cadena de caracteres para trabajar mejor con el
    if((NIF[8] < 65)||(NIF[8] > 90)){ //Se comprueba si el ultimo caracter es una letra mayuscula
         std::cout << "NIF no valido, el NIF debe contener 8 numeros naturales y una letra mayuscula 'NNNNNNNNL'" << std::endl;
         std::cout << "" << std::endl;
         return false;
    }else{
         for(int i = 0; i < 8; i++){ //Si lo anterior se cumple, pasa a comprobar que el resto son numeros naturales
             if((NIF[i] < 48)||(NIF[i] > 57)){
                 std::cout << "NIF no valido, el NIF debe contener 8 numeros naturales y una letra mayuscula 'NNNNNNNNL'" << std::endl;
                 std::cout << "" << std::endl;
                 return false;
                 break;
             }
         }
    }
    return true;
}
bool Administracion::comprobarNIE(const string nie){ //Comprueba que el nie esta formado por 9 numeros naturales
    char NIE [10];
    if(nie.size() > 9){ //El nie solo pueden ser 9 caracteres
        std::cout << "NIE no valido, el NIE debe contener 9 numeros naturales 'NNNNNNNNN'" << std::endl;
        std::cout << "" << std::endl;
        return false;
    }
    strcpy(NIE, nie.c_str()); //Se copia el string en una cadena de caracteres para trabajar mejor con el
    for(int i = 0; i < 9; i++){
        if((NIE[i] < 48)||(NIE[i] > 57)){ //Se comprueba que todos los caracteres son numeros naturales
            std::cout << "NIE no valido, el NIE debe contener 9 numeros naturales 'NNNNNNNNN'" << std::endl;
            std::cout << "" << std::endl;
            return false;
            break;
        }
    }
    return true;
}
bool Administracion::existe_id(const string id){ //Comprueba que la id de un propietario (nif o nie) no esta registrada en el sistema
    for(unsigned int i = 0; i<_nPropietarios; i++){
        if(this->_propietarios[i]->get_id() == id){
            std::cout << "La identificación que ha introducido ya existe" << std::endl;
            std::cout << "" << std::endl;
            return true;
            break;
        }
    }
    return false;
}

/////////////////////////////////////////Funciones referentes al menu naves/////////////////////////////////////////
Naves *Administracion::altaNaves(){ //Se selecciona que tipo de nave se va a dar de alta y se llama a la funcion correspondiente
    int opcion;
    string nRegistro = "";
    int maxTripulantes;
    int precio;
    unsigned short propulsion;
    if(_nNaves == 0){ // Si hay cero naves, se crea un primer array de una sola posicion
        this->_naves = new Naves*[this->_nNaves+1];
        for(unsigned int i = 0; i<_nNaves+1; i++){ //Se inicializa el array
            this->_naves[i] = NULL;
        }
    }else{ //Si hay una o mas naves se crea un array auxiliar de n+1 posiciones
        unsigned int i = 0;
        Naves **arrayAuxiliar = new Naves*[this->_nNaves+1]; //Se crea un array donde volcar la informacion
        Naves **punteroAuxiliar; //Se crea un puntero de punteros para poder liberar memoria mas tarde
        for(i = 0; i<_nNaves+1; i++){ //Se inicializa a null el nuevo array
            arrayAuxiliar[i] = NULL;
        }
        for(i = 0; i<_nNaves; i++){ //Se copian los punteros al array auxiliar
            arrayAuxiliar[i] = _naves[i];
        }
        //A continuacion, se copia la direccion de memoria a donde apunta _naves, q es la primera posicion del array q contiene los punteros
        //q apuntan a las direcciones de memoria donde estan las naves, a un puntero auxiliar.
        punteroAuxiliar = this->_naves;
        //Luego se hace que _naves apunte a la primera direccion de memoria del nuevo array mas grande.
        this->_naves = arrayAuxiliar;
        //Se pasa la direccion de memoria a la que apuntaba _naves, que es la direccion de memoria de la primera posicion del array antiguo.
        arrayAuxiliar = punteroAuxiliar;
        //Por ultimo, se liberan esas direcciones de memoria que contenian los punteros del primer array para que el sistema pueda disponer de ellas
        if(arrayAuxiliar != NULL){
            delete[] arrayAuxiliar;
        }
    }
    std::cout << "  ¿Que tipo de nave desea dar de alta?" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "  1 - Estación Espacial" << std::endl;
    std::cout << "  2 - Destructor" << std::endl;
    std::cout << "  3 - Carguero Espacial" << std::endl;
    std::cout << "  4 - Caza" << std::endl;
    opcion = validar(1,4,"");
    system("clear");
    do{
        std::cout << "¿Cual es su matrícula?" << std::endl;
        std::cin >> nRegistro;
        std::cin.ignore(256, '\n');//limpiamos el buffer
    }while((comprobar_nRegistro(nRegistro) == false)||(existe_nRegistro(nRegistro) == true));
    if(opcion != 4){
        maxTripulantes = validar(1,100,"¿Cual es su número máximo de tripulantes?");
    }
    std::cout << "¿Cual es su tipo de propulsion?" << std::endl;
    std::cout << " 1-Motor de curvatura"<< std::endl;
    std::cout << " 2-Compresor de traza"<< std::endl;
    std::cout << " 3-Motor FTL"<< std::endl;
    std::cout << " 4-Velas solares"<< std::endl;
    std::cout << " 5-Motor iónico"<< std::endl;
    propulsion = validar(1,5,"");
    precio = validar(1,1000000,"¿Cual es su precio de venta (en miles de millones de creditos espaciales)?");
    switch(opcion){
        case 1:{
            return this->altaEstacionEspacial(nRegistro, maxTripulantes, precio, propulsion);
            break;
        }
        case 2:{
            return this->altaDestructor(nRegistro, maxTripulantes, precio, propulsion);
            break;
        }
        case 3:{
            return this->altaCargeroEspacial(nRegistro, maxTripulantes, precio, propulsion);
            break;
        }
        case 4:{
            return this->altaCaza(nRegistro, precio, propulsion);
            break;
        }
        default:{
            break;
        }
    }
    return NULL; //Si por cualquier motivo saliese del bucle devuelve null para no generar una indeterminacion
}
EstacionEspacial *Administracion::altaEstacionEspacial(string nRegistro, int maxTripulantes, int precio, unsigned short propulsion){ //Recoge los datos de una nueva estacion espacial y reserva memoria
    int maxPasajeros;
    int hangares;
    bool escudo;
    string respuestaEscudo;
    maxPasajeros = validar(1,10000,"¿Cual es su capacidad máxima de pasajeros?");
    hangares = validar(0,50,"¿Cuantos hanagres tiene?");
    do{
    std::cout << "¿Tiene escudo de energía? SI/NO" << std::endl;
    std::cin >> respuestaEscudo;
    if(respuestaEscudo != "SI" && respuestaEscudo != "si" && respuestaEscudo != "NO" && respuestaEscudo != "no"){
        std::cout << "Opcion no valida" << std::endl;
        std::cout << "" << std::endl;
    }
    std::cin.ignore(256, '\n');
    }while(respuestaEscudo != "SI" && respuestaEscudo != "si" && respuestaEscudo != "NO" && respuestaEscudo != "no");
    if(respuestaEscudo == "SI" || respuestaEscudo == "si"){
        escudo = 1;
    }else{
        escudo = 0;
    }
    return new EstacionEspacial(nRegistro, "Indefinido", maxTripulantes, precio, propulsion, maxPasajeros, hangares, escudo);
    //Las naves se crean sin un id de propietario, el cual se se asigna si es comprada
}
Destructor *Administracion::altaDestructor(string nRegistro, int maxTripulantes, int precio, unsigned short propulsion){ //Recoge los datos de un nuevo destructor y reserva memoria
    Armamento destructor;
    destructor.pedirArmas(); //LLama a la funcion de armamento para introducir las armas por teclado
    return new Destructor(nRegistro, "Indefinido", maxTripulantes, precio, propulsion, destructor);
}
Caza *Administracion::altaCaza(string nRegistro, int precio, unsigned short propulsion){ //Recoge los datos de un nuevo caza y reserva memoria
    int maxVelocidad;
    maxVelocidad = validar(1,300000,"¿Cual es la velocidad máxima (en km/h)?");
    Armamento caza;
    caza.pedirArmas(); //LLama a la funcion de armamento para introducir las armas por teclado
    return new Caza(nRegistro, "Indefinido", 1, precio, propulsion, maxVelocidad, caza);

}
CargeroEspacial *Administracion::altaCargeroEspacial(string nRegistro, int maxTripulantes, int precio, unsigned short propulsion){ //Recoge los datos de un nuevo cargero espacial y reserva memoria
    int maxCarga;
    int velocidadCrucero;
    bool escudo;
    string respuestaEscudo;
    maxCarga = validar(1,10000,"¿Cual es su capacidad máxima de carga (en toneladas)?");
    velocidadCrucero = validar(1,10000,"¿Cual es su velocidad de crucero (en km/h)?");
    do{
    std::cout << "¿Tiene escudo de energía? SI/NO" << std::endl;
    std::cin >> respuestaEscudo;
    if(respuestaEscudo != "SI" && respuestaEscudo != "si" && respuestaEscudo != "NO" && respuestaEscudo != "no"){
        std::cout << "Opcion no valida" << std::endl;
        std::cout << "" << std::endl;
    }
    std::cin.ignore(256, '\n');
    }while(respuestaEscudo != "SI" && respuestaEscudo != "si" && respuestaEscudo != "NO" && respuestaEscudo != "no");
    if(respuestaEscudo == "SI" || respuestaEscudo == "si"){
        escudo = 1;
    }else{
        escudo = 0;
    }
    return new CargeroEspacial(nRegistro, "Indefinido", maxTripulantes, precio, propulsion, maxCarga, velocidadCrucero, escudo);
}
void Administracion::modificarNave(){ //Busca la nave a modificar y llama al metodo modificar de la nave correspondiente
    string nRegistro, repeticion;
    unsigned int i = 0;
    std::cout << "¿Cual es la matrícula de la nave que desea modificar?" << std::endl;
    std::cin >> nRegistro;
    for(; i<_nNaves; i++){ //Busca la nave
        if(_naves[i]->get_numeroRegistro() == nRegistro){
            break;
        }
    }
    if(i == _nNaves){ //Si el bucle anterior llega al final es que no existe esa nave
        std::cout << "------------------------------------------------------------------------------" << std::endl;
        std::cout << "El número de registro no coincide con ninguna nave" << std::endl;
        std::cout << "------------------------------------------------------------------------------" << std::endl;
        std::cout << "" << std::endl;
    }else{
        std::cout << "Nave de tipo -> ";
        _naves[i]->mostrarTipo(1);
        std::cout << "" << std::endl;
        std::cout << "" << std::endl;
        do{
            _naves[i]->modificar();
            do{
                std::cout << "" << std::endl;
                std::cout << "¿Desea modificar otro parametro de esta nave? SI/NO" << std::endl;
                std::cin >> repeticion;
                if(repeticion != "SI" && repeticion != "si" && repeticion != "NO" && repeticion != "no"){
                    std::cout << "Opcion no valida" << std::endl;
                    std::cout << "" << std::endl;
                }
            }while(repeticion != "SI" && repeticion != "si" && repeticion != "NO" && repeticion != "no");
        }while(repeticion == "SI" || repeticion == "si");
        system("clear");
        std::cout << "Los datos actuales de la nave son:" << std::endl;
        _naves[i]->mostrar(); //Se muestra la informacion actual de la nave
    }
}
void Administracion::bajaNave(){ //Elimina una nave y reajusta el array
    string nRegistro;
    std::cout << "¿Cual es la matrícula de la nave que desea dar de baja?" << std::endl;
    std::cin >> nRegistro;
    unsigned int posicionNave;
    unsigned int i;
    for(i = 0; i<_nNaves; i++){
        if(_naves[i]->get_numeroRegistro() == nRegistro){
            posicionNave = i;
            break;
        };
    }
    if(i == _nNaves){
        std::cout << "------------------------------------------------------------------------------" << std::endl;
        std::cout << "El número de identificacion no coincide con ningun usuario" << std::endl;
        std::cout << "------------------------------------------------------------------------------" << std::endl;
        std::cout << "" << std::endl;
    }else{
        system("clear");
        _naves[posicionNave]->mostrar();
        if(_nNaves == 1){ //Si solo hay una nave, al eliminarla no habra ninguna por lo que directamente se borra el array y se libera memoria
            for(unsigned int i=0; i<this->_nNaves; i++){
                if (this->_naves[i] != NULL){
                    delete this->_naves[i]; //Aqui se estaria llamando al destructor de caza/destructor/etc y luego al de naves
                }
            }
            if(this->_naves != NULL){
                delete[] this->_naves; //se librean las direcciones de memoria que ocupaban los punteros del array
            }
        }else{
            Naves **arrayAuxiliar = new Naves*[this->_nNaves-1]; //Se crea un array donde volcar la informacion
            Naves **punteroAuxiliar; //Se crea un puntero de punteros para poder liberar memoria mas tarde
            for(unsigned int i = 0; i<_nNaves-1; i++){ //Se inicializa a null el nuevo array
                arrayAuxiliar[i] = NULL;
            }
            for(unsigned int i = 0; i<_nNaves; i++){ //Se copian los punteros al array auxiliar
                if(posicionNave != i){ //Se copian todas las naves menos la especificada
                    arrayAuxiliar[((i < posicionNave)? i : (i-1))] = _naves[i];
                }
            }
            if (this->_naves[posicionNave] != NULL){
                delete this->_naves[posicionNave]; //Se libera la memoria que ocupa la nave a eliminar
            }
            //A continuacion, se copia la direccion de memoria a donde apunta _naves, q es la primera posicion del array q contiene los punteros
            //q apuntan a las direcciones de memoria donde estan las naves, a un puntero auxiliar.
            punteroAuxiliar = this->_naves;
            //Luego se hace que _naves apunte a la primera direccion de memoria del nuevo array mas grande.
            this->_naves = arrayAuxiliar;
            //Se pasa la direccion de memoria a la que apuntaba _naves, que es la direccion de memoria de la primera posicion del array antiguo.
            arrayAuxiliar = punteroAuxiliar;
            //Por ultimo, se liberan esas direcciones de memoria que contenian los punteros del primer array para que el sistema pueda disponer de ellas
            if(arrayAuxiliar != NULL){
                delete[] arrayAuxiliar;
            }
        }
        std::cout << "********************* Ha sido dada de baja correctamente *********************" << std::endl;
        std::cout << "" << std::endl;
        this->_nNaves--;
    }
}
bool Administracion::comprobar_nRegistro(const string registro){ //Comprueba si la matricula tiene el formato correcto LNNNNLLL
    char aux [9];
    if(registro.size() > 8){ //La matricula solo pueden ser 8 caracteres
        std::cout << "Matrícula no valida, debe contener 4 numeros naturales y 4 letras mayusculas en este formato 'LNNNNLLL'" << std::endl;
        std::cout << "" << std::endl;
        return false;
    }
    strcpy(aux, registro.c_str()); //Se transforma el string en char para trabajar mejor con el
    if((aux[0] < 65)||(aux[0] > 90)){ //Se comprueba que el primer caracter es una letra mayuscula
         std::cout << "Matrícula no valida, debe contener 4 numeros naturales y 4 letras mayusculas en este formato 'LNNNNLLL'" << std::endl;
         std::cout << "" << std::endl;
         return false;
    }else{ //Si lo anterior se cumple se comprueba el resto
         for(int i = 1; i < 5; i++){
             if((aux[i] < 48)||(aux[i] > 57)){ //se comprueba que los 4 siguientes son numero naturales
                 std::cout << "Número de registro no valido, debe contener 4 numeros naturales y 4 letras mayusculas en este formato 'LNNNNLLL'" << std::endl;
                 std::cout << "" << std::endl;
                 return false;
                 break;
             }
         }
         for(int i = 5; i < 8; i++){
             if((aux[i] < 65)||(aux[i] > 90)){ //Se comprueba que los tres ultimos son letras mayusculas
                 std::cout << "Número de registro no valido, debe contener 4 numeros naturales y 4 letras mayusculas en este formato 'LNNNNLLL'" << std::endl;
                 std::cout << "" << std::endl;
                 return false;
                 break;
             }
         }

    }
    return true;
}
bool Administracion::existe_nRegistro(const string registro){ //Comprueba que la matricula no exsita ya en el sistema
    for(unsigned int i = 0; i<_nNaves; i++){
        if(this->_naves[i]->get_numeroRegistro() == registro){
            std::cout << "La matrícula que ha introducido ya existe" << std::endl;
            std::cout << "" << std::endl;
            return true;
            break;
        }
    }
    return false;
}

/////////////////////////////////////////Funciones de administracion/////////////////////////////////////////
void Administracion::cargarDatos(){//Carga los datos de naves y propietarios desde sus respectivos txt
    string aux;
    string tipoPoropietario, id;
    char planeta[50];
    string tipoNave, nRegistro, propNave, maxTripulantes, precio, propulsion;
    string atr1, atr2, atr3, atr4, atr5;
    ifstream ePropietarios("propietarios.txt", ios::in); //Se abre el fichero de propietarios
    if(ePropietarios.is_open()){ //Se comprueba que el fichero se ha abierto correctamente
        ePropietarios >> _nPropietarios; //el primer dato del archivo es el numero de propietarios que contiene
        ePropietarios >> aux; //Se elimina la palabra propietarios que acompaña al numero
        if(_nPropietarios != 0){
            this->_propietarios = new Propietario*[this->_nPropietarios]; //Se crea un array para guardar los datos del fichero
            for(unsigned int i = 0; i<_nPropietarios; i++){ //Se inicializa el array
                this->_propietarios[i] = NULL;
            }
            for(unsigned int i=0; i<_nPropietarios; i++){
                ePropietarios >> tipoPoropietario >> id;
                ePropietarios.getline(planeta, 50); //Como el planeta puede contener espacios usamos un getline
                for(unsigned int i=0; i<49; i++){ //Como getline coge todos los caracteres, eliminamos el espacio que hay antes del planeta
                    planeta[i] = planeta[i+1];
                }
                if(tipoPoropietario == "Humano"){
                    _propietarios[i] = new Humano(planeta,id);
                }else if(tipoPoropietario == "Extraterrestre"){
                    _propietarios[i] = new Extraterrestre(planeta,id);
                }
            }
        }
    }else{
        std::cout << "Error al cargar los datos de los propietarios" << std::endl;
        std::cout << "" << std::endl;
    }
    ePropietarios.close(); //Se cierra el fichero
    ifstream eNaves("naves.txt", ios::in); //Se abre el fichero que contiene las naves
    if(eNaves.is_open()){ //Se comprueba que se ha abierto correctamente
        eNaves >> _nNaves;
        eNaves >> aux; //Se elimina la palabra naves que acompaña al numero
        if(_nNaves != 0){
            this->_naves = new Naves*[this->_nNaves]; //Se crea un array para guardar los datos del fichero
            for(unsigned int i = 0; i<_nNaves; i++){ //Se inicializa el array
                this->_naves[i] = NULL;
            }
            for(unsigned int i=0; i<_nNaves; i++){
                eNaves >> tipoNave >> nRegistro >> propNave >> maxTripulantes >> precio >> propulsion; //Se leen los atributod generales de las naves
                if(tipoNave == "EstacionEspacial"){
                    eNaves >> atr1 >> atr2 >> atr3; //Se leen los atributos especificos de cada nave
                    _naves[i] = new EstacionEspacial(nRegistro, propNave, atoi(maxTripulantes.c_str()), atoi(precio.c_str()), atoi(propulsion.c_str()), atoi(atr1.c_str()), atoi(atr2.c_str()), atoi(atr3.c_str()));
                }else if(tipoNave == "Destructor"){
                    eNaves >> atr1 >> atr2 >> atr3 >> atr4;
                    Armamento armasDestructor(atoi(atr1.c_str()), atoi(atr2.c_str()), atoi(atr3.c_str()), atoi(atr4.c_str()));
                    _naves[i] = new Destructor(nRegistro, propNave, atoi(maxTripulantes.c_str()), atoi(precio.c_str()), atoi(propulsion.c_str()), armasDestructor);
                }else if(tipoNave == "Caza"){
                    eNaves >> atr1 >> atr2 >> atr3 >> atr4 >> atr5;
                    Armamento armasCaza(atoi(atr2.c_str()), atoi(atr3.c_str()), atoi(atr4.c_str()), atoi(atr5.c_str()));
                    _naves[i] = new Caza(nRegistro, propNave, atoi(maxTripulantes.c_str()), atoi(precio.c_str()), atoi(propulsion.c_str()), atoi(atr1.c_str()), armasCaza);
                }else if(tipoNave == "CargeroEspacial"){
                    eNaves >> atr1 >> atr2 >> atr3;
                    _naves[i] = new CargeroEspacial(nRegistro, propNave, atoi(maxTripulantes.c_str()), atoi(precio.c_str()), atoi(propulsion.c_str()), atoi(atr1.c_str()), atoi(atr2.c_str()), atoi(atr3.c_str()));
                }
            }
        }
    }else{
        std::cout << "Error al cargar los datos de las naves" << std::endl;
        std::cout << "" << std::endl;
    }
    eNaves.close(); //Se cierra el fichero
}
void Administracion::guardarDatos(){//Guarda los datos de naves y propietarios en sus respectivos txt
    remove("propietarios.txt"); //Se eliminan los archivos previos que contien los datos sin actualizar
    remove("naves.txt");
    ofstream sPropietarios("propietarios.txt", ios::out);
    sPropietarios << _nPropietarios << " propietarios" << std::endl; //Se guarda el numero de propietarios que va a contener el fichero
    sPropietarios.close();
    ofstream sNaves("naves.txt", ios::out);
    sNaves << _nNaves << " naves" << std::endl; //Se guarda el numero de naves que va a contener el fichero
    sNaves.close();
    for(unsigned int i=0; i<this->_nPropietarios; i++){
        _propietarios[i]->guardar();
    }
    for(unsigned int i=0; i<this->_nNaves; i++){
        _naves[i]->guardar();
    }
}
string Administracion::fecha(unsigned short formato){ //Devuelve un string con la fecha o la hora segun indique la variable formato
    string Hora, Fecha, HoraFecha;
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    Fecha = std::to_string(timeinfo->tm_mday) + " " + std::to_string(1 + timeinfo->tm_mon) + " " + std::to_string((1900 + timeinfo->tm_year));
    Hora = std::to_string(timeinfo->tm_hour) + " " + std::to_string(timeinfo->tm_min) + " " + std::to_string(timeinfo->tm_sec);
    HoraFecha = Hora + Fecha;
    //HoraFecha = strtok(asctime(timeinfo), "\n");
    //std::cout << "TIME: " << HoraFecha << std::endl;
    //std::cout << Hora << std::endl; //Hora
    //std::cout << Fecha << std::endl;//Fecha
    //std::cout << HoraFecha << std::endl; //Hora y Fecha
    switch (formato) {
    case 0:{
        return Hora;
        break;
    }
    case 1:{
        return Fecha;
        break;
    }
    case 2:{
        return HoraFecha;
        break;
    }
    default:
        break;
    }
    return 0;
}
void Administracion::espera(){ //Espera a que el usuario pulse la tecla intro para cambiar de pantalla
    std::cout << "Pulse intro para continuar...";
    std::cin.get();
    system("clear");
}

/////////////////////////////////////////Destructores/////////////////////////////////////////
Administracion::~Administracion(){
    guardarDatos();
    if(_nPropietarios != 0){ //Si _nPropietarios fuese cero no habria memoria que librerar
        for(unsigned int i=0; i<this->_nPropietarios; i++){
            if (this->_propietarios[i] != NULL){
                delete this->_propietarios[i];
            }
        }
        this->_nPropietarios = 0;
        if(this->_propietarios != NULL){
            delete[] this->_propietarios;
        }
    }
    if(_nNaves != 0){ //Si _nNaves fuese cero no habria memoria que liberar
        for(unsigned int i=0; i<this->_nNaves; i++){
            if (this->_naves[i] != NULL){
                delete this->_naves[i];
            }
        }
        this->_nNaves = 0;
        if(this->_naves != NULL){
            delete[] this->_naves;
        }
    }
}
