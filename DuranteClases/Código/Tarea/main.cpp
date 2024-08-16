#include <iostream>
#include "ListaArmas.h"
#include "utils.h"

void mostrarMenu() {
    std::cout << "1. Agregar Arma\n";
    std::cout << "2. Modificar Arma\n";
    std::cout << "3. Sacar Arma\n";
    std::cout << "4. Evolucionar Arma\n";
    std::cout << "5. Salir\n";
}

int main() {
    ListaArmas listaArmas;
    int opcion;

    do {
        mostrarMenu();
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                std::string nombre, tipo;
                int usos, numeroDisponible;
                std::vector<std::string> atributos;
                std::vector<int> modificadores(6, 0); // Tiros, Peso, Agilidad, Daño, Fuerza, Magia

                // Obtener datos del usuario
                std::cout << "Nombre del arma: ";
                std::cin >> nombre;
                // Agregar atributos y modificadores aquí...
                
                // Crear arma
                int id = generarId();
                Armamento arma(id, nombre, atributos, usos, tipo, numeroDisponible, modificadores);
                listaArmas.agregarArma(arma);
                break;
            }
            case 2: {
                int id;
                std::vector<int> nuevosModificadores(6, 0);
                std::cout << "ID del arma a modificar: ";
                std::cin >> id;
                // Obtener nuevos modificadores del usuario...
                listaArmas.modificarArmas(id, nuevosModificadores);
                break;
            }
            case 3: {
                int id;
                std::cout << "ID del arma a sacar: ";
                std::cin >> id;
                listaArmas.sacarArma(id);
                break;
            }
            case 4: {
                int id;
                std::vector<int> nuevosModificadores(6, 0);
                std::cout << "ID del arma a evolucionar: ";
                std::cin >> id;
                // Obtener nuevos modificadores del usuario...
                listaArmas.evolucionarArma(id, nuevosModificadores);
                break;
            }
            case 5:
                break;
            default:
                std::cout << "Opción no válida.\n";
        }
    } while (opcion != 5);

    return 0;
}
