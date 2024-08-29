#include "nododoble.h"

class ListaDoble {
	
private:
	// Atributos
	NodoDoble * inicio;

public:
	// Constructores
	ListaDoble(){
		inicio = NULL;
	}

	// Metodos
	void insertarAlInicio(int _dato);
	void insertarAlFinal(int _dato);
	NodoDoble * buscar(int _dato);
	NodoDoble * eliminar(int _dato);
	bool estaVacia();
	void imprimir();
	void imprimirUnico(int a);
};

