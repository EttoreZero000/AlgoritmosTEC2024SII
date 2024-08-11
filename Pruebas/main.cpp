#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <string>

#include "funciones.h"
#include "funciones_template.h"

struct Facturas {
    int id;
    std::string descripcion;
    float monto;
    // Sobrecarga del operador <<
    friend std::ostream& operator<<(std::ostream& os, const Facturas& factura) {
        os << "ID: " << factura.id << ", Descripción: " << factura.descripcion << ", Monto: " << factura.monto;
        return os;
    }
};


void Prueba1(std::fstream& archivo) {
    std::vector<Facturas> facturas;
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 10; i++) {
        facturas.push_back({i, "Factura de equipo", 500.0});
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> duration = end - start;
    std::cout << duration.count() << std::endl;
    escribirEnArchivo(archivo, facturas);  // Escribir el tiempo en el archivo
    escribirEnArchivo(archivo, duration.count());  // Escribir el tiempo en el archivo
}

int main() {
    std::fstream archivo;
    std::string nombreArchivo = "tiempos.txt";
    
    if (!abrirArchivoEscritura(archivo, nombreArchivo,true)) {
        std::cerr << "No se pudo abrir el archivo para escribir." << std::endl;
        return 1;
    }

    for (int i = 0; i < 20; i++) {
        Prueba1(archivo);
    }

    cerrarArchivo(archivo);
    std::cout << "Listo";
    std::cin.get();
    return 0;
}
