#include <iostream>
#include "../Armamento/claseArmamento.h"
#include "enemigos.h"
#include "personajesPrincipales.h"

// Definir el constructor de personajesHeroes correctamente
enemigos::enemigos(std::string nombre, int vida, int ataque, bool tipoPersonaje, Arma arma, bool comp, int oro)
    : padrePersonajes(nombre, vida, ataque, tipoPersonaje, arma, oro) // Llamamos al constructor del padre
{
}
int enemigos::getPunch(int damage) {
    if (comp){
        return arma.getDamage() + ataque;
    }else{
        return ataque;
    }
}
void enemigos::setPunch(std::list<personajesH> lista) {
    if(lista.size() > 1){
        srand(static_cast<unsigned>(time(NULL)));
        std::list<personajesH>::iterator it = lista.begin();
        std::advance(it, rand() % lista.size() + 1);
        personajesH e1 = *it;
        vida = vida - e1.getPunch();
    }else{
        personajesH e1 = lista.front();
        vida = vida - e1.getPunch();
    }
}
Arma enemigos::getArma(){
    return arma;
}
int enemigos::getOro(){
    return oro;
}