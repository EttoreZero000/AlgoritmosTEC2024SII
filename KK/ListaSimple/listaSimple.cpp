#include "listaSimple.h"

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
template <typename T>
int ListaSimple<T>::esPar(){
    Nodo<T>* tmp = inicio;
    int i=0;
    while(tmp!=nullptr){
        i++;
        tmp=tmp->siguiente;
    }
    if (i%2==0){
        return i;
    }
    else{
        return 0;
    }
}
template <typename T>
void ListaSimple<T>::insertarMedio(T _dato){
    int a = esPar();
    Nodo<T>* nuevo = new Nodo<T>(_dato);
    if (a>0){
        a=a/2;
        Nodo<T>* tmp = inicio;
        for(int i=0; i<a-1; i++){
            tmp=tmp->siguiente;
        }
        nuevo->siguiente = tmp->siguiente;
        tmp->siguiente = nuevo;
    }else{
        insertarAlFinal(_dato);
    }
}
template <typename T>
Nodo<T>* ListaSimple<T>::eliminarPosicion(int posicion) {
    if (inicio == nullptr || posicion < 0) {
        return nullptr;
    }
    Nodo<T>* eliminado = nullptr;
    if (posicion == 0) {
        eliminado = inicio;
        inicio = inicio->siguiente;
    } else {
        Nodo<T>* tmp = inicio;
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
    }
    return eliminado;
}
