// main.cpp
#include <iostream>
#include <windows.h>
#include <string>
#include "utils.h"

int main() {
    int selectedOption = 0;
    COORD consoleSize = getConsoleSize();
    COORD prevConsoleSize = consoleSize;
    std::string title = "Héroes y Mazmorras";
    std::string options[9] = {"Partida Nueva", "Cargar Partida", "Salir", "Tirar dados", "Armamento", "Volver al menu", "Contratar Mercenario", "Evolucionar arma", "Salir"};
    
    maximizar();
    SetConsoleOutputCP(CP_UTF8);    
    hideCursor();

    // Llamar a la función menu
    selectedOption = menu(title, options, selectedOption, consoleSize);
    // Manejar la opción seleccionada
    if (selectedOption == 0) {
        verHistoria(consoleSize);
        manejarPartidaNueva(consoleSize, prevConsoleSize, options, selectedOption);
    }
    //else if (selectedOption == 1) {
    //    break;
    //}
    std::cin.get();
    return 0;
}