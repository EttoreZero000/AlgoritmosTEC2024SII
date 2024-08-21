#ifndef ARMAMENTO_H
#define ARMAMENTO_H

#include <string>
#include <vector>
#include <fstream>

class Armamento {
public:
    int id;
    std::string nombre;
    std::vector<int> listaAtributos; // Cambio a std::vector<int>
    int usos;
    int tipo;
    int disponibles;
    std::vector<int> listaModificadores;

    // Constructor por defecto
    Armamento();

    // Constructor completo (sin ID)
    Armamento(const std::string& nombre, const std::vector<int>& listaAtributos, int usos, int tipo, int disponibles, const std::vector<int>& listaModificadores);

    // Constructor con ID
    Armamento(int id, const std::string& nombre, const std::vector<int>& listaAtributos, int usos, int tipo, int disponibles, const std::vector<int>& listaModificadores);

    // Métodos estáticos para manejar el archivo de ID
    static void loadNextId();
    static void saveNextId();

    // Método para obtener una representación en cadena del objeto
    void imprimir() const;

private:
    static int nextId; // Variable estática para generar IDs automáticamente
    static const std::string idFileName; // Nombre del archivo donde se guarda el ID
};
std::ostream& operator<<(std::ostream& os, const Armamento& armamento);
#endif // ARMAMENTO_H
