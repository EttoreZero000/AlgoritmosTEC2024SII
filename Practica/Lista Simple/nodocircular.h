#include <cstdlib>

class NodoCircular {
public:
	// Atributos
	int dato;
	NodoCircular * siguiente;

	// Constructores
	NodoCircular(){
		dato = 0;
		siguiente = NULL;
	}

	NodoCircular(int _dato){
		dato = _dato;
		siguiente = NULL;
	}

	NodoCircular(int _dato, NodoCircular * _siguiente){
		dato = _dato;
		siguiente = _siguiente;
	}
};

