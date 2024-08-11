#include "nodo.h"

class ListaSimple {
	
private:
	// Atributos
	Nodo * inicio;

public:
	// Constructores
	ListaSimple(){
		inicio = NULL;
	}

	// Metodos
	void insertarAlInicio(int _dato);
	void insertarAlFinal(int _dato);
	Nodo * buscar(int _dato);
	Nodo * eliminar(int _dato);
	bool estaVacia();
	void imprimir();
};

