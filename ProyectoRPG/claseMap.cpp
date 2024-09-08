#include "claseMap.h"
#include <cstdlib>
#include <ctime>
#include <windows.h>  // Para COORD
#include "utils.h"

// Constructor sin 'box'
claseMap::claseMap(int _size, int _floor)
    : size(_size), floor(_floor), box(25, '-') {  // Inicializa 'box' con 25 elementos '-'
}

// Constructor con 'box'
claseMap::claseMap(int _size, int _floor, std::list<char> _box)
    : size(_size), floor(_floor), box(_box) {  // Inicializa 'box' con la lista dada
}

// Implementación del método generarMapa
void claseMap::generarMapa() {
    srand(static_cast<unsigned>(time(NULL)));  // Inicializa el generador de números aleatorios
    int elementosInsertados = 0;

    while (elementosInsertados < 10) {
        int numeroRandx = rand() % 5 + 1;
        int numeroRandy = rand() % 5 + 1;
        int pos = (numeroRandy - 1) * 5 + (numeroRandx - 1);  // Calcula la posición

        auto it = box.begin();
        std::advance(it, pos);  // Avanza el iterador a la posición calculada
        
        if (*it == '-') {  // Verifica si la posición está vacía
            *it = 'E';  // Guarda 'e' en la posición calculada
            elementosInsertados++;  // Incrementa el contador solo si se insertó un nuevo elemento
        }
    }
    elementosInsertados=0;
    while (elementosInsertados < 15) {
        int numeroRandx = rand() % 5 + 1;
        int numeroRandy = rand() % 5 + 1;
        int pos = (numeroRandy - 1) * 5 + (numeroRandx - 1);  // Calcula la posición

        auto it = box.begin();
        std::advance(it, pos);  // Avanza el iterador a la posición calculada
        
        if (*it == '-') {  // Verifica si la posición está vacía
            *it = 'C';  // Guarda 'e' en la posición calculada
            elementosInsertados++;  // Incrementa el contador solo si se insertó un nuevo elemento
        }
    }
}

void claseMap::imprimirBox(COORD consoleSize){
    std::string boxString;
    for (const char& c : box) {
        boxString += c;
    }

    // Imprimir la cadena centrada
    printCentered(boxString, consoleSize.Y / 3, consoleSize);

}