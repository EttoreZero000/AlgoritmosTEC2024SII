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

void crearMapa(claseMap &mapa, COORD &consoleSize, bool &viewBox) {
    mapa.setFloor();
    mapa.setX(0);
    mapa.setY(0);
    mapa.generarMapa();
    mapa.imprimirBox(consoleSize, viewBox);
}

personajesH crearPersonajePrincipal(std::list<personajesH> &aliados, const std::string &nombre, int fuerza, int agilidad, Arma &arma) {
    personajesH personajeP(nombre, fuerza, agilidad, true, arma, 0);
    aliados.push_front(personajeP);
    return personajeP;
}

int manejarMenu(claseMap &mapa, COORD &consoleSize, std::string (&options)[6], int &selectedOption, bool &viewBox, bool &refresh) {
    int prevSelectedOption = selectedOption;
    
    // Manejo de input
    int input = controladorInput();
    
    if (input > 0) {
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
        // Preciona F1
        else if (input == 10) {
            viewBox = !viewBox;
            refresh = true;
        }

        // Actualizar si la selección ha cambiado o si se requiere refrescar
        if (selectedOption != prevSelectedOption || refresh) {
            refresh = false;
            prevSelectedOption = selectedOption;
            system("cls"); // Limpia la pantalla antes de dibujar
            // Imprimir el submenú
            mapa.imprimirBox(consoleSize, viewBox);
            printMenu(options, 3, selectedOption, consoleSize, 2);
        }
    }
    return 0;
}

void manejarPartidaNueva(COORD &consoleSize, COORD &prevConsoleSize, std::string (&options)[6], int &selectedOption) {
    bool viewBox = false, refresh = false;
    selectedOption = 3;

    // Crear el mapa
    claseMap mapa1(10, 0);
    crearMapa(mapa1, consoleSize, viewBox);

    // Crear arma y personajes
    Arma arma1("Ballesta", 2);
    std::list<personajesH> aliados;
    personajesH personajePrincipal = crearPersonajePrincipal(aliados, "Thorfin", 3, 3, arma1);

    // Imprimir el menú inicial
    printMenu(options, 3, selectedOption, consoleSize, 2);

    // Bucle para el manejo del menú
    while (true) {
        // Verificar si el tamaño de la consola ha cambiado
        if (boolSize(prevConsoleSize, consoleSize) || refresh) {
            refresh=false;
            mapa1.imprimirBox(consoleSize, viewBox);
            printMenu(options, 3, selectedOption, consoleSize, 2);
        }

        // Manejar el menú
        int opcion=manejarMenu(mapa1, consoleSize, options, selectedOption, viewBox, refresh);

        if (opcion == 3) {
            int dado1 = setDados();
            int dado2 = setDados();

            // Mostrar los resultados de los dados en la consola
            std::string dado1String = "Dado 1: " + std::to_string(dado1);
            std::string dado2String = "Dado 2: " + std::to_string(dado2);

            int movimientosRestantes = dado1;  // Comienza con el dado 1
            int input = 0;  // Para almacenar la entrada del controlador
            bool dado1Usado = false;  // Para saber si el dado 1 fue usado
            bool dado2Usado = false;  // Para saber si el dado 2 fue usado

            // Temporizador para evitar que ambos dados se consuman a la vez
            auto ultimoMovimiento = std::chrono::steady_clock::now();

            while (!dado1Usado || !dado2Usado) {
                printPos(dado1String, consoleSize.Y / 2, consoleSize.X / 4);
                printPos(dado2String, consoleSize.Y / 2 + 1, consoleSize.X / 4);
                // Control de tiempo para evitar que se consuman los dados muy rápido
                auto ahora = std::chrono::steady_clock::now();
                std::chrono::duration<double> tiempoPasado = ahora - ultimoMovimiento;

                // Si ha pasado menos de medio segundo, no permitimos un nuevo input
                if (tiempoPasado.count() < 0.2) {
                    continue;  // Esperamos un poco antes de procesar la siguiente entrada
                }

                // Leer entrada del controlador
                input = controladorInput();

                // Mover con dado 1 si aún no se ha usado
                if (!dado1Usado) {
                    if (input == 1) {  // Abajo
                        mapa1.setY(std::min(mapa1.getY() + dado1, 9));  // Mover hacia abajo
                        dado1Usado = true;  // Marcar dado 1 como usado
                    } 
                    else if (input == 2) {  // Arriba
                        mapa1.setY(std::max(mapa1.getY() - dado1, 0));  // Mover hacia arriba
                        dado1Usado = true;
                    } 
                    else if (input == 3) {  // Izquierda
                        mapa1.setX(std::max(mapa1.getX() - dado1, 0));  // Mover a la izquierda
                        dado1Usado = true;
                    } 
                    else if (input == 4) {  // Derecha
                        mapa1.setX(std::min(mapa1.getX() + dado1, 9));  // Mover a la derecha
                        dado1Usado = true;
                    }

                    // Registrar el tiempo del último movimiento
                    ultimoMovimiento = std::chrono::steady_clock::now();
                }

                // Mover con dado 2 si el dado 1 ya fue usado
                else if (dado1Usado && !dado2Usado) {
                    if (input == 1) {  // Abajo
                        mapa1.setY(std::min(mapa1.getY() + dado2, 9));  // Mover hacia abajo
                        dado2Usado = true;  // Marcar dado 2 como usado
                    } 
                    else if (input == 2) {  // Arriba
                        mapa1.setY(std::max(mapa1.getY() - dado2, 0));  // Mover hacia arriba
                        dado2Usado = true;
                    } 
                    else if (input == 3) {  // Izquierda
                        mapa1.setX(std::max(mapa1.getX() - dado2, 0));  // Mover a la izquierda
                        dado2Usado = true;
                    } 
                    else if (input == 4) {  // Derecha
                        mapa1.setX(std::min(mapa1.getX() + dado2, 9));  // Mover a la derecha
                        dado2Usado = true;
                    }

                    // Registrar el tiempo del último movimiento
                    ultimoMovimiento = std::chrono::steady_clock::now();
                }

                // Imprimir la nueva posición del personaje en el mapa
                mapa1.imprimirBox(consoleSize, viewBox);

                // Verificar si ambos dados ya fueron utilizados
                if (dado1Usado && dado2Usado) {
                    refresh=true;
                    break;  // Salir del bucle
                }
            }

            // Mensaje final de la posición del personaje
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