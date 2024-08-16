#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H
#include "nodo.h"

template <typename T>
class ListaSimple {
private:
    // Atributos
    Nodo<T>* inicio;

public:
    // Constructor
    ListaSimple();

    // Métodos
    void insertarAlInicio(const T& _dato);
    void insertarAlFinal(const T& _dato);
    Nodo<T>* buscar(const T& _dato);
    Nodo<T>* eliminar(const T& _dato);
    bool estaVacia() const;
    void imprimir() const; 
};

#endif
