#include <iostream>
#include <fstream>
#include <string>
#include "claseArmamento.h"

    Arma::Arma(): nombre(""), damage(0){}
    Arma::Arma(const std::string& nombre, int damage): nombre(nombre), damage(damage){}

    void Arma::guardar(std::ofstream& out) {
        size_t len = nombre.length();
        out.write(reinterpret_cast<char*>(&len), sizeof(len));
        out.write(nombre.c_str(), len);
        out.write(reinterpret_cast<char*>(&damage), sizeof(damage));
    }

    void Arma::cargar(std::ifstream& in) {
        size_t len = 0;
        in.read(reinterpret_cast<char*>(&len), sizeof(len));
        nombre.resize(len);
        in.read(&nombre[0], len);
        in.read(reinterpret_cast<char*>(&damage), sizeof(damage));
    }

int Arma::getDamage(){
    return damage;
}