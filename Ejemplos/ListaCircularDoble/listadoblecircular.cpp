#include "listadoblecircular.h"

// Método para insertar al inicio
template<typename T>
void ListaDobleCircular<T>::insertarAlInicio(T _dato) {
    NodoDoble<T>* nuevo = new NodoDoble<T>(_dato);
    if (estaVacia()) {
        inicio = final = nuevo;
        nuevo->siguiente = nuevo;
        nuevo->anterior = nuevo;
    } else {
        nuevo->siguiente = inicio;
        nuevo->anterior = final;
        inicio->anterior = nuevo;
        final->siguiente = nuevo;
        inicio = nuevo;
    }
}

// Método para insertar al final
template<typename T>
void ListaDobleCircular<T>::insertarAlFinal(T _dato) {
    NodoDoble<T>* nuevo = new NodoDoble<T>(_dato);
    if (estaVacia()) {
        insertarAlInicio(_dato);
    } else {
        nuevo->siguiente = inicio;
        nuevo->anterior = final;
        final->siguiente = nuevo;
        inicio->anterior = nuevo;
        final = nuevo;
    }
}

// Método para insertar en la posición media
template<typename T>
void ListaDobleCircular<T>::insertarEnMedio(T _dato) {
    if (estaVacia()) {
        insertarAlInicio(_dato);
        return;
    }

    int longitud = 0;
    NodoDoble<T>* tmp = inicio;

    // Contar el número de nodos en la lista
    do {
        longitud++;
        tmp = tmp->siguiente;
    } while (tmp != inicio);

    // Calcular la posición media
    int posicionMedia = longitud / 2;

    // Insertar en la posición media
    tmp = inicio;
    int i = 0;

    // Recorrer la lista hasta la posición media
    while (i < posicionMedia - 1) {
        tmp = tmp->siguiente;
        i++;
    }

    NodoDoble<T>* nuevo = new NodoDoble<T>(_dato);

    // Insertar el nuevo nodo en la posición media
    nuevo->siguiente = tmp->siguiente;
    nuevo->anterior = tmp;
    tmp->siguiente->anterior = nuevo;
    tmp->siguiente = nuevo;
}

// Método para verificar si la lista está vacía
template<typename T>
bool ListaDobleCircular<T>::estaVacia() {
    return inicio == nullptr;
}

// Método para buscar un dato en la lista
template<typename T>
NodoDoble<T>* ListaDobleCircular<T>::buscar(T _dato) {
    NodoDoble<T>* tmp = inicio;
    if (!estaVacia()) {
        do {
            if (tmp->dato == _dato) {
                return tmp;
            }
            tmp = tmp->siguiente;
        } while (tmp != inicio);
    }
    return nullptr;
}

// Método para eliminar un nodo de la lista
template<typename T>
NodoDoble<T>* ListaDobleCircular<T>::eliminar(T _dato) {
    NodoDoble<T>* nodoEliminar = buscar(_dato);
    if (nodoEliminar != nullptr) {
        if (nodoEliminar->anterior != nullptr) {
            nodoEliminar->anterior->siguiente = nodoEliminar->siguiente;
        } else {
            inicio = nodoEliminar->siguiente;
        }
        if (nodoEliminar->siguiente != nullptr) {
            nodoEliminar->siguiente->anterior = nodoEliminar->anterior;
        } else {
            final = nodoEliminar->anterior;
        }
        if (inicio == nodoEliminar) {
            inicio = nodoEliminar->siguiente;
        }
        if (final == nodoEliminar) {
            final = nodoEliminar->anterior;
        }
        delete nodoEliminar;
    }
    return inicio;
}

// Método para imprimir los elementos de la lista
template<typename T>
void ListaDobleCircular<T>::imprimir() {
    if (!estaVacia()) {
        NodoDoble<T>* tmp = inicio;
        do {
            std::cout << tmp->dato << " ";
            tmp = tmp->siguiente;
        } while (tmp != inicio);
        std::cout << std::endl;
    } else {
        std::cout << "No hay elementos" << std::endl;
    }
}
