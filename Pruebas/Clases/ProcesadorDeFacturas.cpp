// ProcesadorDeFacturas.cpp
#include "ProcesadorDeFacturas.h"

bool ProcesadorDeFacturas::abrirArchivoEscritura(bool tipo) {
    if (tipo) {
        archivo.open(nombreArchivo, std::ios::out);
        return archivo.is_open();
    } else {
        archivo.open(nombreArchivo, std::ios::in);
        return archivo.is_open();
    }
}

void ProcesadorDeFacturas::cerrarArchivo() {
    if (archivo.is_open()) {
        archivo.close();
    }
}
