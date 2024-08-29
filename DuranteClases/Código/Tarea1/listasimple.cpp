#include "listasimple.h"

template <typename T>
ListaSimple<T>::ListaSimple() : inicio(nullptr) {}

template <typename T>
void ListaSimple<T>::insertarAlInicio(T _dato) {
    if (inicio == nullptr)
        inicio = new Nodo<T>(_dato);
    else {
        Nodo<T>* nuevo = new Nodo<T>(_dato);
        nuevo->siguiente = inicio;
        inicio = nuevo;
    }
}

template <typename T>
void ListaSimple<T>::insertarAlFinal(T dato) {
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
Nodo<T>* ListaSimple<T>::buscar(int id) {
    Nodo<T>* actual = inicio;
    while (actual != nullptr) {
        if (actual->dato.getId() == id) {
            return actual;
        }
        actual = actual->siguiente;
    }
    return nullptr;
}

template <typename T>
Nodo<T>* ListaSimple<T>::eliminar(T dato) {
    Nodo<T>* actual = inicio;
    Nodo<T>* anterior = nullptr;
    while (actual != nullptr && actual->dato != dato) {
        anterior = actual;
        actual = actual->siguiente;
    }
    if (actual == nullptr) {
        return nullptr; // No se encontró el dato
    }
    if (anterior == nullptr) {
        inicio = actual->siguiente;
    } else {
        anterior->siguiente = actual->siguiente;
    }
    delete actual;
    return inicio;
}

template <typename T>
bool ListaSimple<T>::estaVacia() const {
    return inicio == nullptr;
}

template <typename T>
void ListaSimple<T>::imprimir() const {
    Nodo<T>* actual = inicio;
    while (actual != nullptr) {
        std::cout << actual->dato << " ";  // Usa el operador <<
        actual = actual->siguiente;
    }
    std::cout << std::endl;
}
