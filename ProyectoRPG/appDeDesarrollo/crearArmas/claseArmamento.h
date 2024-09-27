#ifndef ARMAMENTO_H
#define ARMAMENTO_H

#include <string>
#include <fstream>

class Arma {
public:
    int damage;
    std::string nombre;

    // Constructor completo
    Arma();
    Arma(const std::string& nombre, int damage);

    //Métodos varios
    std::string getNombre();
    int getDamage();

    void guardar(std::ofstream& out);
    void cargar(std::ifstream& in);

};
#endif // ARMAMENTO_H
