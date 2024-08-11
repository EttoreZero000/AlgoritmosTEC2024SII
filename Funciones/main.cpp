#include <iostream>

#include "funciones.h"

int main() {
    int a = 0;
    std::cout << "Introduce un numero: ";
    std::cin >> a;

    if (esPar(a)) {
        std::cout << "Es par" << std::endl;
    } else {
        std::cout << "Es impar" << std::endl;
    }

    std::cout << "Presione Enter para salir...";
    std::cin.ignore();
    std::cin.get();

    return 0;
}
