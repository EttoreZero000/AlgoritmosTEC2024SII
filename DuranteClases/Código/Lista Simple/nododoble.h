#include <cstdlib>

class NodoDoble {
public:
	// Atributos
	int dato;
	NodoDoble * siguiente, * anterior;

	// Constructores
	NodoDoble(){
		dato = 0;
		siguiente = anterior = NULL;
	}

	NodoDoble(int _dato){
		dato = _dato;
		siguiente = anterior = NULL;
	}

	NodoDoble(int _dato, NodoDoble * _siguiente, NodoDoble * _anterior){
		dato = _dato;
		siguiente = _siguiente;
		anterior = _anterior;
	}
};


