#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H

#include <iostream>

template <typename T>
class Nodo {
public:
    T dato;
    Nodo* siguiente;

    Nodo(T _dato) : dato(_dato), siguiente(nullptr) {}
};

template <typename T>
class ListaSimple {
private:
    Nodo<T>* inicio;

public:
    ListaSimple() : inicio(nullptr) {}

    void insertarAlInicio(T _dato) {
        if (inicio == nullptr)
            inicio = new Nodo<T>(_dato);
        else {
            Nodo<T>* nuevo = new Nodo<T>(_dato);
            nuevo->siguiente = inicio;
            inicio = nuevo;
        }
    }

    void insertarAlFinal(T _dato) {
        if (inicio == nullptr)
            inicio = new Nodo<T>(_dato);
        else {
            Nodo<T>* tmp = inicio;
            while (tmp->siguiente != nullptr) {
                tmp = tmp->siguiente;
            }
            tmp->siguiente = new Nodo<T>(_dato);
        }
    }

    Nodo<T>* eliminar(T _dato) {
        if (_dato == inicio->dato) {  // Comparar directamente si es un tipo primitivo
            Nodo<T>* eliminado = inicio;
            inicio = inicio->siguiente;
            eliminado->siguiente = nullptr;
            return eliminado;
        } else {
            Nodo<T>* nodo_anterior = inicio;
            Nodo<T>* tmp = inicio;
            while (tmp != nullptr) {
                if (tmp->dato == _dato) {  // Comparar directamente si es un tipo primitivo
                    nodo_anterior->siguiente = tmp->siguiente;
                    tmp->siguiente = nullptr;
                    return tmp;
                }
                nodo_anterior = tmp;
                tmp = tmp->siguiente;
            }
            return nullptr;
        }
    }

    Nodo<T>* buscar(T _dato) {
        Nodo<T>* tmp = inicio;
        while (tmp != nullptr) {
            if (tmp->dato == _dato)  // Comparar directamente si es un tipo primitivo
                return tmp;
            tmp = tmp->siguiente;
        }
        return nullptr;
    }

    bool estaVacia() const {
        return inicio == nullptr;
    }

    void imprimir() const {
        if (!estaVacia()) {
            Nodo<T>* tmp = inicio;
            while (tmp != nullptr) {
                std::cout << tmp->dato << " ";  // Usar std::cout para tipos primitivos
                tmp = tmp->siguiente;
            }
            std::cout << std::endl;
        } else {
            std::cout << "No hay elementos" << std::endl;
        }
    }
};

#endif  // LISTASIMPLE_H
