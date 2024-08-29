#ifndef ARMAMENTO_H
#define ARMAMENTO_H

#include <string>

class Vehiculo {
public:
    std::string placa;
    std::string marca;
    std::string modelo; // Cambio a std::vector<int>
    std::string color;
    int year;

    // Constructor por defecto
    Vehiculo();

    // Constructor completo (sin ID)
    Vehiculo(std::string placa, std::string marca, std::string modelo, std::string color, int year);

    // Método para obtener una representación en cadena del objeto
    void imprimir() const;
};
std::ostream& operator<<(std::ostream& os, const Vehiculo& armamento);
#endif // ARMAMENTO_H
