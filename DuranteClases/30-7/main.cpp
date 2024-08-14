#include <iostream>

#include "funciones.h"

int main() {
    std::string a;
    int b,c;
    while(true){    
    std::cout << "Introduce un numero: ";
    std::cin >> a;

    std::cout << "Introduce la base: ";
    std::cin >> b;

    std::cout << "Introduce la base final: ";
    std::cin >> c;

    std::cout << convertirBases(a,b,c) << std::endl;
    if(a=="0"){
        break;
    }
    }

    std::cout << "Presione Enter para salir...";
    std::cin.ignore();
    std::cin.get();

    return 0;
}