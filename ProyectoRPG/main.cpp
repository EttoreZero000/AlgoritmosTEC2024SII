// main.cpp
#include <iostream>
#include <windows.h>
#include <string>
#include "utils.h"

int main() {
    maximizar();
    SetConsoleOutputCP(CP_UTF8);
    COORD consoleSize = getConsoleSize();
    COORD prevConsoleSize = consoleSize;
    std::string title = "Héroes y Mazmorras";
    std::string options[6] = {"Partida Nueva", "Cargar Partida", "Salir", "Tirar dados", "Armamento", "Volver al menu"};
    int selectedOption = 0;
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
    system("cls");
    std::cout << selectedOption;
    std::cin.get();

    int posx;

    return 0;
}