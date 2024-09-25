#ifndef PADRE_H
#define PADRE_H

#include <iostream>
#include "../Armamento/claseArmamento.h"

class padrePersonajes {
protected:
    std::string nombre;
    int vida, ataque, oro;
    bool tipoPersonaje;
    Arma arma;

public:
    // Constructor del padre (si es necesario no borrar)
    padrePersonajes(std::string nombre, int vida, int ataque, bool tipoPersonaje, Arma arma, int _oro)
        : nombre(nombre), vida(vida), ataque(ataque), tipoPersonaje(tipoPersonaje), arma(arma), oro(_oro) {}
};
#endif // PADRE_H
