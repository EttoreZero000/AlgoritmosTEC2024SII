#include "claseArmamento.h"
#include <iostream>

int Arma::nextId = 1;
const std::string Arma::idFileName = "next_id.txt";

void Arma::loadNextId() {
    std::ifstream inFile(idFileName);
    if (inFile.is_open()) {
        inFile >> nextId;
        inFile.close();
    } else {
        nextId = 1;
    }
}

void Arma::saveNextId() {
    std::ofstream outFile(idFileName);
    if (outFile.is_open()) {
        outFile << nextId;
        outFile.close();
    } else {
        std::cerr << "Error al abrir el archivo para guardar el ID." << std::endl;
    }
}

// Constructor por defecto
Arma::Arma() 
    : id(nextId++), 
      nombre(""),
      listaAtributos(),
      usos(0),
      tipo(0),
      disponibles(0),
      listaModificadores(),
      damage(0)
{
    saveNextId(); // Guarda el nuevo ID
}

// Constructor completo (sin ID)
Arma::Arma(const std::string& nombre, const ListaSimple<int>& listaAtributos, int usos, int tipo, int disponibles, const ListaSimple<int>& listaModificadores, int damage)
    : id(nextId++),
      nombre(nombre),
      listaAtributos(listaAtributos),
      usos(usos),
      tipo(tipo),
      disponibles(disponibles),
      listaModificadores(listaModificadores),
      damage(damage)
{
    saveNextId(); // Guarda el nuevo valor de nextId
}

// Constructor con ID
Arma::Arma(int id, const std::string& nombre, const ListaSimple<int>& listaAtributos, int usos, int tipo, int disponibles, const ListaSimple<int>& listaModificadores, int damage)
    : id(id),
      nombre(nombre),
      listaAtributos(listaAtributos),
      usos(usos),
      tipo(tipo),
      disponibles(disponibles),
      listaModificadores(listaModificadores),
      damage(damage)
{
    // No incrementamos nextId, ya que se pasa un ID específico
}
int Arma::getId(){
    return id;    
}
void Arma::setAtributos(ListaSimple<int> _listaAtributos){
    listaAtributos=_listaAtributos;
}
void Arma::setModificadores(ListaSimple<int> _listaModificadores){
    listaModificadores=_listaModificadores;
}
void Arma::imprimir() const {
    std::cout << "------------------------------------" << std::endl;
    std::string nombresAtributos[] = {"Oscuridad", "Viento", "Agua", "Tierra", "Fuego", "Luz"};
    std::string nombresModificadores[] = {"Magia", "Fuerza", "Daño", "Agilidad", "Peso", "Tiro"};
    std::string nombresTipos[] = {"Lanza", "Espada", "Varita", "Maza", "Arco", "Hacha"};

    std::cout << "ID: " << id << ", Nombre: " << nombre << ", Tipo: " << nombresTipos[tipo-1] <<", Usos: " << usos << ", Disponibles: " << disponibles << "Damage: " << damage << std::endl;
    
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

int Arma::getDamage(){
    return damage;
}

std::ostream& operator<<(std::ostream& os, const Arma& armamento) {
    armamento.imprimir();
    return os;
}