#ifndef PERSONAJEPRINCIPAL_H
#define PERSONAJEPRINCIPAL_H

#include <iostream>
#include "padre.h"
#include "../Armamento/claseArmamento.h"

class personajesHeroes : public padrePersonajes {
public:
    // Constructor de personajesHeroes
    personajesHeroes(std::string nombre, int vida, int ataque, bool tipoPersonaje, Arma arma, int oro);
    
    // Métodos
    int givePunch();
    void setPunch(int damage);
    void setOro(int oro);
    Arma giveArma();
    void setArma(Arma arma);
    int setCraps();
};

#endif // PERSONAJEPRINCIPAL_H
