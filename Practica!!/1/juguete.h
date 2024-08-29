#ifndef JUGUETE_H
#define JUGUETE_H

#include <string>

class Juguete {
public:
    std::string nombre;
    std::string marca;
    int anioEmision;
    float precioPorUnidad;
    int unidadesDisponibles;

    Juguete(const std::string& nombre, const std::string& marca, int anioEmision, float precioPorUnidad, int unidadesDisponibles) 
        : nombre(nombre), marca(marca), anioEmision(anioEmision), precioPorUnidad(precioPorUnidad), unidadesDisponibles(unidadesDisponibles) {}

    Juguete() : nombre(""), marca(""), anioEmision(0), precioPorUnidad(0.0f), unidadesDisponibles(0) {}
};

#endif
