// main.cpp
#include <iostream>
#include <windows.h>
#include <string>
#include "utils.h"

int main() {
    maximizar();
    COORD consoleSize = getConsoleSize();
    COORD prevConsoleSize = consoleSize;
    SetConsoleOutputCP(CP_UTF8);
    std::string title = "Héroes y Mazmorras";
    std::string options[5] = {"Partida Nueva", "Cargar Partida", "Salir", "Tirar dados", "Armamento"};
    int selectedOption = 0;
    hideCursor();
    // Llamar a la función menu
    selectedOption = menu(title, options, selectedOption, consoleSize);
    // Manejar la opción seleccionada
    if (selectedOption == 0) {
        manejarPartidaNueva(consoleSize, prevConsoleSize, options, selectedOption);
    }
    system("cls");
    std::cout << selectedOption;
    std::cin.get();
    return 0;
}