#include "../../clases/Armamento/claseArmamento.h"
#include "../../clases/personajesYEnemigos/enemigos.h"
#include <vector>
#include <sstream>  // Asegúrate de incluir esto para istringstream
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    std::string nombreEnemigo;
    int vida, ataque, oro;
    bool tipoPersonaje, comp;

    std::cout << "Ingrese el nombre del enemigo: ";
    std::getline(std::cin, nombreEnemigo);
    std::cout << "Ingrese vida del enemigo: ";
    std::cin >> vida;
    std::cout << "Ingrese ataque del enemigo: ";
    std::cin >> ataque;

    tipoPersonaje = 0;

    srand(static_cast<unsigned int>(time(0)));
    int probabilidad = rand() % 100;
    comp = (probabilidad < 12);

    std::cout << "Tiene arma (0 para no, 1 para sí): " << comp << std::endl;
    std::cout << "Ingrese oro del enemigo: ";
    std::cin >> oro;

    Arma armaSeleccionada("Vacío", 0);  // Default empty weapon

    // Load weapons from the file if comp is true
    if (comp) {
        std::vector<Arma> armas;
        std::ifstream file("../crearArmas/armas.txt");

        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                std::istringstream iss(line);
                Arma arma;
                arma.cargar(iss);
                armas.push_back(arma);
            }
            file.close();
        }

        if (!armas.empty()) {
            int index = rand() % armas.size();
            armaSeleccionada = armas[index];
        } else {
            std::cerr << "No se cargaron armas desde el archivo.\n";
        }
    }

    // Save the enemy data to a file
    std::ofstream outFile("enemigos.txt", std::ios::app);  // Append mode
    if (outFile.is_open()) {
        outFile << std::endl << nombreEnemigo << "," << vida << "," << ataque
                << "," << 0 << "," << armaSeleccionada.getNombre() << "," << armaSeleccionada.getDamage() << "," << comp 
                << "," << oro;
        outFile.close();
        std::cout << "Datos del enemigo guardados correctamente.\n";
    } else {
        std::cerr << "No se pudo abrir el archivo 'enemigos.txt' para escribir.\n";
    }

    return 0;
}
