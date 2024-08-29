#ifndef LISTADOBLE_H
#define LISTADOBLE_H

#include <iostream>

template <typename T>
class NodoDoble {
public:
    T dato;
    NodoDoble* siguiente;
    NodoDoble* anterior;

    NodoDoble(T _dato) : dato(_dato), siguiente(nullptr), anterior(nullptr) {}
};

template <typename T>
class ListaDoble {
private:
    NodoDoble<T>* inicio;

public:
    ListaDoble();
    void insertarAlInicio(T _dato);
    void insertarAlFinal(T dato);
    NodoDoble<T>* buscar(int id);
    NodoDoble<T>* eliminar(T dato);
    bool estaVacia() const;
    void imprimir() const;
    int esPar();
    void insertarMedio(T _dato);
    NodoDoble<T>* eliminarPosicion(int posicion);
};

// Implementaciones de ListaDoble

template <typename T>
ListaDoble<T>::ListaDoble() : inicio(nullptr) {}

template <typename T>
void ListaDoble<T>::insertarAlInicio(T _dato) {
    NodoDoble<T>* nuevo = new NodoDoble<T>(_dato);
    if (inicio == nullptr) {
        inicio = nuevo;
    } else {
        nuevo->siguiente = inicio;
        inicio->anterior = nuevo;
        inicio = nuevo;
    }
}

template <typename T>
void ListaDoble<T>::insertarAlFinal(T dato) {
    NodoDoble<T>* nuevo = new NodoDoble<T>(dato);
    if (inicio == nullptr) {
        inicio = nuevo;
    } else {
        NodoDoble<T>* actual = inicio;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo;
        nuevo->anterior = actual;
    }
}

template <typename T>
NodoDoble<T>* ListaDoble<T>::buscar(int id) {
    NodoDoble<T>* actual = inicio;
    while (actual != nullptr) {
        if (actual->dato.getId() == id) {
            return actual;
        }
        actual = actual->siguiente;
    }
    return nullptr;
}

template <typename T>
NodoDoble<T>* ListaDoble<T>::eliminar(T dato) {
    NodoDoble<T>* actual = inicio;
    while (actual != nullptr && actual->dato != dato) {
        actual = actual->siguiente;
    }
    if (actual == nullptr) {
        return nullptr; // No se encontró el dato
    }
    if (actual->anterior != nullptr) {
        actual->anterior->siguiente = actual->siguiente;
    } else {
        inicio = actual->siguiente; // Actual era el primer nodo
    }
    if (actual->siguiente != nullptr) {
        actual->siguiente->anterior = actual->anterior;
    }
    delete actual;
    return inicio;
}

template <typename T>
bool ListaDoble<T>::estaVacia() const {
    return inicio == nullptr;
}

template <typename T>
void ListaDoble<T>::imprimir() const {
    NodoDoble<T>* actual = inicio;
    while (actual != nullptr) {
        std::cout << actual->dato << " ";  // Usa el operador <<
        actual = actual->siguiente;
    }
    std::cout << std::endl;
}

template <typename T>
int ListaDoble<T>::esPar() {
    NodoDoble<T>* tmp = inicio;
    int i = 0;
    while (tmp != nullptr) {
        i++;
        tmp = tmp->siguiente;
    }
    return (i % 2 == 0) ? i : 0;
}

template <typename T>
void ListaDoble<T>::insertarMedio(T _dato) {
    int a = esPar();
    NodoDoble<T>* nuevo = new NodoDoble<T>(_dato);
    if (a > 0) {
        a = a / 2;
        NodoDoble<T>* tmp = inicio;
        for (int i = 0; i < a - 1; i++) {
            tmp = tmp->siguiente;
        }
        nuevo->siguiente = tmp->siguiente;
        if (tmp->siguiente != nullptr) {
            tmp->siguiente->anterior = nuevo;
        }
        tmp->siguiente = nuevo;
        nuevo->anterior = tmp;
    } else {
        insertarAlFinal(_dato);
    }
}

template <typename T>
NodoDoble<T>* ListaDoble<T>::eliminarPosicion(int posicion) {
    if (inicio == nullptr || posicion < 0) {
        return nullptr;
    }
    NodoDoble<T>* eliminado = nullptr;
    if (posicion == 0) {
        eliminado = inicio;
        inicio = inicio->siguiente;
        if (inicio != nullptr) {
            inicio->anterior = nullptr;
        }
    } else {
        NodoDoble<T>* tmp = inicio;
        for (int j = 0; j < posicion - 1; j++) {
            if (tmp->siguiente == nullptr) {
                return nullptr;
            }
            tmp = tmp->siguiente;
        }
        if (tmp->siguiente == nullptr) {
            return nullptr;
        }
        eliminado = tmp->siguiente;
        tmp->siguiente = eliminado->siguiente;
        if (eliminado->siguiente != nullptr) {
            eliminado->siguiente->anterior = tmp;
        }
    }
    return eliminado;
}

#endif // LISTADOBLE_H
