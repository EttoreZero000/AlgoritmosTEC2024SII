#include "clase.h"

// Constructor de Veterinaria
Veterinaria::Veterinaria(std::string _especie, std::string _ID)
    : especie(_especie) {
    // Lanzar un error si el ID no tiene exactamente 10 caracteres
    if (_ID.length() != 10) {
        throw std::invalid_argument("Error: El ID debe tener exactamente 10 caracteres.");
    } else {
        ID = _ID; // Asignar el ID si tiene exactamente 10 caracteres
    }
}

// Método para imprimir los datos de la clase
void Veterinaria::print() const {
    std::cout << "Especie: " << especie << " ID: " << ID << "\n";
}