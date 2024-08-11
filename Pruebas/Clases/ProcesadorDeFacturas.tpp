#ifndef PROCESADOR_DE_FACTURAS_TPP
#define PROCESADOR_DE_FACTURAS_TPP

#include "ProcesadorDeFacturas.h"

// Implementación de la función template para tipos generales
template<typename T>
void ProcesadorDeFacturas::escribirEnArchivo(const T& dato) {
    if (archivo.is_open()) {
        archivo << dato << std::endl;
    }
}

// Implementación de la función template para vectores
template<typename T>
void ProcesadorDeFacturas::escribirEnArchivo(const std::vector<T>& datos) {
    if (archivo.is_open()) {
        for (const auto& dato : datos) {
            archivo << dato << std::endl;
        }
    }
}

#endif // PROCESADOR_DE_FACTURAS_TPP
