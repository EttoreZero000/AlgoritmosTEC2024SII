#include "nodo.h"
#include "clase.h"

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
	void insertarAlInicio(Estudiante _dato);
	void insertarAlFinal(Estudiante _dato);
	Nodo * buscar(Estudiante _dato);
	Nodo * eliminar(Estudiante _dato);
	bool estaVacia();
	void imprimir();
};

