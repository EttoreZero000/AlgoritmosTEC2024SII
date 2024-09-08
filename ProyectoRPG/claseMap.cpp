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

void claseMap::imprimirBox(COORD consoleSize) {
    // Construir la línea superior/inferior
    std::string topRow = "+";
    for (int i = 0; i < size; ++i) {
        topRow += "---------------------+";
    }
    // Construir la línea intermedia
    std::string middleRow = "|";
    for (int i = 0; i < size; ++i) {
        middleRow += "                     |";
    }
    // Ajustar la posición de la impresión
    int startY = 0;

    // Imprimir la cuadrícula
    for (int i = 0; i < size; ++i) {
        printCentered(topRow, startY + i * 5, consoleSize); // Línea superior/inferior
        for(int j=1;j<5;j++)
        printCentered(middleRow, startY + i * 5 + j, consoleSize);
    }
    printCentered(topRow, startY + size * 5, consoleSize);

    std::string a;
    for(char c : box){
        a=a+c;
    }
    printCentered(a, startY + size * 5+1, consoleSize);
}
