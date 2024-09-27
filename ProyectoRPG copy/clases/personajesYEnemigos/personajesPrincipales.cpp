#include <iostream>
#include "../Armamento/claseArmamento.h"
#include "personajesPrincipales.h"

// Definir el constructor de personajesH correctamente
personajesH::personajesH(std::string nombre, int vida, int ataque, bool tipoPersonaje, Arma arma, int oro, int _vidaMaxima)
    : padrePersonajes(nombre, vida, ataque, tipoPersonaje, arma, oro), vidaMaxima(_vidaMaxima) // Llamamos al constructor del padre
{
}

int personajesH::getPunch() {
    return arma.getDamage() + ataque;
}
void personajesH::setVidaMaxima(){
    vidaMaxima+=1;
    vida+=1;
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

void personajesH::curarVida(){
    vida+=(vida*10)/100;
}