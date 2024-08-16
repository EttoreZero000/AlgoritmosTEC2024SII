
#include <iostream>
#include "classArmamento.h"
#include "listasimple.h"
int main(){
	
	ListaSimple<Armamento> * L1 = new ListaSimple<Armamento>();
	Armamento E1;

	L1->insertarAlInicio(E1);

	// 4 3 2 1
	L1->imprimir();

	Nodo<Armamento> * e1 = L1->eliminar(E1);


	(e1 != NULL) ? std::cout << "Se elimino de la lista simple a " << e1->dato << std::endl : std::cout << "No lo encontro" << std::endl;

	delete e1;

	std::cin.get();
	return 0;
}

