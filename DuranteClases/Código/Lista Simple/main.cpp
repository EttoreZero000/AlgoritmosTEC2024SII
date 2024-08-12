
#include <iostream>
#include "listasimple.h"
#include "listadoble.h"
#include "listacircular.h"

int main(){

	// PRUEBAS
	
	ListaSimple * L1 = new ListaSimple();
	L1->insertarAlInicio(1);
	L1->insertarAlInicio(2);
	L1->insertarAlInicio(3);
	L1->insertarAlInicio(4);

	// 4 3 2 1

	L1->imprimir();

	L1->insertarAlFinal(5);

	// 4 3 2 1 5
	L1->imprimir();

	Nodo * e1 = L1->eliminar(5);


	(e1 != NULL) ? std::cout << "Se elimino de la lista simple el " << e1->dato << std::endl : std::cout << "No lo encontro" << std::endl;

	delete e1;

	// 4 3 2 1
	L1->imprimir();

	Nodo * f1 = L1->eliminar(4);

	(f1 != NULL) ? std::cout << "Se elimino de la lista simple el " << f1->dato << std::endl : std::cout << "No lo encontro" << std::endl;
	
	delete f1;
	
	// 3 2 1
	L1->imprimir();
	
	Nodo * g1 = L1->eliminar(2);
	
	(g1 != NULL) ? std::cout << "Se elimino de la lista simple el " << g1->dato << std::endl : std::cout << "No lo encontro" << std::endl;
	
	delete g1;
	
	// 3 1
	L1->imprimir();
	
	Nodo * h1 = L1->eliminar(1);
	
	(h1 != NULL) ? std::cout << "Se elimino de la lista simple el " << h1->dato << std::endl : std::cout << "No lo encontro" << std::endl;

	delete h1;

	// 3
	L1->imprimir();

	Nodo * i1 = L1->eliminar(3);

	(i1 != NULL) ? std::cout << "Se elimino de la lista simple el " << i1->dato << std::endl : std::cout << "No lo encontro" << std::endl;

	delete i1;

	// 
	L1->imprimir();
	
	return 0;
}

