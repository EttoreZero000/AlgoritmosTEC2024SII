#ifndef PERSONAJEPRINCIPAL_H
#define PERSONAJEPRINCIPAL_H

#include <iostream>
#include "padre.h"
#include "../Armamento/claseArmamento.h"

class personajesHeroes : public padrePersonajes {
public:
    // Constructor de personajesHeroes
    personajesHeroes(std::string nombre, int vida, int ataque, bool tipoPersonaje, Arma arma);
    
    // Métodos
    int givePunch(int damage);
    void setPunch(int damage);
    int setCraps();
};

#endif // PERSONAJEPRINCIPAL_H
