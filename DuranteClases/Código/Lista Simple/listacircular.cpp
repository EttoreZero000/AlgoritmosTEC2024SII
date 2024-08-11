#include <cstdlib>
#include <iostream>
#include "listacircular.h"


void ListaCircular::insertarAlInicio(int _dato){
	if (inicio == NULL){
		inicio = final = new NodoCircular(_dato);
		final->siguiente = inicio;
	}
	else {
		NodoCircular * nuevo = new NodoCircular(_dato);
		nuevo->siguiente = inicio;
		final->siguiente = nuevo;
		inicio = nuevo;
	}
}

void ListaCircular::insertarAlFinal(int _dato){
	if (inicio == NULL)
		inicio = final = new NodoCircular(_dato);
	else {
		NodoCircular * nuevo = new NodoCircular(_dato);
		final->siguiente = nuevo;
		final = nuevo;
		nuevo->siguiente = inicio;
	}
}

NodoCircular * ListaCircular::eliminar(int _dato){
	if (!estaVacia()){
		NodoCircular * tmp = inicio;
		if (inicio->dato == _dato){
			if (inicio == final)
				inicio = final = NULL;
			else {
				tmp = inicio;
				final->siguiente = inicio->siguiente;
				inicio = inicio->siguiente;
			}
			return tmp;
		}
		NodoCircular * anterior = NULL;
		while (tmp != final){
			if (tmp->dato == _dato){
				anterior->siguiente = tmp->siguiente;
				tmp->siguiente = NULL;
				return tmp;
			}
			anterior = tmp;
			tmp = tmp->siguiente;
		}

		if (final->dato == _dato){
			anterior->siguiente = final->siguiente;
			final = anterior;
			tmp->siguiente = NULL;
			return tmp;
		}

	}
	return NULL;
}

NodoCircular * ListaCircular::buscar(int _dato){
	if (!estaVacia()){
		NodoCircular * tmp = inicio;
		tmp = tmp->siguiente;
		while (tmp != inicio){
			if (tmp->dato == _dato)
				return tmp;
			tmp = tmp->siguiente;
		}
	}
	return NULL;
}

bool ListaCircular::estaVacia(){
	return inicio == NULL && final == NULL;
}

void ListaCircular::imprimir(){
	if (!estaVacia()){
		NodoCircular * tmp = inicio;
		std::cout << tmp->dato << " ";
		tmp = tmp->siguiente;
		while (tmp != inicio){
			std::cout << tmp->dato << " ";
			tmp = tmp->siguiente;
		}
		std::cout << std::endl;
	}
	else
		std::cout << "No hay elementos" << std::endl;
	
}