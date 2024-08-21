#include <iostream>
#include <vector>
#include <fstream>
#include "claseArmamento.h"

// Función para guardar el vector de Armamento en un archivo
void guardarVector(const std::vector<Armamento>& vec, const std::string& nombreArchivo) {
    std::ofstream archivoSalida(nombreArchivo, std::ios::binary);
    if (archivoSalida.is_open()) {
        for (const auto& armamento : vec) {
            archivoSalida.write(reinterpret_cast<const char*>(&armamento.id), sizeof(armamento.id));

            size_t nombreSize = armamento.nombre.size();
            archivoSalida.write(reinterpret_cast<const char*>(&nombreSize), sizeof(nombreSize));
            archivoSalida.write(armamento.nombre.c_str(), nombreSize);

            size_t atributosSize = armamento.listaAtributos.size();
            archivoSalida.write(reinterpret_cast<const char*>(&atributosSize), sizeof(atributosSize));
            archivoSalida.write(reinterpret_cast<const char*>(armamento.listaAtributos.data()), atributosSize * sizeof(int));

            archivoSalida.write(reinterpret_cast<const char*>(&armamento.usos), sizeof(armamento.usos));
            archivoSalida.write(reinterpret_cast<const char*>(&armamento.tipo), sizeof(armamento.tipo));
            archivoSalida.write(reinterpret_cast<const char*>(&armamento.disponibles), sizeof(armamento.disponibles));

            size_t modificadoresSize = armamento.listaModificadores.size();
            archivoSalida.write(reinterpret_cast<const char*>(&modificadoresSize), sizeof(modificadoresSize));
            archivoSalida.write(reinterpret_cast<const char*>(armamento.listaModificadores.data()), modificadoresSize * sizeof(int));
        }
        archivoSalida.close();
    } else {
        std::cerr << "No se pudo abrir el archivo para guardar los datos." << std::endl;
    }
}

// Función para cargar el vector de Armamento desde un archivo
std::vector<Armamento> cargarVector(const std::string& nombreArchivo) {
    std::vector<Armamento> vec;
    std::ifstream archivoEntrada(nombreArchivo, std::ios::binary);
    if (archivoEntrada.is_open()) {
        while (archivoEntrada.peek() != EOF) {
            int id;
            std::string nombre;
            int usos, tipo, disponibles;
            std::vector<int> listaAtributos;
            std::vector<int> modificadores;

            archivoEntrada.read(reinterpret_cast<char*>(&id), sizeof(id));

            size_t nombreSize;
            archivoEntrada.read(reinterpret_cast<char*>(&nombreSize), sizeof(nombreSize));
            nombre.resize(nombreSize);
            archivoEntrada.read(&nombre[0], nombreSize);

            size_t atributosSize;
            archivoEntrada.read(reinterpret_cast<char*>(&atributosSize), sizeof(atributosSize));
            listaAtributos.resize(atributosSize);
            archivoEntrada.read(reinterpret_cast<char*>(listaAtributos.data()), atributosSize * sizeof(int));

            archivoEntrada.read(reinterpret_cast<char*>(&usos), sizeof(usos));
            archivoEntrada.read(reinterpret_cast<char*>(&tipo), sizeof(tipo));
            archivoEntrada.read(reinterpret_cast<char*>(&disponibles), sizeof(disponibles));

            size_t modificadoresSize;
            archivoEntrada.read(reinterpret_cast<char*>(&modificadoresSize), sizeof(modificadoresSize));
            modificadores.resize(modificadoresSize);
            archivoEntrada.read(reinterpret_cast<char*>(modificadores.data()), modificadoresSize * sizeof(int));

            vec.emplace_back(id, nombre, listaAtributos, usos, tipo, disponibles, modificadores);
        }
        archivoEntrada.close();
    } else {
        std::cerr << "No se pudo abrir el archivo para cargar los datos." << std::endl;
    }
    return vec;
}

int main() {
    const std::string filename = "armamentos.dat";

    Armamento::loadNextId();

    std::vector<int> modificadores1 = {10, 20, 30};
    std::vector<int> atributos1 = {0, 0, 1};
    Armamento armamento1("Espada Mágica", atributos1, 5, 2, 3, modificadores1);

    std::vector<int> modificadores2 = {15, 25, 35};
    std::vector<int> atributos2 = {1, 0, 0};
    Armamento armamento2("Hacha de Guerra", atributos2, 10, 3, 5, modificadores2);

    std::vector<Armamento> listaArmamento = {armamento1, armamento2};

    guardarVector(listaArmamento, filename);

    std::vector<Armamento> listaCargada = cargarVector(filename);

    for (const auto& armamento : listaCargada) {
        armamento.imprimir();
    }

    return 0;
}
