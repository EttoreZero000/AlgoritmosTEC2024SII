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
    std::string options[9] = {"Partida Nueva", "Cargar Partida", "Salir", "Tirar dados", "Armamento", "Volver al menu", "Contratar mercenarios", "Evolucionar arma", "Salir"};
    int selectedOption = 0;
    hideCursor();
    // Llamar a la función menu
    while(true){
        selectedOption=0;
        selectedOption = menu(title, options, selectedOption, consoleSize);
        // Manejar la opción seleccionada
        if (selectedOption == 0) {
            verHistoria(consoleSize);
            manejarPartidaNueva(consoleSize, prevConsoleSize, options, selectedOption);
        }else if(selectedOption == 2){
            break;
        }
    }
    system("cls");
    //std::cout << selectedOption;
    //std::cin.get();
    return 0;
}