#ifndef ARMAMENTO_H
#define ARMAMENTO_H

class Armamento{
    int _canionPlasma;
    int _misiles;
    int _rayoLaser;
    int _PEM;
    int _capacidadDestructiva;
public:
    //Constructores
    Armamento();
    Armamento(int canionPlasma, int misiles, int rayoLaser, int PEM);
    //Modificadores
    void set_canionPlasma(int canionPlasma);
    void set_misiles(int misiles);
    void set_rayoLaser(int rayoLaser);
    void set_pem(int pem);
    void set_capacidadDestructiva(int capacidadDestructiva);
    void pedirArmas();
    //Consultores
    int get_canionPlasma();
    int get_misiles();
    int get_rayoLaser();
    int get_pem();
    int get_capacidadDestructiva();
    void calcular_capacidadDestructiva();
    void mostrar();
    //Destructores
    ~Armamento();
};
#endif // ARMAMENTO_H
