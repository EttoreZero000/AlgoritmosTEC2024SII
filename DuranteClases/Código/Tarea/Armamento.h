#ifndef ARMAMENTO_H
#define ARMAMENTO_H

#include <string>
#include <vector>

class Armamento {
public:
    int id;
    std::string nombre;
    std::vector<std::string> atributos; // LS / Luz, Agua, Fuego, etc.
    int usos;
    std::string tipo; // Lanza, Espada, etc.
    int numeroDisponible;
    std::vector<int> modificadores; // /Tiros, Peso, Agilidad, Daño, Fuerza, Magia

    Armamento(int id, const std::string& nombre, const std::vector<std::string>& atributos, int usos, const std::string& tipo, int numeroDisponible, const std::vector<int>& modificadores);

    void mostrarInformacion() const;
    void modificarAtributos(const std::vector<int>& nuevosModificadores);
};

#endif // ARMAMENTO_H
