#include <iostream>
#include <fstream>
#include <chrono>
#include "fstream.h"

// Función para abrir el archivo
bool abrirArchivoEscritura(std::fstream& archivo, const std::string& nombreArchivo, bool tipo) {
    if (tipo) {
        archivo.open(nombreArchivo, std::ios::out);
    } else {
        archivo.open(nombreArchivo, std::ios::in);
    }
    return archivo.is_open();
}

// Función para cerrar el archivo
void cerrarArchivo(std::fstream& archivo) {
    if (archivo.is_open()) {
        archivo.close();
    }
}
// Función para iniciar la medición del tiempo
std::chrono::time_point<std::chrono::high_resolution_clock> chronoStart() {
    return std::chrono::high_resolution_clock::now();
}

// Función para finalizar la medición del tiempo y calcular la duración
float chronoEnd(const std::chrono::time_point<std::chrono::high_resolution_clock>& start) {
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> duration = end - start;
    return duration.count();
}