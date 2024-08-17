#include <iostream>
#include "listasimple.h"
#include "claseArmamento.h"

int main() {
    // Crear listas de atributos y modificación
    ListaSimple<bool> atributos;
    atributos.insertarAlInicio(true);
    atributos.insertarAlFinal(true);
    atributos.insertarAlFinal(false);
    atributos.insertarAlFinal(false);
    atributos.insertarAlFinal(false);
    atributos.insertarAlFinal(false);

    ListaSimple<int> modificaciones;
    modificaciones.insertarAlInicio(5);
    modificaciones.insertarAlFinal(6);

    // Crear un objeto Armamento Nombre, atributos, usos, tipo, disponibles, modificaciones
    Armamento arma("Espada Larga", atributos, 10, 1, 5, modificaciones);

    // Imprimir información del objeto Armamento
    std::cout << "Informacion del armamento:" << std::endl;
    arma.imprimir();

    // El objeto `arma` se destruirá automáticamente al final del ámbito de `main`
    std::cin.get();
    return 0;
}
