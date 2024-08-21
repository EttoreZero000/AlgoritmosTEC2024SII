#include "claseArmamento.h"
#include <iostream>

int Armamento::nextId = 1;
const std::string Armamento::idFileName = "next_id.txt";

void Armamento::loadNextId() {
    std::ifstream inFile(idFileName);
    if (inFile.is_open()) {
        inFile >> nextId;
        inFile.close();
    } else {
        nextId = 1;
    }
}

void Armamento::saveNextId() {
    std::ofstream outFile(idFileName);
    if (outFile.is_open()) {
        outFile << nextId;
        outFile.close();
    } else {
        std::cerr << "Error al abrir el archivo para guardar el ID." << std::endl;
    }
}

// Constructor por defecto
Armamento::Armamento() 
    : id(nextId++), 
      nombre(""),
      listaAtributos(),
      usos(0),
      tipo(0),
      disponibles(0),
      listaModificadores()
{
    saveNextId(); // Guarda el nuevo ID
}

// Constructor completo (sin ID)
Armamento::Armamento(const std::string& nombre, const std::vector<int>& listaAtributos, int usos, int tipo, int disponibles, const std::vector<int>& listaModificadores)
    : id(nextId++),
      nombre(nombre),
      listaAtributos(listaAtributos),
      usos(usos),
      tipo(tipo),
      disponibles(disponibles),
      listaModificadores(listaModificadores)
{
    saveNextId(); // Guarda el nuevo valor de nextId
}

// Constructor con ID
Armamento::Armamento(int id, const std::string& nombre, const std::vector<int>& listaAtributos, int usos, int tipo, int disponibles, const std::vector<int>& listaModificadores)
    : id(id),
      nombre(nombre),
      listaAtributos(listaAtributos),
      usos(usos),
      tipo(tipo),
      disponibles(disponibles),
      listaModificadores(listaModificadores)
{
    // No incrementamos nextId, ya que se pasa un ID específico
}

void Armamento::imprimir() const {
    std::cout << "ID: " << id << std::endl;
    std::cout << "Nombre: " << nombre << std::endl;

    std::cout << "Lista de Atributos (int): ";
    for (int atributo : listaAtributos) {
        std::cout << atributo << " ";
    }
    std::cout << std::endl;

    std::cout << "Usos: " << usos << std::endl;
    std::cout << "Tipo: " << tipo << std::endl;
    std::cout << "Disponibles: " << disponibles << std::endl;

    std::cout << "Lista de Modificadores (int): ";
    for (int modificador : listaModificadores) {
        std::cout << modificador << " ";
    }
    std::cout << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Armamento& armamento) {
    armamento.imprimir();
    return os;
}