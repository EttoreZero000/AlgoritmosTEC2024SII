// listasimple.h
#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H

#include "Nodo.h"
#include <iostream>
#include "vehiculo.h"

template <typename T>
class pilaSimple {
public:
    pilaSimple();

    void insertarAlInicio(T dato);
    void insertarAlFinal(T dato);
    Nodo<T>* eliminar(T dato);
    bool estaVacia() const;
    void imprimir() const;

private:
    Nodo<T>* inicio; // Puntero al primer nodo
};

// Aquí incluimos la implementación
#include "pila.cpp"
#include "vehiculo.cpp"

#endif // LISTASIMPLE_H
