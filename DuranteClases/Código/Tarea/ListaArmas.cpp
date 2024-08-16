#include "ListaArmas.h"
#include <iostream>
#include <fstream>

Nodo::Nodo(const Armamento& arma) : arma(arma), siguiente(nullptr) {}

ListaArmas::ListaArmas() : cabeza(nullptr), contadorId(1) {
    cargarDesdeDisco();
}

ListaArmas::~ListaArmas() {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        Nodo* siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
}

void ListaArmas::agregarArma(const Armamento& arma) {
    Nodo* nuevo = new Nodo(arma);
    nuevo->siguiente = cabeza;
    cabeza = nuevo;
    guardarEnDisco();
}

void ListaArmas::modificarArmas(int id, const std::vector<int>& nuevosModificadores) {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        if (actual->arma.id == id) {
            actual->arma.modificarAtributos(nuevosModificadores);
            guardarEnDisco();
            return;
        }
        actual = actual->siguiente;
    }
}

void ListaArmas::sacarArma(int id) {
    Nodo* actual = cabeza;
    Nodo* anterior = nullptr;
    while (actual != nullptr) {
        if (actual->arma.id == id) {
            if (anterior != nullptr) {
                anterior->siguiente = actual->siguiente;
            } else {
                cabeza = actual->siguiente;
            }
            delete actual;
            guardarEnDisco();
            return;
        }
        anterior = actual;
        actual = actual->siguiente;
    }
}

void ListaArmas::evolucionarArma(int id, const std::vector<int>& nuevosModificadores) {
    modificarArmas(id, nuevosModificadores);
}

void ListaArmas::mostrarArmas() const {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        actual->arma.mostrarInformacion();
        actual = actual->siguiente;
    }
}

void ListaArmas::guardarEnDisco() {
    std::ofstream archivo("armas.dat", std::ios::binary);
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        archivo.write(reinterpret_cast<char*>(&actual->arma), sizeof(Armamento));
        actual = actual->siguiente;
    }
    archivo.close();
}

void ListaArmas::cargarDesdeDisco() {
    std::ifstream archivo("armas.dat", std::ios::binary);
    if (archivo.is_open()) {
        Armamento arma(0, "", {}, 0, "", 0, {});
        while (archivo.read(reinterpret_cast<char*>(&arma), sizeof(Armamento))) {
            agregarArma(arma);
        }
        archivo.close();
    }
}
