// listasimple.h
#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H

#include "nodoSimple.h"
#include <iostream>

template <typename T>
class ListaSimple {
public:
    ListaSimple();

    void insertarAlInicio(T dato);
    void insertarAlFinal(T dato);
    void insertarMedio(T dato);
    Nodo<T>* buscar(int dato);
    Nodo<T>* eliminar(T dato);
    Nodo<T>* eliminarPosicion(int dato);
    bool estaVacia() const;
    void imprimir() const;
    Nodo<T>* getInicio() const { return inicio; }
    int esPar();

private:
    Nodo<T>* inicio; // Puntero al primer nodo
};

// Aquí incluimos la implementación
#include "listaSimple.cpp"

#endif // LISTASIMPLE_H
