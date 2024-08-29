#include <cstdlib>

class Nodo {
public:
	// Atributos
	int dato;
	Nodo * siguiente;

	// Constructores
	Nodo(){
		dato = 0;
		siguiente = NULL;
	}

	Nodo(int _dato){
		dato = _dato;
		siguiente = NULL;
	}

	Nodo(int _dato, Nodo * _siguiente){
		dato = _dato;
		siguiente = _siguiente;
	}
};

