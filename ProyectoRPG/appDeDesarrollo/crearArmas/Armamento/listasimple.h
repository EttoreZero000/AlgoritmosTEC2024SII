// listasimple.h
#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H

#include "Nodo.h"
#include <iostream>

template <typename T>
class ListaSimple {
public:
    ListaSimple();

    void insertarAlInicio(T dato);
    void insertarAlFinal(T dato);
    Nodo<T>* buscar(int dato);
    Nodo<T>* eliminar(T dato);
    bool estaVacia() const;
    void imprimir() const;
    Nodo<T>* getInicio() const { return inicio; }

private:
    Nodo<T>* inicio; // Puntero al primer nodo
};

// Aquí incluimos la implementación
#include "listasimple.cpp"

#endif // LISTASIMPLE_H
