#include <cstdlib>

template <typename T>
class Nodo {
public:
    // Atributos
    T dato;
    Nodo* siguiente;

    // Constructores
    Nodo() : dato(T()), siguiente(NULL) {}

    Nodo(T _dato) : dato(_dato), siguiente(NULL) {}

    Nodo(T _dato, Nodo* _siguiente) : dato(_dato), siguiente(_siguiente) {}
};
