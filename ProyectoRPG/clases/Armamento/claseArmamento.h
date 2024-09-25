#ifndef ARMAMENTO_H
#define ARMAMENTO_H

#include <string>
#include <vector>
#include <fstream>
#include "listasimple.h"

class Arma {
public:
    int damage;
    std::string nombre;

    // Constructor completo (sin ID)
    Arma(const std::string& nombre, int damage);

    //Métodos varios
    int getDamage();

};
#endif // ARMAMENTO_H
