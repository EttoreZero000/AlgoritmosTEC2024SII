#include "pila.h"

template <typename T>
pilaSimple<T>::pilaSimple() : inicio(nullptr) {}

template <typename T>
void pilaSimple<T>::insertarAlInicio(T _dato) {
    if (inicio == nullptr)
        inicio = new Nodo<T>(_dato);
    else {
        Nodo<T>* nuevo = new Nodo<T>(_dato);
        nuevo->siguiente = inicio;
        inicio = nuevo;
    }
}

template <typename T>
void pilaSimple<T>::insertarAlFinal(T dato) {
    if (inicio == nullptr) {
        inicio = new Nodo<T>(dato);
    } else {
        Nodo<T>* actual = inicio;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        actual->siguiente = new Nodo<T>(dato);
    }
}

template <typename T>
bool pilaSimple<T>::estaVacia() const {
    return inicio == nullptr;
}

template <typename T>
void pilaSimple<T>::imprimir() const {
    Nodo<T>* actual = inicio;
    while (actual != nullptr) {
        std::cout << actual->dato;  // Usa el operador <<
        actual = actual->siguiente;
    }
    std::cout << std::endl;
}
