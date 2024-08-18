#ifndef NODO_H
#define NODO_H

template <typename T>
class Nodo {
public:
    T dato; // Dato del nodo
    Nodo* siguiente; // Puntero al siguiente nodo

    Nodo(T d, Nodo* s = nullptr) : dato(d), siguiente(s) {}
};

#endif // NODO_H
