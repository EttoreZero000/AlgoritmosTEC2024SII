#ifndef LISTACIRCULARDOBLE_H
#define LISTACIRCULARDOBLE_H

#include <iostream>
#include "clase.h"

template <typename T>
class NodoCircularDoble {
public:
    T dato;
    NodoCircularDoble* siguiente;
    NodoCircularDoble* anterior;

    NodoCircularDoble(T _dato) : dato(_dato), siguiente(nullptr), anterior(nullptr) {}
};




template <typename T>
class ListaCircularDoble {
private:
    NodoCircularDoble<T>* inicio;

public:
    ListaCircularDoble();
    void insertarAlInicio(T _dato);
    void insertarMenorAMayor(T _dato);
    void insertarAlFinal(T dato);
    NodoCircularDoble<T>* buscar(std::string dato);
    NodoCircularDoble<T>* eliminar(T dato);
    bool estaVacia() const;
    void imprimir() const;
    int esPar();
    void insertarMedio(T _dato);
    NodoCircularDoble<T>* eliminarPosicion(int posicion);
    void imprimirTipo(int dato);
    void imprimirPrecio(float dato);
    void mostarJoyaAntesDespues(std::string dato);
};

// Implementaciones de ListaCircularDoble

template <typename T>
ListaCircularDoble<T>::ListaCircularDoble() : inicio(nullptr) {}

template <typename T>
void ListaCircularDoble<T>::insertarAlInicio(T _dato) {
    NodoCircularDoble<T>* nuevo = new NodoCircularDoble<T>(_dato);
    if (inicio == nullptr) {
        inicio = nuevo;
        nuevo->siguiente = nuevo;
        nuevo->anterior = nuevo;
    } else {
        nuevo->siguiente = inicio;
        nuevo->anterior = inicio->anterior;
        inicio->anterior->siguiente = nuevo;
        inicio->anterior = nuevo;
        inicio = nuevo;
    }
}

template <typename T>
void ListaCircularDoble<T>::insertarMenorAMayor(T _dato) {
    NodoCircularDoble<T>* nuevo = new NodoCircularDoble<T>(_dato);
    if (inicio == nullptr){
        inicio = nuevo;
        nuevo->siguiente = nuevo;
        nuevo->anterior = nuevo;
    } else {
        NodoCircularDoble<T>* tmp = inicio;
        if (_dato.precio < inicio->dato.precio) {
            NodoCircularDoble<T>* ultimo = inicio->anterior;

            nuevo->siguiente = inicio;
            nuevo->anterior = ultimo;

            ultimo->siguiente = nuevo;
            inicio->anterior = nuevo;

            inicio = nuevo;
        } else {
            while (tmp->siguiente != inicio && tmp->siguiente->dato.precio < _dato.precio) {
                tmp = tmp->siguiente;
            }
            nuevo->siguiente = tmp->siguiente;
            nuevo->anterior = tmp;

            tmp->siguiente->anterior = nuevo;
            tmp->siguiente = nuevo;
        }
    }
}


template <typename T>
void ListaCircularDoble<T>::insertarAlFinal(T dato) {
    NodoCircularDoble<T>* nuevo = new NodoCircularDoble<T>(dato);
    if (inicio == nullptr) {
        inicio = nuevo;
        nuevo->siguiente = nuevo;
        nuevo->anterior = nuevo;
    } else {
        NodoCircularDoble<T>* ultimo = inicio->anterior;
        nuevo->siguiente = inicio;
        nuevo->anterior = ultimo;
        ultimo->siguiente = nuevo;
        inicio->anterior = nuevo;
    }
}

template <typename T>
NodoCircularDoble<T>* ListaCircularDoble<T>::buscar(std::string dato) {
    NodoCircularDoble<T>* actual = inicio;
    if (actual != nullptr) {
        do {
            if (actual->dato.nombre == dato) {
                return actual;
            }
            actual = actual->siguiente;
        } while (actual != inicio);
    }
    return nullptr;
}

