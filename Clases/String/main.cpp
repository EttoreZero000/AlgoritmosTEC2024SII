#include <iostream>

#include "stringUtils.h"
#include "fstream.h"

int main() {

    std::string text = "Hola Mundo";
    std::cout << "Mayúsculas: " << StringUtil::toUpperCase(text) << std::endl;
    std::cout << "Minúsculas: " << StringUtil::toLowerCase(text) << std::endl;
    auto start = chronoStart();
    std::cout << "Vocales mayuscula: " << StringUtil::vocalesMayuscula(text) << std::endl;
    std::cout << "Consonantes mayuscula: " << StringUtil::consonantesMayuscula(text) << std::endl;
    float duration = chronoEnd(start);
    std::cout << "Segundos: " << duration << std::endl;
    std::cin.get();
    return 0;
}
