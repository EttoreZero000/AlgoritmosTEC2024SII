#include <iostream>
#include "../Armamento/claseArmamento.h"
#include "personajesPrincipales.h"

// Definir el constructor de personajesHeroes correctamente
personajesHeroes::personajesHeroes(std::string nombre, int vida, int ataque, bool tipoPersonaje, Arma arma)
    : padrePersonajes(nombre, vida, ataque, tipoPersonaje, arma) // Llamamos al constructor del padre
{
}

int personajesHeroes::givePunch(int damage) {
    return arma.getDamage() + ataque;
}

void personajesHeroes::setPunch(int damage) {
    vida=vida-damage;
}

int personajesHeroes::setCraps(){
    srand(static_cast<unsigned>(time(NULL)));
    return rand() % 6 + 1;
}