#include "listasimple.h"

template <typename T>
ListaSimple<T>::ListaSimple() : cabeza(nullptr) {}

//template <typename T>
//ListaSimple<T>::~ListaSimple() {
//    Nodo<T>* actual = cabeza;
//    while (actual != nullptr) {
//        Nodo<T>* siguiente = actual->siguiente;
//        delete actual;
//        actual = siguiente;
//    }
//}

template <typename T>
void ListaSimple<T>::insertarAlInicio(T dato) {
    cabeza = new Nodo<T>(dato, cabeza);
}

template <typename T>
void ListaSimple<T>::insertarAlFinal(T dato) {
    if (cabeza == nullptr) {
        cabeza = new Nodo<T>(dato);
    } else {
        Nodo<T>* actual = cabeza;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        actual->siguiente = new Nodo<T>(dato);
    }
}

template <typename T>
Nodo<T>* ListaSimple<T>::buscar(T dato) {
    Nodo<T>* actual = cabeza;
    while (actual != nullptr) {
        if (actual->dato == dato) {
            return actual;
        }
        actual = actual->siguiente;
    }
    return nullptr;
}

template <typename T>
Nodo<T>* ListaSimple<T>::eliminar(T dato) {
    Nodo<T>* actual = cabeza;
    Nodo<T>* anterior = nullptr;
    while (actual != nullptr && actual->dato != dato) {
        anterior = actual;
        actual = actual->siguiente;
    }
    if (actual == nullptr) {
        return nullptr; // No se encontró el dato
    }
    if (anterior == nullptr) {
        cabeza = actual->siguiente;
    } else {
        anterior->siguiente = actual->siguiente;
    }
    delete actual;
    return cabeza;
}

template <typename T>
bool ListaSimple<T>::estaVacia() const {
    return cabeza == nullptr;
}

template <typename T>
void ListaSimple<T>::imprimir() const {
    Nodo<T>* actual = cabeza;
    while (actual != nullptr) {
        std::cout << actual->dato << " ";  // Usa el operador <<
        actual = actual->siguiente;
    }
    std::cout << std::endl;
}