#include <cstdlib>
#include "estudiante.h"
class Nodo {
public:
	// Atributos
	Estudiante dato;
	Nodo * siguiente;


	Nodo() : dato(Estudiante()), siguiente(NULL) {}

	Nodo(Estudiante _dato) : dato(_dato), siguiente(NULL) {}

	Nodo(Estudiante  _dato, Nodo * _siguiente) : dato(_dato), siguiente(_siguiente){};
};