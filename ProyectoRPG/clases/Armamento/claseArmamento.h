#ifndef ARMAMENTO_H
#define ARMAMENTO_H

#include <string>
#include <vector>
#include <fstream>
#include "listasimple.h"

class Arma {
public:
    int id;
    std::string nombre;
    ListaSimple<int> listaAtributos;
    int usos, tipo, disponibles, damage;
    ListaSimple<int> listaModificadores;

    // Constructor por defecto
    Arma();

    // Constructor completo (sin ID)
    Arma(const std::string& nombre, const ListaSimple<int>& listaAtributos, int usos, int tipo, int disponibles, const ListaSimple<int>& listaModificadores, int damage);

    // Constructor con ID
    Arma(int id, const std::string& nombre, const ListaSimple<int>& listaAtributos, int usos, int tipo, int disponibles, const ListaSimple<int>& listaModificadores, int damage);
    // Métodos estáticos para manejar el archivo de ID
    static void loadNextId();
    static void saveNextId();
    //Metodos varios
    int getId();
    int getDamage();
    void setAtributos(ListaSimple<int> listaAtributos);
    void setModificadores(ListaSimple<int> listaModificadores);
    void imprimir() const;

private:
    static int nextId; // Variable estática para generar IDs automáticamente
    static const std::string idFileName; // Nombre del archivo donde se guarda el ID
};
std::ostream& operator<<(std::ostream& os, const Arma& Arma);
#endif // ARMAMENTO_H
