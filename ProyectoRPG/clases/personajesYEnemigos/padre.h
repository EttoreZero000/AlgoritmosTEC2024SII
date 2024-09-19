#ifndef CLASEMAP_H
#define CLASEMAP_H

#include <iostream>
#include "../Armamento/claseArmamento.h"

class padrePersonajes {
protected:
    std::string nombre;
    int vida, ataque;
    bool tipoPersonaje;
    Arma arma;

public:
    // Constructor del padre (si es necesario no borrar)
    padrePersonajes(std::string nombre, int vida, int ataque, bool tipoPersonaje, Arma arma)
        : nombre(nombre), vida(vida), ataque(ataque), tipoPersonaje(tipoPersonaje), arma(arma) {}
};

class personajesHeroes : public padrePersonajes {
public:
    // Constructor de personajesHeroes
    personajesHeroes(std::string nombre, int vida, int ataque, bool tipoPersonaje, Arma arma);
    
    // Métodos
    int givePunch(int damage);
    void setPunch(int damage);
    int setCraps();
};

#endif // CLASEMAP_H
