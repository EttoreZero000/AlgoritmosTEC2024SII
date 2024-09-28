#include <iostream>
#include <fstream>
#include <string>
#include "claseArmamento.h"
#include <sstream>  // Añadir esta línea

    Arma::Arma():nombre(""), damage(0){}
    Arma::Arma(const std::string& nombre, int damage): nombre(nombre), damage(damage){}

std::string Arma::getNombre() const {  // Asegúrate de que es constante
    return nombre;
}

    void Arma::guardar(std::ofstream& out) {
    out << nombre << "," << damage << "\n";  // Guarda el nombre y el daño separados por coma
}

   void Arma::cargar(std::istream& in) {
    std::string line;
    if (std::getline(in, line)) {
        std::istringstream iss(line);
        std::getline(iss, nombre, ',');
        iss >> damage;
    }
}


int Arma::getDamage(){
    return damage;
}