#include <iostream>
#include "listasimple.h"

template <typename T>
ListaSimple<T>::ListaSimple() : inicio(nullptr) {}

template <typename T>
void ListaSimple<T>::insertarAlInicio(const T& _dato) {
    if (inicio == nullptr) {
        inicio = new Nodo<T>(_dato);
    } else {
        Nodo<T>* nuevo = new Nodo<T>(_dato);
        nuevo->siguiente = inicio;
        inicio = nuevo;
    }
}

template <typename T>
void ListaSimple<T>::insertarAlFinal(const T& _dato) {
    if (inicio == nullptr) {
        inicio = new Nodo<T>(_dato);
    } else {
        Nodo<T>* tmp = inicio;
        while (tmp->siguiente != nullptr) {
            tmp = tmp->siguiente;
        }
        tmp->siguiente = new Nodo<T>(_dato);
    }
}

template <typename T>
Nodo<T>* ListaSimple<T>::eliminar(const T& _dato) {
    if (inicio == nullptr) return nullptr; // Lista vacía

    if (_dato == inicio->dato) { // Comparar con el primer nodo
        Nodo<T>* eliminado = inicio;
        inicio = inicio->siguiente;
        eliminado->siguiente = nullptr;
        return eliminado;
    } else {
        Nodo<T>* nodo_anterior = inicio;
        Nodo<T>* tmp = inicio->siguiente;
        while (tmp != nullptr) {
            if (_dato == tmp->dato) { // Comparar con nodos siguientes
                nodo_anterior->siguiente = tmp->siguiente;
                tmp->siguiente = nullptr;
                return tmp;
            }
            nodo_anterior = tmp;
            tmp = tmp->siguiente;
        }
        return nullptr; // No se encontró el elemento
    }
}

template <typename T>
Nodo<T>* ListaSimple<T>::buscar(const T& _dato) {
    Nodo<T>* tmp = inicio;
    while (tmp != nullptr) {
        if (tmp->dato == _dato) {
            return tmp;
        }
        tmp = tmp->siguiente;
    }
    return nullptr; // No encontrado
}

template <typename T>
bool ListaSimple<T>::estaVacia() const {
    return inicio == nullptr;
}

template <typename T>
void ListaSimple<T>::imprimir() const {
    if (!estaVacia()) {
        Nodo<T>* tmp = inicio;
        while (tmp != nullptr) {
            tmp->dato.imprimir(); // Asegúrate de que `imprimir()` esté definido en `T`
            tmp = tmp->siguiente;
        }
        std::cout << std::endl;
    } else {
        std::cout << "No hay elementos" << std::endl;
    }
}
