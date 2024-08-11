#ifndef TEMPLATE_FUNCS_H
#define TEMPLATE_FUNCS_H

#include <iostream>
#include <vector>

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

#endif // TEMPLATE_FUNCS_H
