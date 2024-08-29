#ifndef NODO_H
#define NODO_H

template<typename T>
class NodoDoble {
public:
    T dato;
    NodoDoble* siguiente;
    NodoDoble* anterior;

    NodoDoble(T _dato) : dato(_dato), siguiente(nullptr), anterior(nullptr) {}
};

#endif // NODO_H
