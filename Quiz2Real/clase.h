#ifndef CLASE_H
#define CLASE_H

#include <list>
#include <windows.h>
#include <string>
#include <iostream>


// Clase Veterinaria
class Veterinaria {
private:
    std::string especie, ID; // Atributos especie e ID
public:
    Veterinaria(std::string especie, std::string ID);

    std::string getEspecie() const { return especie; }
    std::string getID() const { return ID; }

    void print() const;
};

#endif // CLASE_H
