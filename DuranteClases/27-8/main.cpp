#include <iostream>
#include <thread>
#include "clase.h"
#include <stack>
#include <conio.h> // Para detectar teclas
#include <windows.h>
#include <cstdlib> // Para rand() y srand()
#include <ctime>   // Para time()

std::stack<Dispositivo> pila;

// Probabilidad de 0.001% para cambiar el estado a "B"
bool probabilidadB() {
    return (rand() % 100000 == 0); // 1 en 100,000
}

void cambiarEstadoLote(std::stack<Dispositivo>& pila, int cantidad, char tipoDispositivo) {
    for (int i = 0; i < cantidad; i++) {
        if (!pila.empty()) {
            Dispositivo dispositivo = pila.top();
            pila.pop();
            if (dispositivo.getTipo() == tipoDispositivo) {
                dispositivo.setEstado('D');
                std::cout << "Dispositivo " << tipoDispositivo << " con estado 'D'\n";
            } else {
                pila.push(dispositivo);
                std::cout << "Dispositivo no es del tipo " << tipoDispositivo << "\n";
            }
        } else {
            std::cout << "No hay dispositivos en la pila\n";
            break;
        }
    }
}

void timer(int sec) {
    Sleep(sec * 1000);
}

void crearDispositivo(char tipo, int time, int& basura) {
    std::string idUnico = Dispositivo::generarIDUnico();
    Dispositivo nuevoDispositivo(idUnico, tipo, 'C', 10);
    pila.push(nuevoDispositivo);
    std::cout << "Dispositivo '" << tipo << "' confeccionado con ID: " << idUnico << "\n";
    timer(time);

    Dispositivo dispositivo = pila.top();
    pila.pop();
    if (probabilidadB()) {
        dispositivo.setEstado('B');  // Cambiar estado a 'B' con 0.001% probabilidad
        basura++;
    } else {
        dispositivo.setEstado('E');
    }
    pila.push(dispositivo);
    std::cout << "Dispositivo '" << tipo << "' enfriamiento\n";
    timer(1);

    Dispositivo topDispositivo = pila.top();
    pila.pop();
    topDispositivo.setEstado('P');
    pila.push(topDispositivo);
    std::cout << "Dispositivo '" << tipo << "' preparado\n";
}

int main() {
    int numeroA = 0, numeroB = 0, numeroC = 0;
    int loteA = 0, loteB = 0, loteC = 0;
    int basura = 0; // Contador de dispositivos marcados como "B" (basura)
    bool creandoA = true, creandoB = false, creandoC = false; // Alternar entre A, B y C
    srand(time(nullptr)); // Inicializar semilla para rand()

    while (true) {
        if (_kbhit()) { // Detectar si hay una tecla presionada
            char tecla = _getch();
            if (tecla == 27) { // Si se presiona ESC
                std::cout << "Producción detenida.\n";
                std::cout << "Estadísticas:\n";
                std::cout << "Dispositivos A creados: " << numeroA << "\n";
                std::cout << "Dispositivos B creados: " << numeroB << "\n";
                std::cout << "Dispositivos C creados: " << numeroC << "\n";
                std::cout << "Lotes A procesados: " << loteA << "\n";
                std::cout << "Lotes B procesados: " << loteB << "\n";
                std::cout << "Lotes C procesados: " << loteC << "\n";
                std::cout << "Cantidad de dispositivos basura (estado B): " << basura << "\n";
                break; // Salir del bucle
            } else if (tecla == 'c') { // Alternar entre A, B, C con la tecla 'c'
                if (creandoA) {
                    creandoA = false;
                    creandoB = true;
                    creandoC = false;
                    std::cout << "Cambiado a B\n";
                } else if (creandoB) {
                    creandoA = false;
                    creandoB = false;
                    creandoC = true;
                    std::cout << "Cambiado a C\n";
                } else if (creandoC) {
                    creandoA = true;
                    creandoB = false;
                    creandoC = false;
                    std::cout << "Cambiado a A\n";
                }
            }
        }

        if (creandoA) {
            std::thread A(crearDispositivo, 'A', 3, std::ref(basura));
            A.join();
            numeroA++;
            if (numeroA % 8 == 0) {
                loteA++;
                cambiarEstadoLote(pila, 8, 'A');
            }
        } else if (creandoB) {
            std::thread B(crearDispositivo, 'B', 4, std::ref(basura));
            B.join();
            numeroB++;
            if (numeroB % 6 == 0) {
                loteB++;
                cambiarEstadoLote(pila, 6, 'B');
            }
        } else if (creandoC) {
            std::thread C(crearDispositivo, 'C', 5, std::ref(basura));
            C.join();
            numeroC++;
            if (numeroC % 10 == 0) {
                loteC++;
                cambiarEstadoLote(pila, 10, 'C');
            }
        }
    }
    return 0;
}
