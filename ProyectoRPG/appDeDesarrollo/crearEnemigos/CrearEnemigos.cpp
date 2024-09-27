#include <iostream>
#include <fstream>
#include "../Armamento/claseArmamento.h"
#include "enemigos.h"
#include "personajesPrincipales.h"

// Asumiendo que clase Arma está adecuadamente definida
// Asumiendo que padrePersonajes está adecuadamente definida y tiene un constructor adecuado

// Definiciones previas de enemigos.h y claseArmamento.h son necesarias aquí.

int main() {
    std::string nombre;
    int vida, ataque, oro;
    bool tipoPersonaje, comp;
    std::string nombreArma;
    int danioArma; // Asumiendo que estas son las propiedades de la clase Arma

    std::cout << "Ingrese nombre del enemigo: ";
    std::getline(std::cin, nombre);
    std::cout << "Ingrese vida del enemigo: ";
    std::cin >> vida;
    std::cout << "Ingrese ataque del enemigo: ";
    std::cin >> ataque;
    std::cout << "Es un tipo de personaje especial (0 no, 1 sí): ";
    std::cin >> tipoPersonaje;
    std::cin.ignore(); // Limpiar buffer después de cin a bool
    std::cout << "Ingrese nombre de la arma: ";
    std::getline(std::cin, nombreArma);
    std::cout << "Ingrese daño de la arma: ";
    std::cin >> danioArma;
    std::cout << "Tiene compañía (0 no, 1 sí): ";
    std::cin >> comp;
    std::cout << "Ingrese oro del enemigo: ";
    std::cin >> oro;

    Arma arma(nombreArma, danioArma);  // Asumiendo constructor de Arma
    enemigos enemigo(nombre, vida, ataque, tipoPersonaje, arma, comp, oro);

    // Ahora, escribimos los detalles en un archivo
    std::ofstream archivo("enemigos.txt", std::ios::app); // Abre en modo append
    if (archivo.is_open()) {
        archivo << nombre << "," << vida << "," << ataque << "," << tipoPersonaje << ","
                << nombreArma << "," << danioArma << "," << comp << "," << oro << "\n";
        archivo.close();
        std::cout << "Datos guardados correctamente.\n";
    } else {
        std::cout << "No se pudo abrir el archivo.\n";
    }

    return 0;
}
