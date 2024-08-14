#include <iostream>
#include "listasimple.h"

void ListaSimple::insertarAlInicio(Estudiante _dato){
	if (inicio == NULL)
		inicio = new Nodo(_dato);
	else {
		Nodo * nuevo = new Nodo(_dato);
		nuevo->siguiente = inicio;
		inicio = nuevo;
	}
}

void ListaSimple::insertarAlFinal(Estudiante _dato){
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

Nodo * ListaSimple::eliminar(Estudiante _dato){
	if (_dato.nombre == inicio->dato.nombre) {
		Nodo * eliminado = inicio;
		inicio = inicio->siguiente;
		eliminado->siguiente = NULL;
		return eliminado;
	}
	else {
		Nodo * nodo_anterior = inicio;
		Nodo * tmp = inicio;
		while (tmp != NULL){
			if (tmp->dato.nombre == _dato.nombre){
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

Nodo * ListaSimple::buscar(Estudiante _dato){
	Nodo * tmp = inicio;
	while (tmp != NULL){
		if (tmp->dato.nombre == _dato.nombre)
			return tmp;
		tmp = tmp->siguiente;
	}
	return NULL;
}

bool ListaSimple::estaVacia(){
	return inicio == NULL;
}

void ListaSimple::imprimir(){
	if (!estaVacia()){
		Nodo * tmp = inicio;
		while (tmp != NULL){
			tmp->dato.imprimir();
			tmp = tmp->siguiente;
		}
		std::cout << std::endl;
	}
	else
		std::cout << "No hay elementos" << std::endl;
}