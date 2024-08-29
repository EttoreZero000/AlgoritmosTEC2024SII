// listaDoble.cpp
#include <iostream>
#include "listaDoble.h"

// Método para insertar al inicio
void ListaDoble::insertarAlInicio(int _dato) {
    NodoDoble* nuevo = new NodoDoble(_dato);
    if (inicio != nullptr) {
        nuevo->siguiente = inicio;
        inicio->anterior = nuevo;
    }
    inicio = nuevo;
}

// Método para insertar al final
void ListaDoble::insertarAlFinal(int _dato) {
    NodoDoble* nuevo = new NodoDoble(_dato);
    if (estaVacia()) {
        inicio = nuevo;
    } else {
        NodoDoble* tmp = inicio;
        while (tmp->siguiente != nullptr) {
            tmp = tmp->siguiente;
        }
        tmp->siguiente = nuevo;
        nuevo->anterior = tmp;
    }
}

// Método para verificar si la lista está vacía
bool ListaDoble::estaVacia() {
    return inicio == nullptr;
}

// Método para imprimir los elementos de la lista
void ListaDoble::imprimir() {
    if (!estaVacia()) {
        NodoDoble* tmp = inicio;
        while (tmp != nullptr) {
            std::cout << tmp->dato << " ";
            tmp = tmp->siguiente;
        }
        std::cout << std::endl;
    } else {
        std::cout << "No hay elementos" << std::endl;
    }
}
void ListaDoble::imprimirUnico(int a) {
    if (!estaVacia()) {
        NodoDoble* tmp = inicio;
        int i = 1;
        
        while (i != a) {
            if (tmp == nullptr) {  // Verificación para evitar acceder a un puntero nulo
                std::cout << "No hay elemento" << std::endl;
                return;
            }
            tmp = tmp->siguiente;
            i++;
        }
        
        if (tmp != nullptr) {
            std::cout << tmp->dato << std::endl;
        } else {
            std::cout << "No hay elemento" << std::endl;
        }
    } else {
        std::cout << "No hay elementos" << std::endl;
    }
}


// Método para buscar un dato en la lista
NodoDoble* ListaDoble::buscar(int _dato) {
    NodoDoble* tmp = inicio;
    while (tmp != nullptr && tmp->dato != _dato) {
        tmp = tmp->siguiente;
    }
    return tmp;
}

// Método para eliminar un nodo de la lista
NodoDoble* ListaDoble::eliminar(int _dato) {
    NodoDoble* nodoEliminar = buscar(_dato);
    if (nodoEliminar != nullptr) {
        if (nodoEliminar->anterior != nullptr) {
            nodoEliminar->anterior->siguiente = nodoEliminar->siguiente;
        } else {
            inicio = nodoEliminar->siguiente;  // Si es el primer nodo
        }
        if (nodoEliminar->siguiente != nullptr) {
            nodoEliminar->siguiente->anterior = nodoEliminar->anterior;
        }
        delete nodoEliminar;
    }
    return inicio;
}
