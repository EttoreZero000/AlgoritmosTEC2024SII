#include <iostream>
#include "../Armamento/claseArmamento.h"
#include "personajesPrincipales.h"

// Definir el constructor de personajesH correctamente
personajesH::personajesH(std::string nombre, int vida, int ataque, bool tipoPersonaje, Arma arma, int oro)
    : padrePersonajes(nombre, vida, ataque, tipoPersonaje, arma, oro) // Llamamos al constructor del padre
{
}

int personajesH::getPunch() {
    return arma.getDamage() + ataque;
}

void personajesH::setPunch(int damage) {
    vida=vida-damage;
}
void personajesH::setOro(int _oro){
    oro=oro+_oro;
}
Arma personajesH::getArma(){
    return arma;
}
void personajesH::setArma(Arma _arma){
    arma=_arma;
}
