#include <iostream>
#include <conio.h>    // Para _kbhit() y _getch()
#include <windows.h>  // Para COORD
#include <thread>     // Para sleep_for
#include <chrono>     // Para milliseconds
#include <fstream>    //Guardar y cargar partidas
#include "claseMap.h"
#include "clases/personajesYEnemigos/padre.h"
#include "controladorAcciones.h"
#include "clases/personajesYEnemigos/personajesPrincipales.h"
#include "clases/Armamento/claseArmamento.h"


// Maximizar la ventana
void maximizar() {
    HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd, WS_MINIMIZE);
}

// Número random de 1 a 6
int setDados(){
    srand(static_cast<unsigned>(time(NULL)));
    return rand() % 6 + 1;
}
// Ocultar el cursor
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

// Función para imprimir un texto centrado en una fila específica
void printCentered(const std::string &text, int row, COORD consoleSize) {
    int col = (consoleSize.X - text.length()) / 2;
    COORD pos = { (short)col, (short)row };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    std::cout << text;
}

// Posicionar en X y Y arbitrarias
void printPos(const std::string &text, int row, int col) {
    COORD pos = { (short)col, (short)row };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    std::cout << text;
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

// Función auxiliar para mostrar el menú rápidamente
void printMenu(std::string (&options)[6], int startIndex, int &selectedOption, COORD consoleSize, int cantidadLista) {
    for (int i = 0; i < cantidadLista; i++) {
        int optionIndex = startIndex + i;
        if (optionIndex == selectedOption) {
            printCentered("> " + options[optionIndex] + " <", (consoleSize.Y / 1.2) + i, consoleSize);
        } else {
            printCentered(options[optionIndex], (consoleSize.Y / 1.2) + i, consoleSize);
        }
    }
}

// Menú que se actualiza cuando hay un cambio de selección o de tamaño de la consola
int menu(std::string title, std::string (&options)[6], int selectedOption, COORD consoleSize) {
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


void manejarPartidaNueva(COORD &consoleSize, COORD &prevConsoleSize, std::string (&options)[6], int &selectedOption) {
    // Muestra la historia
    verHistoria(consoleSize);
    bool viewBox=false, refresh=false;

    // Inicializar el mapa
    selectedOption = 3;
    claseMap mapa1(10, 0);
    mapa1.setFloor();
    mapa1.setX(0);
    mapa1.setY(0);
    mapa1.generarMapa();
    mapa1.imprimirBox(consoleSize, viewBox);
    Arma arma1("Ballesta", 2);
    printMenu(options, 3, selectedOption, consoleSize, 2);
    personajesH personajeP("Thorfin", 3, 3, true, arma1, 0);
    std::list<personajesH> ali;  // Lista de aliados
    ali.push_front(personajeP);
    // Bucle para el manejo del menú
    while (true) {
        // Verifica si el tamaño de la consola ha cambiado
        if (boolSize(prevConsoleSize, consoleSize)) {
            mapa1.imprimirBox(consoleSize, viewBox);
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
                return selectedOption;
            }
            //Preciona F1
            else if(input==10){
                viewBox=!viewBox;
                refresh=true;
            }

            // Solo actualizar si la selección ha cambiado
            if (selectedOption != prevSelectedOption || refresh) {
                refresh=false;
                prevSelectedOption = selectedOption;
                system("cls"); // Limpia la pantalla antes de dibujar
                // Imprimir el submenú
                mapa1.imprimirBox(consoleSize, viewBox);
                printMenu(options, 3, selectedOption, consoleSize, 2);
                std::cout << mapa1.Casilla();
            }
            
            if(selectedOption==3){
                srand(static_cast<unsigned>(time(0))); // Inicializa la semilla para rand()
                int dado1=setDados();
                Sleep(200);
                int dado2=setDados();
                std::cout << dado1 << " " <<dado2;
                int movimientoX = 0, movimientoY = 0;
                bool dado1Usado = false;
                bool dado2Usado = false;

                if(dado1>dado2){
                    while(true){
                        if (input == 3) {
                            if (movimientoX == dado1 + dado2) {
                                movimientoX -= dado1;
                                dado1Usado=false;
                            } else if (movimientoX == dado2) {
                                movimientoX = 0;
                                dado2Usado=false;
                            } else if (movimientoX == 0) {
                                movimientoX = -dado2;
                                dado2Usado = true; // Marca dado2 como usado
                            } else if (movimientoX == -dado2) {
                                movimientoX -= dado1;
                                dado1Usado = true; // Marca dado1 como usado
                            }
                        }//if input 3
                        if (input == 4) {
                            if (movimientoX == -dado1 - dado2) {
                                movimientoX += dado1;
                                dado1Usado=false;
                            } else if (movimientoX == -dado2) {
                                movimientoX = 0;
                                dado2Usado=false;
                            } else if (movimientoX == 0) {
                                movimientoX = dado2;
                                dado2Usado = true; // Marca dado2 como usado
                            } else if (movimientoX == dado2) {
                                movimientoX = dado2 + dado1;
                                dado1Usado = true; // Marca dado1 como usado
                            }
                        }//if input 4

                        if (input == 1) {
                            if (movimientoY == dado1 + dado2) {
                                movimientoY -= dado1;
                                dado1Usado=false;
                            } else if (movimientoY == dado2) {
                                movimientoY = 0;
                                dado2Usado=false;
                            } else if (movimientoY == 0) {
                                movimientoY = dado2;
                                dado2Usado = true; // Marca dado2 como usado
                            } else if (movimientoY == dado1) {
                                movimientoY = dado1 + dado2;
                                dado1Usado = true; // Marca dado1 como usado
                            }
                        }//if input 1

                        if (input == 2) {
                            if (movimientoY == -dado1 - dado2) {
                                movimientoY += dado1;
                                dado1Usado=false;
                            } else if (movimientoY == -dado2) {
                                movimientoY = 0;
                                dado2Usado=false;
                            } else if (movimientoY == 0) {
                                movimientoY = -dado2;
                                dado2Usado = true; // Marca dado2 como usado
                            } else if (movimientoY == -dado2) {
                                movimientoY -= dado1;
                                dado1Usado = true; // Marca dado1 como usado
                            }
                        }//if input 2

                        if(input==5){
                            break;
                        }


                    }//while true
                } //If
        }

        Sleep(100);  // Pausa para no sobrecargar el procesador
    }
}

//void guardarProgreso(const std::string& nombreArchivo, int nivel, int puntaje) {
//    std::ofstream archivo(nombreArchivo);
//    if (archivo.is_open()) {
//        archivo << nivel << "\n" << puntaje << "\n";
//        archivo.close();
//    } else {
//        std::cerr << "No se pudo abrir el archivo para guardar." << std::endl;
//    }
//}  
//}