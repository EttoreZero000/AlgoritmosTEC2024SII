#ifndef ENEMIGOS_H
#define ENEMIGOS_H

#include <iostream>
#include <list>
#include "padre.h"
#include "personajesPrincipales.h"
#include "../Armamento/claseArmamento.h"

class enemigos : public padrePersonajes {
private:
    bool comp;
public:
    // Constructor de personajesHeroes
    enemigos(std::string nombre, int vida, int ataque, bool tipoPersonaje, Arma arma, bool comp, int oro);
    
    // Métodos
    int getPunch(int damage);
    void setPunch(std::list<personajesH> lista);
    Arma getArma();
    int getOro();
};

#endif // ENEMIGOS_H
