#include <iostream>
#include <conio.h>   // Para _getch() y teclas
#include <windows.h> // Para manipular la consola
#include <chrono>    // Para medir tiempos
#include <thread>    // Para pausas

using namespace std;

// Función para obtener el tamaño actual de la consola
void hideCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE; // Ocultar el cursor
    SetConsoleCursorInfo(consoleHandle, &info);
}
COORD getConsoleSize() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns, rows;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left;
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top;
    return { (SHORT)columns, (SHORT)rows };
}
// Función para mover el cursor a una posición específica en la consola
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Función para centrar un texto en una línea específica
void printCentered(string text, int y, COORD consoleSize) {
    int x = (consoleSize.X - text.length()) / 2; // Calcula la posición x centrada
    gotoxy(x, y);
    cout << text;
}

void menu(string title, std::string (&options)[3], int selectedOption, COORD consoleSize){
    while (true) {
        // Obtener el tamaño actual de la consola
        consoleSize = getConsoleSize();

        // Limpiar pantalla
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

        // Detectar la tecla presionada
        if (_kbhit()) { // _kbhit() devuelve verdadero si hay una tecla presionada
            char key = _getch();

            // Navegar con las teclas de flechas
            if (key == 72) { // Flecha hacia arriba
                selectedOption--;
                if (selectedOption < 0) selectedOption = 2; // Volver al final
            } else if (key == 80) { // Flecha hacia abajo
                selectedOption++;
                if (selectedOption > 2) selectedOption = 0; // Volver al inicio
            } else if (key == 13) { // Tecla Enter
                //return selectedOption;
                system("cls");
                printCentered("Opcion seleccionada: " + options[selectedOption], consoleSize.Y / 2, consoleSize);
                printCentered("Puto el que lo lea", consoleSize.Y / 2 + 1, consoleSize);
                break; // Salir del ciclo al seleccionar una opción
            }
        }

        // Pausa breve para evitar alto uso de CPU
        this_thread::sleep_for(chrono::milliseconds(50));
    }
}

int main() {
    string title = "Heroes y Mazmorras";
    string options[3] = {"Partida Nueva", "Cargar Partida", "Salir"};
    int selectedOption = 0; // Opción seleccionada actualmente
    COORD consoleSize;
    hideCursor();
    // Ciclo del menú
    menu(title, options, selectedOption, consoleSize);
    std::cin.get();
    return 0;
}
