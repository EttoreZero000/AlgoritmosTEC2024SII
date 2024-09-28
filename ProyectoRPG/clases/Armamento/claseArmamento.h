#ifndef ARMAMENTO_H
#define ARMAMENTO_H

#include <string>
#include <fstream>

class Arma {
public:
    std::string nombre;
    int damage;

    Arma();
    Arma(const std::string& nombre, int damage);
    
    std::string getNombre() const;
    int getDamage();
    void setDamage(int damage);

    void guardar(std::ofstream& out);
    void cargar(std::istream& in);
};

#endif // ARMAMENTO_H
