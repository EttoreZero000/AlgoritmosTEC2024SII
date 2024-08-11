// main.cpp
#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <string>

#include "ProcesadorDeFacturas.h"

struct Facturas {
    int id;
    std::string descripcion;
    float monto;
    
    friend std::ostream& operator<<(std::ostream& os, const Facturas& factura) {
        os << "ID: " << factura.id << ", Descripción: " << factura.descripcion << ", Monto: " << factura.monto;
        return os;
    }
};

void Prueba1(ProcesadorDeFacturas& procesador) {
    std::vector<Facturas> facturas;
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 10; i++) {
        facturas.push_back({i, "Factura de equipo", 500.0});
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> duration = end - start;
    std::cout << duration.count() << std::endl;
    procesador.escribirEnArchivo(facturas);  // Escribir las facturas en el archivo
    procesador.escribirEnArchivo(duration.count());  // Escribir el tiempo en el archivo
}

int main() {
    ProcesadorDeFacturas procesador;
    procesador.setNombreArchivo("tiempos.txt");
    
    if (!procesador.abrirArchivoEscritura(true)) {
        std::cerr << "No se pudo abrir el archivo para escribir." << std::endl;
        return 1;
    }

    for (int i = 0; i < 20; i++) {
        Prueba1(procesador);
    }

    procesador.cerrarArchivo();
    std::cout << "Listo";
    std::cin.get();
    return 0;
}
