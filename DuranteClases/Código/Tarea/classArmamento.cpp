// classArmamento.cpp
#include "classArmamento.h"

// Definiciones de atributos estáticos
int Armamento::counter = 0;
bool Armamento::isCounterInitialized = false;

Armamento::Armamento(const std::string& _nombre) : nombre(_nombre) {
    if (!isCounterInitialized) {
        counter = 0;
        isCounterInitialized = true;
    }
    // Resto de la inicialización
}

void Armamento::imprimir() const {
    // Implementa la impresión de `Armamento`
    std::cout << "Nombre: " << nombre << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Armamento& arm) {
    // Implementa cómo quieres mostrar un objeto `Armamento`
    os << "Armamento details: " << arm.nombre; // Ejemplo
    return os;
}
