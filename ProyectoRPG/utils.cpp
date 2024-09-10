// Función para obtener el tamaño de la consola real
#include <iostream>
#include <conio.h>  // Para _kbhit() y _getch()
#include <windows.h>  // Para COORD
#include <thread>  // Para sleep_for
#include <chrono>  // Para milliseconds

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
    int col = (consoleSize.X - text.length()) / 2;  // Calcular la columna para centrar el texto
    COORD pos = { (short)col, (short)row };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    std::cout << text;
}

void printPos(const std::string &text, int row, int col) {
    COORD pos = { (short)col, (short)row };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    std::cout << text;
}

void printMenu(std::string (&options)[5], int startIndex, int &selectedOption, COORD consoleSize) {
    // Recorre las dos opciones disponibles en el submenú
    for (int i = 0; i < 2; i++) {
        int optionIndex = startIndex + i; // Calcula el índice basado en `startIndex`
        if (optionIndex == selectedOption) {
            printCentered("> " + options[optionIndex] + " <", (consoleSize.Y / 1.2) + i, consoleSize); // Puedes ajustar el valor de `consoleSize.Y / 2` para centrar
        } else {
            printCentered(options[optionIndex], (consoleSize.Y / 1.2) + i, consoleSize); // Igualmente ajustar la posición si es necesario
        }
    }
}