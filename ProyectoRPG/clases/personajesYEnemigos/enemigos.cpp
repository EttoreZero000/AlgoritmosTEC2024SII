#include <iostream>
#include "../Armamento/claseArmamento.h"
#include "enemigos.h"
#include "personajesPrincipales.h"

// Definir el constructor de personajesHeroes correctamente
enemigos::enemigos(): padrePersonajes("", 0, 0, false, arma, 0), comp(false) // Llamamos al constructor del padre
{
}

// Definir el constructor de personajesHeroes correctamente
enemigos::enemigos(std::string nombre, int vida, int ataque, bool tipoPersonaje, Arma arma, bool _comp, int oro)
    : padrePersonajes(nombre, vida, ataque, tipoPersonaje, arma, oro), comp(_comp) // Llamamos al constructor del padre
{
}
int enemigos::getPunch() {
    if (comp){
        return arma.getDamage() + ataque;
    }else{
        return ataque;
    }
}
void enemigos::setPunch(int damage) {
    vida-=damage;
}
Arma enemigos::getArma(){
    return arma;
}
int enemigos::getOro(){
    return oro;
}
int enemigos::getVida(){
    return vida;
}

int enemigos::getComp(){
    return comp;
}