#ifndef LISTADOBLECIRCULAR_H
#define LISTADOBLECIRCULAR_H

#include "nodo.h"
#include <iostream>

template<typename T>
class ListaDobleCircular {
private:
    NodoDoble<T>* inicio;
    NodoDoble<T>* final;

public:
    // Constructor
    ListaDobleCircular() : inicio(nullptr), final(nullptr) {}

    // Métodos
    void insertarAlInicio(T _dato);
    void insertarAlFinal(T _dato);
    void insertarEnMedio(T _dato);
    NodoDoble<T>* buscar(T _dato);
    NodoDoble<T>* eliminar(T _dato);
    bool estaVacia();
    void imprimir();
};

#include "listadoblecircular.cpp"

#endif // LISTADOBLECIRCULAR_H
