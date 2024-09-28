#include <iostream>
#include <fstream>
#include "claseArmamento.h"  // Asegúrate de que esta ruta y archivo están correctos

int main() {
    std::string nombre;
    int damage;

    std::cout << "Ingrese el nombre de la arma: ";
    std::getline(std::cin, nombre);
    std::cout << "Ingrese el daño de la arma: ";
    std::cin >> damage;

    Arma arma(nombre, damage);  // Creando el objeto arma con los datos ingresados

    // Guardando los datos en un archivo en modo binario
    std::ofstream archivo("armas.bin", std::ios::binary | std::ios::app);
    if (archivo.is_open()) {
        arma.guardar(archivo);  // Usando el método guardar definido en la clase Arma
        archivo.close();
        std::cout << "Datos de la arma guardados correctamente.\n";
    } else {
        std::cout << "No se pudo abrir el archivo para guardar los datos.\n";
    }

    return 0;
}
