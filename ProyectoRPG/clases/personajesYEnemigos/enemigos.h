#ifndef ENEMIGOS_H
#define ENEMIGOS_H

#include <iostream>
#include <list>
#include "padre.h"
#include "personajesPrincipales.h"
#include "../Armamento/claseArmamento.h"

class enemigos : public padrePersonajes {
public:
    // Constructor de personajesHeroes
    enemigos(std::string nombre, int vida, int ataque, bool tipoPersonaje, Arma arma);
    
    // Métodos
    int givePunch(int damage);
    void setPunch(int damage, std::list<personajesHeroes> lista);
};

#endif // ENEMIGOS_H
