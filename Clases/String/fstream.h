#ifndef FSTREAM_H
#define FSTREAM_H

#include <fstream>
#include <chrono>
#include <vector>
#include <string>

// Función para abrir el archivo
bool abrirArchivoEscritura(std::fstream& archivo, const std::string& nombreArchivo, bool tipo);

// Función para cerrar el archivo
void cerrarArchivo(std::fstream& archivo);

// Función template para manejar vectores
template<typename T>
void escribirEnArchivo(std::fstream& archivo, const std::vector<T>& datos) {
    if (archivo.is_open()) {
        for (const auto& dato : datos) {
            archivo << dato << std::endl;
        }
    }
}
// Función template para manejar tipos generales
template<typename T>
void escribirEnArchivo(std::fstream& archivo, const T& dato) {
    if (archivo.is_open()) {
        archivo << dato << std::endl;
    }
}

std::chrono::time_point<std::chrono::high_resolution_clock> chronoStart();
float chronoEnd(const std::chrono::time_point<std::chrono::high_resolution_clock>& start);

#endif // FSTREAM_H
