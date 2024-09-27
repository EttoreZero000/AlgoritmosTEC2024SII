#include "claseArmamento.h"
#include <iostream>


// Constructor completo (sin ID)
Arma::Arma(const std::string& nombre, int damage) : nombre(nombre), damage(damage) {
}

std::string Arma::getNombre(){
    return nombre;
}

int Arma::getDamage() {
    return damage;
}