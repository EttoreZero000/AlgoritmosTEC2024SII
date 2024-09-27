#ifndef PERSONAJEPRINCIPAL_H
#define PERSONAJEPRINCIPAL_H

#include <iostream>
#include "padre.h"
#include "../Armamento/claseArmamento.h"
#include <list>

class personajesH : public padrePersonajes {
public:
    // Constructor de personajesHeroes
    int vidaMaxima;
    personajesH(std::string nombre, int vida, int ataque, bool tipoPersonaje, Arma arma, int oro, int vidaMaxima);
    
    // Métodos
    int getPunch();
    void setVidaMaxima();
    void setPunch(int damage);
    void setOro(int oro);
    Arma getArma();
    void setArma(Arma arma);
    
    void curarVida();
};

#endif // PERSONAJEPRINCIPAL_H
