#ifndef ENEMIGOS_H
#define ENEMIGOS_H

#include <iostream>
#include <list>
#include "padre.h"
#include "personajesPrincipales.h"
#include "../Armamento/claseArmamento.h"

class enemigos : public padrePersonajes {
private:
    bool comp;
public:
    // Constructor de personajesHeroes
    enemigos();
    enemigos(std::string nombre, int vida, int ataque, bool tipoPersonaje, Arma arma, bool comp, int oro);
    
    // Métodos
    int getPunch();
    void setPunch(int damage);
    Arma getArma();
    int getOro();
    int getVida();
    int getComp();
    void guardar(std::ofstream& out);
    std::string getNombre();
    void setDamage(int damage);
    void setVida(int vida);

    void mostrarDatos() const {
        std::cout << "Nombre: " << nombre << "\n"
                  << "Vida: " << vida << "\n"
                  << "Ataque: " << ataque << "\n"
                  << "Tipo de Personaje: " << tipoPersonaje << "\n"
                  << "Compañero: " << comp << "\n"
                  << "Oro: " << oro << "\n";
    }
};

#endif // ENEMIGOS_H
