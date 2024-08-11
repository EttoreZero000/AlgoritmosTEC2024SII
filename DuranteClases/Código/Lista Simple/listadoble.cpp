#include <iostream>
#include "listadoble.h"

void ListaDoble::insertarAlInicio(int _dato){
	if (inicio == NULL)
		inicio = new NodoDoble(_dato);
	else {
		NodoDoble * nuevo = new NodoDoble(_dato);
		nuevo->siguiente = inicio;
		inicio->anterior = nuevo;
		inicio = nuevo;
	}
}

void ListaDoble::insertarAlFinal(int _dato){
	if (inicio == NULL)
		inicio = new NodoDoble(_dato);
	else {
		NodoDoble * tmp = inicio;
		NodoDoble * nuevo = new NodoDoble(_dato);
		while (tmp->siguiente != NULL){
			tmp = tmp->siguiente;
		}
		nuevo->anterior = tmp;
		tmp->siguiente = nuevo;
	}
}

void desligar(NodoDoble *  nodo){
	if (nodo->anterior != NULL)
		nodo->anterior->siguiente = nodo->siguiente;
	if (nodo->siguiente != NULL)
		nodo->siguiente->anterior = nodo->anterior;
}

NodoDoble * ListaDoble::eliminar(int _dato){
	if (!estaVacia()){
		NodoDoble * eliminado = buscar(_dato);
		if (eliminado != NULL){
			if (eliminado == inicio)
				inicio = inicio->siguiente;
			desligar(eliminado);
			return eliminado;
		}
	}
	return NULL;
}

NodoDoble * ListaDoble::buscar(int _dato){
	NodoDoble * tmp = inicio;
	while (tmp != NULL){
		if (tmp->dato == _dato)
			return tmp;
		tmp = tmp->siguiente;
	}
	return NULL;
}

bool ListaDoble::estaVacia(){
	return inicio == NULL;
}

void ListaDoble::imprimir(){
	if (!estaVacia()){
		NodoDoble * tmp = inicio;
		while (tmp != NULL){
			std::cout << tmp->dato << " ";
			tmp = tmp->siguiente;
		}
		std::cout << std::endl;
	}
	else
		std::cout << "No hay elementos" << std::endl;
}