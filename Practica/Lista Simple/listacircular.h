#include "nodocircular.h"

class ListaCircular {
	
private:
	// Atributos
	NodoCircular * inicio, * final;

public:
	// Constructores
	ListaCircular(){
		inicio = final = NULL;
	}

	// Metodos
	void insertarAlInicio(int _dato);
	void insertarAlFinal(int _dato);
	NodoCircular * buscar(int _dato);
	NodoCircular * eliminar(int _dato);
	bool estaVacia();
	void imprimir();
};

