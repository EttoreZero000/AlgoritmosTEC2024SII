#include "nodo.h"

template <typename T>
class listaSimple {
private:
	// Atributos
	Nodo * inicio;
public:
	// Constructores
	listaSimple(){
		inicio = NULL;
	}
	// Metodos
	void insertarInicio(T _dato);
	void insertarFinal(T _dato);
	Nodo * eliminar(T _dato);
};

