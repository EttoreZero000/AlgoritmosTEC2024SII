#include <iostream>
#include <conio.h>  // Para _kbhit() y _getch()
#include <windows.h>  // Para COORD
#include <thread>  // Para sleep_for
#include <chrono>  // Para milliseconds
#include "controladorAcciones.h"
#include "claseMap.h"
//Maximizar la ventana
void maximizar() {
    HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd, WS_MINIMIZE);
}

// Función auxiliar para ocultar el cursor
void hideCursor() { 
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE; // Ocultar el cursor
    SetConsoleCursorInfo(consoleHandle, &info);
}

// Función para obtener el tamaño de la consola real
COORD getConsoleSize() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    COORD size;
    size.X = csbi.srWindow.Right - csbi.srWindow.Left + 1; // Columnas
    size.Y = csbi.srWindow.Bottom - csbi.srWindow.Top + 1; // Filas
    return size;
}

// Función para imprimir un texto centrado en una fila específica
void printCentered(const std::string &text, int row, COORD consoleSize) {
    int col = (consoleSize.X - text.length()) / 2;
    COORD pos = { (short)col, (short)row };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    std::cout << text;
}

// Imprime un texto en una posición específica
void printPos(const std::string &text, int row, int col) {
    COORD pos = { (short)col, (short)row };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    std::cout << text;
}

// Función auxiliar para mostrar el menú rápidamente
void printMenu(std::string (&options)[5], int startIndex, int &selectedOption, COORD consoleSize, int cantidadLista) {
    for (int i = 0; i < cantidadLista; i++) {
        int optionIndex = startIndex + i;
        if (optionIndex == selectedOption) {
            printCentered("> " + options[optionIndex] + " <", (consoleSize.Y / 1.2) + i, consoleSize);
        } else {
            printCentered(options[optionIndex], (consoleSize.Y / 1.2) + i, consoleSize);
        }
    }
}

// Mostrar la historia
void verHistoria(COORD consoleSize){
    system("cls");
    printCentered("Thorfinn es un vikingo que quiere matar a sus enemigos por ver sangre de sus enemigos.", consoleSize.Y/2, consoleSize);
    Sleep(1000);
    printCentered("Thorfinn viaja a un calabozo para matar a los enemigos más fuertes.", consoleSize.Y/2+2, consoleSize);
    printCentered("Para demostrar a su padre que su hijo es el más fuerte del planeta.", consoleSize.Y/2+3, consoleSize);
    Sleep(1000);
    printPos("Preciono Z o A para continuar", consoleSize.Y, consoleSize.X-29);
    while (true){
        if(controladorInput()==5){
            break;
        }
    }
}

// Función que gestiona el tamaño de la consola
bool boolSize(COORD &prevConsoleSize, COORD &consoleSize){
    consoleSize = getConsoleSize();
    if(consoleSize.X != prevConsoleSize.X || consoleSize.Y != prevConsoleSize.Y){
        prevConsoleSize = consoleSize;
        system("cls");
        return true;
    }
    return false;
}

// Menú que se actualiza cuando hay un cambio de selección o de tamaño de la consola
int menu(std::string title, std::string (&options)[5], int selectedOption, COORD consoleSize) {
    COORD prevConsoleSize = consoleSize;
    int prevSelectedOption = -1;

    // Dibujar el menú la primera vez
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
        consoleSize = getConsoleSize();
        if (consoleSize.X != prevConsoleSize.X || consoleSize.Y != prevConsoleSize.Y) {
            prevConsoleSize = consoleSize;
            system("cls");
            printCentered(title, consoleSize.Y / 4, consoleSize);
            for (int i = 0; i < 3; i++) {
                if (i == selectedOption) {
                    printCentered("> " + options[i] + " <", (consoleSize.Y / 2) + i, consoleSize);
                } else {
                    printCentered(options[i], (consoleSize.Y / 2) + i, consoleSize);
                }
            }
        }
        int input = controladorInput();
        if (input > 0) {
            if (input == 2) { // Flecha hacia arriba
                selectedOption--;
                if (selectedOption < 0) selectedOption = 2;
            } else if (input == 1) { // Flecha hacia abajo
                selectedOption++;
                if (selectedOption > 2) selectedOption = 0;
            } else if (input == 5) { // Enter
                return selectedOption;
            }
            if (selectedOption != prevSelectedOption) {
                prevSelectedOption = selectedOption;
                system("cls");
                printCentered(title, consoleSize.Y / 4, consoleSize);
                for (int i = 0; i < 3; i++) {
                    if (i == selectedOption) {
                        printCentered("> " + options[i] + " <", (consoleSize.Y / 2) + i, consoleSize);
                    } else {
                        printCentered(options[i], (consoleSize.Y / 2) + i, consoleSize);
                    }
                }
            }
        }
        Sleep(0);
    }
}


void manejarPartidaNueva(COORD &consoleSize, COORD &prevConsoleSize, std::string (&options)[5], int &selectedOption) {
    // Muestra la historia
    verHistoria(consoleSize);
    
    // Inicializar el mapa
    selectedOption = 3;
    claseMap mapa1(10, 1);
    mapa1.generarMapa();
    mapa1.imprimirBox(consoleSize);
    printMenu(options, 3, selectedOption, consoleSize, 2);

    // Bucle para el manejo del menú
    while (true) {
        // Verifica si el tamaño de la consola ha cambiado
        if (boolSize(prevConsoleSize, consoleSize)) {
            mapa1.imprimirBox(consoleSize);
            printMenu(options, 3, selectedOption, consoleSize, 2);
        }
        
        // Manejo de input
        int input = controladorInput();
        if (input > 0) {
            int prevSelectedOption = selectedOption;
            // Movimiento hacia arriba
            if (input == 2) {
                selectedOption--;
                if (selectedOption < 3) selectedOption = 4; // Mantener dentro del rango
            }
            // Movimiento hacia abajo
            else if (input == 1) {
                selectedOption++;
                if (selectedOption > 4) selectedOption = 3; // Mantener dentro del rango
            }
            // Si se presiona Enter, salir del bucle
            else if (input == 5) {
                break;
            }

            // Solo actualizar si la selección ha cambiado
            if (selectedOption != prevSelectedOption) {
                prevSelectedOption = selectedOption;
                system("cls"); // Limpia la pantalla antes de dibujar
                // Imprimir el submenú
                mapa1.imprimirBox(consoleSize);
                printMenu(options, 3, selectedOption, consoleSize, 2);
            }
        }

        Sleep(0);  // Pausa para no sobrecargar el procesador
    }
}