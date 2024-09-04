#ifndef NODO_H
#define NODO_H
#include <iostream>

template <typename T>
class NodoCircularDoble {
public:
    T dato;
    NodoCircularDoble* siguiente;
    NodoCircularDoble* anterior;

    NodoCircularDoble(T _dato) : dato(_dato), siguiente(nullptr), anterior(nullptr) {}
};

#endif // NODO_H
