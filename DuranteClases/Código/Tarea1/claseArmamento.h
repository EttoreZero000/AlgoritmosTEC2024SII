#ifndef ARMAMENTO_H
#define ARMAMENTO_H

#include <string>
#include <fstream> // Necesario para fstream
#include "listasimple.h" // Incluye la cabecera de ListaSimple

class Armamento {
public:
    int id;
    std::string nombre;
    ListaSimple<bool>* listaAtributos;
    int usos;
    int tipo;
    int disponibles;
    ListaSimple<int>* listaModificadores;

    // Constructor por defecto
    Armamento();

    // Constructor completo (sin ID)
    Armamento(const std::string& nombre, ListaSimple<bool>* listaAtributos, int usos, int tipo, int disponibles, ListaSimple<int>* listaModificadores);

    // Destructor
    ~Armamento();

    // Métodos estáticos para manejar el archivo de ID
    static void loadNextId();
    static void saveNextId();

    // Método para obtener una representación en cadena del objeto
    std::string toString() const;
    void imprimir() const;

private:
    static int nextId; // Variable estática para generar IDs automáticamente
    static const std::string idFileName; // Nombre del archivo donde se guarda el ID
};

#endif // ARMAMENTO_H
