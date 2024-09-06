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

// Menú que se actualiza cuando hay un cambio de selección o de tamaño de la consola
void menu(std::string title, std::string (&options)[3], int selectedOption) {
    COORD consoleSize = getConsoleSize();
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
                system("cls");
                printCentered("Opción seleccionada: " + options[selectedOption], consoleSize.Y / 2, consoleSize);
                printCentered("Puto el que lo lea", consoleSize.Y / 2 + 1, consoleSize);
                printCentered("1234567890", consoleSize.Y -1, consoleSize);
                printCentered("0987654321", 0, consoleSize);
                std::cout << consoleSize.Y;
                std::cout << consoleSize.X;
                std::cin.get(); // Esperar a que se presione una tecla
                break; // Salir del ciclo al seleccionar una opción
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

        // Pausa breve para evitar alto uso de CPU
        std::this_thread::sleep_for(std::chrono::milliseconds(0));
    }
}

int main() {
    std::string title = "Heroes y Mazmorras";
    std::string options[3] = {"Partida Nueva", "Cargar Partida", "Salir"};
    int selectedOption = 0; // Opción seleccionada actualmente
    hideCursor();
    // Ciclo del menú
    menu(title, options, selectedOption);
    return 0;
}
