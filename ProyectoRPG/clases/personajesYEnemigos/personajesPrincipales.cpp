#include <iostream>
#include "../Armamento/claseArmamento.h"
#include "personajesPrincipales.h"

// Definir el constructor de personajesHeroes correctamente
personajesHeroes::personajesHeroes(std::string nombre, int vida, int ataque, bool tipoPersonaje, Arma arma, int oro)
    : padrePersonajes(nombre, vida, ataque, tipoPersonaje, arma, oro) // Llamamos al constructor del padre
{
}

int personajesHeroes::givePunch() {
    return arma.getDamage() + ataque;
}

void personajesHeroes::setPunch(int damage) {
    vida=vida-damage;
}
void personajesHeroes::setOro(int _oro){
    oro=oro+_oro;
}
Arma personajesHeroes::giveArma(){
    return arma;
}
void personajesHeroes::setArma(Arma _arma){
    arma=_arma;
}
int personajesHeroes::setCraps(){
    srand(static_cast<unsigned>(time(NULL)));
    return rand() % 6 + 1;
}