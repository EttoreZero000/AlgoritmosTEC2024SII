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
Armamento::Armamento(const std::string& nombre, const ListaSimple<int>& listaAtributos, int usos, int tipo, int disponibles, const ListaSimple<int>& listaModificadores)
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
Armamento::Armamento(int id, const std::string& nombre, const ListaSimple<int>& listaAtributos, int usos, int tipo, int disponibles, const ListaSimple<int>& listaModificadores)
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
int Armamento::getId(){
    return id;    
}
void Armamento::setAtributos(ListaSimple<int> _listaAtributos){
    listaAtributos=_listaAtributos;
}
void Armamento::setModificadores(ListaSimple<int> _listaModificadores){
    listaModificadores=_listaModificadores;
}
void Armamento::imprimir() const {
    std::cout << "------------------------------------" << std::endl;
    std::string nombresAtributos[] = {"Oscuridad", "Viento", "Agua", "Tierra", "Fuego", "Luz"};
    std::string nombresModificadores[] = {"Magia", "Fuerza", "Daño", "Agilidad", "Peso", "Tiro"};
    std::string nombresTipos[] = {"Lanza", "Espada", "Varita", "Maza", "Arco", "Hacha"};

    std::cout << "ID: " << id << ", Nombre: " << nombre << ", Tipo: " << nombresTipos[tipo-1] <<", Usos: " << usos << ", Disponibles: " << disponibles << std::endl;
    
    std::cout << "Atributos: ";
    Nodo<int>* actualAtributo = listaAtributos.getInicio();  // Método getInicio() debe retornar el primer nodo de la lista
    for (int i = 0; actualAtributo != nullptr && i < 6; ++i) {
        if (actualAtributo->dato == 1) {
            std::cout << nombresAtributos[i] << " ";
        }
        actualAtributo = actualAtributo->siguiente;
    }
    
    std::cout << std::endl;
    std::cout << "Modificadores: ";
    Nodo<int>* actualModificador = listaModificadores.getInicio();
    for (int i = 0; actualModificador != nullptr && i < 6; ++i) {
        std::cout << nombresModificadores[i] << ": " << actualModificador->dato<< ", ";
        actualModificador=actualModificador->siguiente;
    }
    std::cout << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Armamento& armamento) {
    armamento.imprimir();
    return os;
}