template <typename T>
NodoCircularDoble<T>* ListaCircularDoble<T>::eliminar(T dato) {
    NodoCircularDoble<T>* actual = inicio;
    if (actual != nullptr) {
        do {
            if (actual->dato == dato) {
                if (actual->siguiente == actual) { // Solo nodo en la lista
                    delete actual;
                    inicio = nullptr;
                } else {
                    actual->anterior->siguiente = actual->siguiente;
                    actual->siguiente->anterior = actual->anterior;
                    if (actual == inicio) {
                        inicio = actual->siguiente;
                    }
                    delete actual;
                }
                return inicio;
            }
            actual = actual->siguiente;
        } while (actual != inicio);
    }
    return nullptr;
}

template <typename T>
bool ListaCircularDoble<T>::estaVacia() const {
    return inicio == nullptr;
}

template <typename T>
void ListaCircularDoble<T>::imprimir() const {
    NodoCircularDoble<T>* actual = inicio;
    if (actual != nullptr) {
        do {
            std::cout << actual->dato << " ";
            actual = actual->siguiente;
        } while (actual != inicio);
    }
}

template <typename T>
int ListaCircularDoble<T>::esPar() {
    NodoCircularDoble<T>* tmp = inicio;
    int i = 0;
    if (tmp != nullptr) {
        do {
            i++;
            tmp = tmp->siguiente;
        } while (tmp != inicio);
    }
    return (i % 2 == 0) ? i : 0;
}

template <typename T>
void ListaCircularDoble<T>::insertarMedio(T _dato) {
    int a = esPar();
    NodoCircularDoble<T>* nuevo = new NodoCircularDoble<T>(_dato);
    if (a > 0) {
        a = a / 2;
        NodoCircularDoble<T>* tmp = inicio;
        for (int i = 0; i < a - 1; i++) {
            tmp = tmp->siguiente;
        }
        nuevo->siguiente = tmp->siguiente;
        nuevo->anterior = tmp;
        tmp->siguiente->anterior = nuevo;
        tmp->siguiente = nuevo;
    } else {
        insertarAlFinal(_dato);
    }
}

template <typename T>
NodoCircularDoble<T>* ListaCircularDoble<T>::eliminarPosicion(int posicion) {
    if (inicio == nullptr || posicion < 0) {
        return nullptr;
    }
    NodoCircularDoble<T>* eliminado = nullptr;
    NodoCircularDoble<T>* actual = inicio;
    int i = 0;
    if (posicion == 0) {
        if (inicio->siguiente == inicio) { // Solo nodo en la lista
            eliminado = inicio;
            inicio = nullptr;
        } else {
            eliminado = inicio;
            inicio = inicio->siguiente;
            inicio->anterior = eliminado->anterior;
            eliminado->anterior->siguiente = inicio;
        }
        delete eliminado;
        return inicio;
    } else {
        do {
            if (i == posicion) {
                eliminado = actual;
                actual->anterior->siguiente = actual->siguiente;
                actual->siguiente->anterior = actual->anterior;
                if (eliminado == inicio) {
                    inicio = actual->siguiente;
                }
                delete eliminado;
                return inicio;
            }
            actual = actual->siguiente;
            i++;
        } while (actual != inicio);
    }
    return nullptr;
}
template <typename T>
void ListaCircularDoble<T>::imprimirTipo(int dato){
    NodoCircularDoble<T>* tmp = inicio;
    while(tmp!=nullptr){
        if(tmp->dato.tipo==dato){
            tmp->dato.imprimir();
        }
        tmp=tmp->siguiente;
        if(tmp==inicio){
            return ;
        }
    }
    std::cout << "Final de la lista";
}
template <typename T>
void ListaCircularDoble<T>::imprimirPrecio(float dato){
    NodoCircularDoble<T>* tmp = inicio;
    while(tmp!=nullptr){
        if(tmp->dato.precio<=dato){
            tmp->dato.imprimir();
        }
        tmp=tmp->siguiente;
        if(tmp==inicio){
            return;
        }
    }
    std::cout << "Final de la lista";
}
template <typename T>
void ListaCircularDoble<T>::mostarJoyaAntesDespues(std::string dato){
    NodoCircularDoble<T>* tmp=inicio;
    while(tmp!=nullptr){
        if(tmp->dato.nombre==dato){
            std::cout << tmp->dato;
            std::cout << "Posterior";
            std::cout << tmp->siguiente->dato;
            std::cout << "Anterior";
            std::cout << tmp->anterior->dato;
            return;
        }
        tmp=tmp->siguiente;
    }
}
#endif // LISTACIRCULARDOBLE_H
