#include "claseMap.h"
#include <cstdlib>
#include <ctime>
#include <windows.h>  // Para COORD
#include "utils.h"

// Constructor sin 'box'
claseMap::claseMap(int _size, int _floor)
    : size(_size), floor(_floor), box(100, '-') { 
}

// Constructor con 'box'
claseMap::claseMap(int _size, int _floor, std::list<char> _box)
    : size(_size), floor(_floor), box(_box) {
}

// Implementación del método generarMapa
void claseMap::generarMapa() {
    srand(static_cast<unsigned>(time(NULL)));  // Inicializa el generador de números aleatorios
    int elementosInsertados = 0;

    while (elementosInsertados < 10) {
        int numeroRandx = rand() % 10 + 1;
        int numeroRandy = rand() % 10 + 1;
        if (numeroRandx!=1 || numeroRandy!=1){
            int pos = (numeroRandy - 1) * 10 + (numeroRandx - 1);  // Calcula la posición

            auto it = box.begin();
            std::advance(it, pos);
            if (*it == ' ') { 
                *it = 'E';
                elementosInsertados++;
            }
        }
    }
    elementosInsertados=0;
    while (elementosInsertados < 15) {
        int numeroRandx = rand() % 10 + 1;
        int numeroRandy = rand() % 10 + 1;
        if (numeroRandx!=1 || numeroRandy!=1){
            int pos = (numeroRandy - 1) * 10 + (numeroRandx - 1);  // Calcula la posición
    
            auto it = box.begin();
            std::advance(it, pos);  // Avanza el iterador a la posición calculada
                if (*it == ' ') {  // Verifica si la posición está vacía
                    *it = 'C';  // Guarda 'e' en la posición calculada
                    elementosInsertados++;  // Incrementa el contador solo si se insertó un nuevo elemento
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

    // Iterador para recorrer la lista de caracteres
    auto it = box.begin();

    // Imprimir la cuadrícula
    for (int i = 0; i < size; ++i) {
        // Imprimir la línea superior de cada fila
        printCentered(topRow, startY + i * h, consoleSize); 

        for (int j = 1; j < h; j++) {
            std::string middleRow = "|";
            for (int k = 0; k < size; ++k) {
                // Aquí decides qué forma imprimir en cada casilla
                std::string forma = "     "; // Espacio en blanco por defecto
                if (j == h / 2 && it != box.end()) { // Solo imprimir la forma en la fila del medio y si hay elementos en la lista
                    forma = "  "; // Espacio antes de la forma
                    forma += *it; // Añadir el carácter de la lista
                    forma += "  "; // Espacio después de la forma
                    ++it; // Mover al siguiente carácter en la lista
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
