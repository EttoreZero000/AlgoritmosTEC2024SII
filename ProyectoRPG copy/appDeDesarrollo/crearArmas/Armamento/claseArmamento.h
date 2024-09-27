#ifndef ARMAMENTO_H
#define ARMAMENTO_H

#include <string>
#include <vector>
#include <fstream>
#include "listasimple.h"

class Armamento {
public:
    int id;
    std::string nombre;
    ListaSimple<int> listaAtributos;
    int usos;
    int tipo;
    int disponibles;
    ListaSimple<int> listaModificadores;

    // Constructor por defecto
    Armamento();

    // Constructor completo (sin ID)
    Armamento(const std::string& nombre, const ListaSimple<int>& listaAtributos, int usos, int tipo, int disponibles, const ListaSimple<int>& listaModificadores);

    // Constructor con ID
    Armamento(int id, const std::string& nombre, const ListaSimple<int>& listaAtributos, int usos, int tipo, int disponibles, const ListaSimple<int>& listaModificadores);
    // Métodos estáticos para manejar el archivo de ID
    static void loadNextId();
    static void saveNextId();
    //Metodos varios
    int getId();
    void setAtributos(ListaSimple<int> listaAtributos);
    void setModificadores(ListaSimple<int> listaModificadores);
    void imprimir() const;

private:
    static int nextId; // Variable estática para generar IDs automáticamente
    static const std::string idFileName; // Nombre del archivo donde se guarda el ID
};
std::ostream& operator<<(std::ostream& os, const Armamento& armamento);
#endif // ARMAMENTO_H
