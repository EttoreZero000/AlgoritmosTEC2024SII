#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H

#include "Nodo.h"
#include <iostream>


template <typename T>
class ListaSimple {
public:
    ListaSimple();
    //~ListaSimple();

    void insertarAlInicio(T dato);
    void insertarAlFinal(T dato);
    Nodo<T>* buscar(T dato);
    Nodo<T>* eliminar(T dato);
    bool estaVacia() const;
    void imprimir() const;

private:
    Nodo<T>* cabeza; // Puntero al primer nodo
};

#include "ListaSimple.tpp" // Incluye la implementación de las plantillas

#endif // LISTASIMPLE_H
