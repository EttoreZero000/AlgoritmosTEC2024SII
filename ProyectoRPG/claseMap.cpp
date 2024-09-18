#include "claseMap.h"
#include <cstdlib>
#include <ctime>
#include <windows.h>  // Para COORD
#include "utils.h"

claseMap::claseMap(int _size, int _floor)
    : size(_size), floor(_floor), box(_size * _size, ' ') {  // Ajustar el tamaño
}

// Constructor con 'box'
claseMap::claseMap(int _size, int _floor, std::vector<char> _box)
    : size(_size), floor(_floor), box(_box) {
}

// Implementación del método generarMapa
void claseMap::generarMapa() {
    srand(static_cast<unsigned>(time(NULL)));  // Inicializa el generador de números aleatorios
    int elementosInsertados = 0;

    while (elementosInsertados < 10) {
        int numeroRandx = rand() % size;  // Rango ajustado
        int numeroRandy = rand() % size;  // Rango ajustado
        if (numeroRandx != 0 || numeroRandy != 0) {
            int pos = numeroRandy * size + numeroRandx;  // Calcula la posición

            if (pos >= 0 && pos < box.size()) {
                if (box[pos] == ' ') { 
                    box[pos] = 'E';
                    elementosInsertados++;
                }
            }
        }
    }
    
    elementosInsertados = 0;
    while (elementosInsertados < 15) {
        int numeroRandx = rand() % size;  // Rango ajustado
        int numeroRandy = rand() % size;  // Rango ajustado
        if (numeroRandx != 0 || numeroRandy != 0) {
            int pos = numeroRandy * size + numeroRandx;  // Calcula la posición
    
            if (pos >= 0 && pos < box.size()) {
                if (box[pos] == ' ') {  // Verifica si la posición está vacía
                    box[pos] = 'C';  // Guarda 'C' en la posición calculada
                    elementosInsertados++;  // Incrementa el contador solo si se insertó un nuevo elemento
                }
            }
        }
    }
}

void claseMap::imprimirBox(COORD consoleSize) {
    system("cls");
    int h = 3;

    // Construir la línea superior/inferior
    std::string topRow = "   +";
    for (int i = 0; i < size; ++i) {
        topRow += "-----+";
    }

    // Construir la fila de etiquetas de columnas (A-J)
    std::string columnLabels = "    ";
    for (char c = 'A'; c < 'A' + size; ++c) {
        columnLabels += "  ";
        columnLabels += c;
        columnLabels += "   ";
    }

    // Ajustar la posición de la impresión
    int startY = 1;  // Incrementamos en 1 para dejar espacio para las etiquetas de las columnas

    // Imprimir las etiquetas de las columnas
    printCentered(columnLabels, startY - 1, consoleSize);

    // Imprimir la cuadrícula
    for (int i = 0; i < size; ++i) {
        // Imprimir la línea superior de cada fila
        printCentered(topRow, startY + i * h, consoleSize); 

        for (int j = 1; j < h; j++) {
            std::string middleRow = "|";
            for (int k = 0; k < size; ++k) {
                // Aquí decides qué forma imprimir en cada casilla
                std::string forma = "     "; // Espacio en blanco por defecto
                if (j == h / 2) { // Solo imprimir la forma en la fila del medio
                    forma = "  "; // Espacio antes de la forma
                    forma += box[i * size + k]; // Añadir el carácter de la lista
                    forma += "  "; // Espacio después de la forma
                }
                middleRow += forma + "|";
            }
            // Imprimir la etiqueta de la fila antes de la fila del tablero
            if (j == h / 2) {
                std::string rowLabel = std::to_string(i + 1); // Etiqueta de fila (1-10)
                middleRow = rowLabel + (rowLabel.length() == 1 ? "  " : " ") + middleRow; // Ajusta espacio para las etiquetas
            } else {
                middleRow = "   " + middleRow; // Espacio en filas que no son la del medio
            }
            printCentered(middleRow, startY + i * h + j, consoleSize);
        }
    }
    printCentered(topRow, startY + size * h, consoleSize);
}

char claseMap::verCasilla(int x, int y){
    x=x+(y*10);
    return box[x];
}