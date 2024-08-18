#include "claseArmamento.h"
#include <iostream>
#include <sstream> // Para std::ostringstream

// Inicializa la variable estática
int Armamento::nextId = 1;
const std::string Armamento::idFileName = "next_id.txt";

// Carga el siguiente ID desde el archivo
void Armamento::loadNextId() {
    std::ifstream inFile(idFileName);
    if (inFile.is_open()) {
        inFile >> nextId;
        inFile.close();
    } else {
        // Archivo no encontrado o no se puede abrir, asignar ID inicial
        nextId = 1;
    }
}

// Guarda el siguiente ID en el archivo
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
      listaAtributos(new ListaSimple<bool>()),
      usos(0),
      tipo(0),
      disponibles(0),
      listaModificadores(new ListaSimple<int>())
{
    saveNextId(); // Guarda el nuevo ID
}

// Constructor completo
Armamento::Armamento(const std::string& nombre, ListaSimple<bool>* listaAtributos, int usos, int tipo, int disponibles, ListaSimple<int>* listaModificadores)
    : id(nextId++), 
      nombre(nombre), 
      listaAtributos(listaAtributos), 
      usos(usos), 
      tipo(tipo), 
      disponibles(disponibles), 
      listaModificadores(listaModificadores) 
{
    saveNextId(); // Guarda el nuevo ID
}

// Destructor
Armamento::~Armamento() {
    delete listaAtributos;
    delete listaModificadores;
}

void Armamento::imprimir() const {
    std::cout << "ID: " << id << std::endl;
    std::cout << "Nombre: " << nombre << std::endl;

    std::cout << "Lista de Atributos (bool): ";
    listaAtributos->imprimir();  // Asume que la clase `ListaSimple` tiene una función `imprimir()`

    std::cout << "Usos: " << usos << std::endl;
    std::cout << "Tipo: " << tipo << std::endl;
    std::cout << "Disponibles: " << disponibles << std::endl;

    std::cout << "Lista de Modificadores (int): ";
    listaModificadores->imprimir();  // Asume que la clase `ListaSimple` tiene una función `imprimir()`
}