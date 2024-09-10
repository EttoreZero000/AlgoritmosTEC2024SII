#include <iostream>
#include <conio.h>  // Para _kbhit() y _getch()
#include <windows.h>  // Para COORD
#include <thread>  // Para sleep_for
#include <chrono>  // Para milliseconds
#include "utils.h"
#include "claseMap.h"

bool boolSize(COORD &prevConsoleSize, COORD &consoleSize){
    consoleSize = getConsoleSize();
    if(consoleSize.X != prevConsoleSize.X || consoleSize.Y != prevConsoleSize.Y){
        prevConsoleSize=consoleSize;
        system("cls");
        return true;
    }else{
        return false;
    }
}

// Menú que se actualiza cuando hay un cambio de selección o de tamaño de la consola
int menu(std::string title, std::string (&options)[5], int selectedOption, COORD consoleSize) {
    COORD prevConsoleSize = consoleSize;  // Tamaño previo de la consola
    int prevSelectedOption = -1;  // Para rastrear si hay cambios en la selección

    // Dibujar el menú la primera vez antes de entrar en el bucle
    system("cls");
    printCentered(title, consoleSize.Y / 4, consoleSize);
    for (int i = 0; i < 3; i++) {
        if (i == selectedOption) {
            printCentered("> " + options[i] + " <", (consoleSize.Y / 2) + i, consoleSize);
        } else {
            printCentered(options[i], (consoleSize.Y / 2) + i, consoleSize);
        }
    }

    while (true) {
        // Verificar si el tamaño de la consola ha cambiado
        consoleSize = getConsoleSize();
        if (consoleSize.X != prevConsoleSize.X || consoleSize.Y != prevConsoleSize.Y) {
            prevConsoleSize = consoleSize;  // Actualizar el tamaño previo
            system("cls");  // Limpiar la pantalla

            // Redibujar el título y las opciones centradas
            printCentered(title, consoleSize.Y / 4, consoleSize);
            for (int i = 0; i < 3; i++) {
                if (i == selectedOption) {
                    printCentered("> " + options[i] + " <", (consoleSize.Y / 2) + i, consoleSize);
                } else {
                    printCentered(options[i], (consoleSize.Y / 2) + i, consoleSize);
                }
            }
        }

        if (_kbhit()) { // Si se presiona una tecla
            char key = _getch();
            
            // Navegar con las teclas de flechas
            if (key == 72) { // Flecha hacia arriba
                selectedOption--;
                if (selectedOption < 0) selectedOption = 2; // Volver al final
            } else if (key == 80) { // Flecha hacia abajo
                selectedOption++;
                if (selectedOption > 2) selectedOption = 0; // Volver al inicio
            } else if (key == 13) { // Tecla Enter
                return selectedOption;
               
            }

            // Solo actualizar la pantalla si la selección ha cambiado
            if (selectedOption != prevSelectedOption) {
                prevSelectedOption = selectedOption;

                // Limpiar pantalla y redibujar
                system("cls");

                // Imprimir el título centrado
                printCentered(title, consoleSize.Y / 4, consoleSize);

                // Mostrar las opciones y resaltar la opción seleccionada
                for (int i = 0; i < 3; i++) {
                    if (i == selectedOption) {
                        printCentered("> " + options[i] + " <", (consoleSize.Y / 2) + i, consoleSize);
                    } else {
                        printCentered(options[i], (consoleSize.Y / 2) + i, consoleSize);
                    }
                }
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

int main() {
    COORD consoleSize = getConsoleSize();
    COORD prevConsoleSize = consoleSize;
    SetConsoleOutputCP(CP_UTF8);
    std::string title = "Héroes y Mazmorras";
    std::string options[5] = {"Partida Nueva", "Cargar Partida", "Salir", "Tirar dados", "Armamento"};
    int selectedOption = 0; // Opción seleccionada actualmente
    hideCursor();
    // Ciclo del menú
    selectedOption = menu(title, options, selectedOption, consoleSize);
    if (selectedOption==0){
        selectedOption=3;
        claseMap mapa1(10,1);
        mapa1.generarMapa();
        mapa1.imprimirBox(consoleSize);
        printMenu(options, 3, selectedOption, consoleSize);
        while(true){
            if(boolSize(prevConsoleSize, consoleSize)){
                mapa1.imprimirBox(consoleSize);
                printMenu(options, 3, selectedOption, consoleSize); // Actualiza el índice de inicio
            }
            if(_kbhit()){
        int prevSelectedOption = selectedOption;
        char key = _getch();

        // Movimiento hacia arriba
        if (key == 72) {
            selectedOption--;
            if (selectedOption < 3) selectedOption = 4; // Mantener dentro del rango
        }
        // Movimiento hacia abajo
        else if (key == 80) {
            selectedOption++;
            if (selectedOption > 4) selectedOption = 3; // Mantener dentro del rango
        }
        // Si se presiona Enter, salir del bucle
        else if (key == 13) {
            break;
        }

        // Solo actualizar si la selección ha cambiado
        if (selectedOption != prevSelectedOption) {
            prevSelectedOption = selectedOption;
            system("cls"); // Limpia la pantalla antes de dibujar

            // Imprimir el submenú
            mapa1.imprimirBox(consoleSize);
            printMenu(options, 3, selectedOption, consoleSize);
        }
    }
        }
        //std::cout << consoleSize.Y;
        //std::cout << consoleSize.X;
    }
    system("cls");
    std::cout << selectedOption;
    std::cin.get();
    return 0;
}
