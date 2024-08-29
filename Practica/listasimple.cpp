#include <iostream>
#include "listasimple.h"

template <typename T>
void listaSimple<T>::insertarInicio(T _dato) {
	if (inicio = NULL)
        inicio = new Nodo(_dato);
    else{
        Nodo * nuevo = new Nodo(_dato);
        nuevo->siguiente = inicio;
        inicio = nuevo;
    }
}

template <typename T>
void listaSimple<T>::insertarFinal(T _dato) {
	if (inicio=NULL)
        inicio=new Nodo(_dato)
    else{
        Nodo * tmp = inicio;
        while (tmp->siguiente !=NULL)
        {
            tmp=tmp->siguiente;
        }
        tmp->siguiente = new Nodo(_dato)
    }
}

template <typename T>
Nodo * listaSimple<T>::eliminar(T _dato){
    if(_dato == inicio->dato){
        Nodo * eliminado = inicio;
        inicio = inicio->siguiente;
        eliminado->siguiente = NULL;
        return eliminado;
    }
    else{
        Nodo * nodo_anterior = inicio;
        Nodo * tmp = inicio;
        while (tpm != NULL){
            if (tmp->dato == _dato){
                nodo_anterior->siguiente=tmp->siguiente;
                tmp->siguiente=NULL;
                return tmp;
            }
            nodo_anterior=tmp;
            tmp=tmp->siguiente;
        }
        return NULL;
    }
}