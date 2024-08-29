#include <iostream>
#include "listaDoble.h"

int main() {
    ListaDoble trila;
    int opcion;
    std::string nombre, marca;
    int anioEmision, unidadesDisponibles;
    float precioPorUnidad;

    do {
        std::cout << "\nMenú:\n";
        std::cout << "1. Agregar un juguete\n";
        std::cout << "2. Retirar un juguete de la línea\n";
        std::cout << "3. Vender un juguete\n";
        std::cout << "4. Buscar un juguete por nombre\n";
        std::cout << "5. Mostrar todos los juguetes\n";
        std::cout << "6. Salir\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                std::cout << "Ingrese el nombre del juguete: ";
                std::cin.ignore();
                std::getline(std::cin, nombre);
                std::cout << "Ingrese la marca: ";
                std::getline(std::cin, marca);
                std::cout << "Ingrese el año de emisión: ";
                std::cin >> anioEmision;
                std::cout << "Ingrese el precio por unidad: ";
                std::cin >> precioPorUnidad;
                std::cout << "Ingrese las unidades disponibles: ";
                std::cin >> unidadesDisponibles;
                trila.insertar(Juguete(nombre, marca, anioEmision, precioPorUnidad, unidadesDisponibles));
                break;

            case 2:
                trila.eliminar();
                break;

            case 3:
                std::cout << "Ingrese el nombre del juguete a vender: ";
                std::cin.ignore();
                std::getline(std::cin, nombre);
                trila.venderJuguete(nombre);
                break;

            case 4:
                std::cout << "Ingrese el nombre del juguete a buscar: ";
                std::cin.ignore();
                std::getline(std::cin, nombre);
                trila.buscarJuguete(nombre);
                break;

            case 5:
                trila.mostrarLista();
                break;

            case 6:
                std::cout << "Saliendo del programa...\n";
                break;

            default:
                std::cout << "Opción no válida. Intente de nuevo.\n";
        }

    } while (opcion != 6);

    return 0;
}
