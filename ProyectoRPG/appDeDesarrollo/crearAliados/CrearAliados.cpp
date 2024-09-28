#include "../../clases/personajesYEnemigos/personajesPrincipales.h"
#include <iostream>
#include <vector>
#include <fstream>

int main() {
    std::vector<personajesH> aliados;
    std::ofstream outFile("aliados.txt", std::ios::app);
    if (!outFile.is_open()) {
        std::cerr << "No se pudo abrir o crear el archivo 'aliados.txt' para escribir.\n";
        return 1;
    }
    
    std::cout << "Ingrese la cantidad de aliados a crear: ";
    int cantidad;
    std::cin >> cantidad;
    std::cin.ignore();

    for (int i = 0; i < cantidad; i++) {
        std::string nombre;
        int vida, ataque, oro, vidaMaxima;
        std::cout << "Ingrese el nombre del aliado: ";
        std::getline(std::cin, nombre);
        std::cout << "Ingrese vida del aliado: ";
        std::cin >> vida;
        std::cout << "Ingrese ataque del aliado: ";
        std::cin >> ataque;
        std::cout << "Ingrese oro del aliado: ";
        std::cin >> oro;
        std::cout << "Ingrese vida máxima del aliado: ";
        std::cin >> vidaMaxima;
        std::cin.ignore();

        Arma armaVacia("Vacío", 0);
        personajesH aliado(nombre, vida, ataque, false, armaVacia, oro, vidaMaxima);
        aliados.push_back(aliado);

        outFile << nombre << "," << vida << "," << ataque
                << "," << oro << ",0," << armaVacia.getNombre() << "," << armaVacia.getDamage() << "," << vidaMaxima << std::endl;
        std::cout << "Aliado creado y guardado: " << nombre << std::endl;
    }

    outFile.close();
    std::cout << "Todos los datos han sido guardados en 'aliados.txt'.\n";
    return 0;
}
