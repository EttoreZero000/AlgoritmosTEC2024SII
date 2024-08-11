#include <iostream>
#include "clase.h"

void Estudiante::insertarAlInicio(int _dato){
	if (inicio == NULL)
		inicio = new Nodo(_dato);
	else {
		Nodo * nuevo = new Nodo(_dato);
		nuevo->siguiente = inicio;
		inicio = nuevo;
	}
}

void Estudiante::insertarAlFinal(int _dato){
	if (inicio == NULL)
		inicio = new Nodo(_dato);
	else {
		Nodo * tmp = inicio;
		while (tmp->siguiente != NULL){
			tmp = tmp->siguiente;
		}
		tmp->siguiente = new Nodo(_dato);
	}
}

Nodo * Estudiante::eliminar(int _dato){
	if (_dato == inicio->dato) {
		Nodo * eliminado = inicio;
		inicio = inicio->siguiente;
		eliminado->siguiente = NULL;
		return eliminado;
	}
	else {
		Nodo * nodo_anterior = inicio;
		Nodo * tmp = inicio;
		while (tmp != NULL){
			if (tmp->dato == _dato){
				nodo_anterior->siguiente = tmp->siguiente;
				tmp->siguiente = NULL;
				return tmp;
			}
			nodo_anterior = tmp;
			tmp = tmp->siguiente;
		}
		return NULL;
	}
}

Nodo * Estudiante::buscar(int _dato){
	Nodo * tmp = inicio;
	while (tmp != NULL){
		if (tmp->dato == _dato)
			return tmp;
		tmp = tmp->siguiente;
	}
	return NULL;
}

bool Estudiante::estaVacia(){
	return inicio == NULL;
}

void Estudiante::imprimir(){
	if(!estaVacia()){
	Nodo * tmp = inicio;
	while (tmp != NULL){
		std::cout << tmp->dato << " ";
		tmp = tmp->siguiente;
	}
	std::cout << std::endl;
	}
	else
		std::cout << "No hay elementos" << std::endl;
}