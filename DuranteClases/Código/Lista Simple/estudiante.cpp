#include "Estudiante.h"
#include <iostream>

void Estudiante::imprimir() const {
    std::cout << "Nombre: " << nombre << ", Apellido: " << apellido
              << ", Carrera: " << carrera << ", Fecha de Nacimiento: " << fechaNacimiento << std::endl;
}
