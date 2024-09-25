#ifndef PERSONAJEPRINCIPAL_H
#define PERSONAJEPRINCIPAL_H

#include <iostream>
#include "padre.h"
#include "../Armamento/claseArmamento.h"
#include <list>

class personajesH : public padrePersonajes {
public:
    // Constructor de personajesHeroes
    personajesH(std::string nombre, int vida, int ataque, bool tipoPersonaje, Arma arma, int oro);
    
    // Métodos
    int getPunch();
    void setPunch(int damage);
    void setOro(int oro);
    Arma getArma();
    void setArma(Arma arma);
    
};

#endif // PERSONAJEPRINCIPAL_H
