#include <cstdlib>
#include "clase.h"

class Nodo {
public:
	// Atributos
	Object dato;
	Nodo * siguiente;

	// Constructores
	Nodo(){
		dato = 0;
		siguiente = NULL;
	}

	Nodo(Object _dato){
		dato = _dato;
		siguiente = NULL;
	}

	Nodo(Object _dato, Nodo * _siguiente){
		dato = _dato;
		siguiente = _siguiente;
	}
};

