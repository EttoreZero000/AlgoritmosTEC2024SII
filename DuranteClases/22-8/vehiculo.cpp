#include "vehiculo.h"
#include <iostream>
#include <string>

Vehiculo::Vehiculo(std::string placa, std::string marca, std::string modelo, std::string color, int year)
    : placa(placa), marca(marca), modelo(modelo), color(color), year(year) {
    // Código adicional si es necesario
}

void Vehiculo::imprimir() const {
    std::cout << "Placa: " << placa 
          << ", Marca: " << marca 
          << ", Modelo: " << modelo 
          << ", Color: " << color 
          << ", Year: " << year << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Vehiculo& armamento) {
    armamento.imprimir();
    return os;
}