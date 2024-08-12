
#include <iostream>
#include "listasimple.h"
#include "listadoble.h"
#include "listacircular.h"

int main(){

	// PRUEBAS
	
	ListaSimple * L1 = new ListaSimple();
	Estudiante E1("Juan", "Perez", "Ingeniería", "01/01/2000");
    Estudiante E2("Maria", "Gomez", "Medicina", "02/02/1999");
    Estudiante E3("Luis", "Ramirez", "Derecho", "03/03/1998");
    Estudiante E4("Ana", "Martinez", "Arquitectura", "04/04/1997");

	L1->insertarAlInicio(E1);
    L1->insertarAlInicio(E2);
    L1->insertarAlInicio(E3);

	// 4 3 2 1

	L1->imprimir();

	L1->insertarAlFinal(E4);

	// 4 3 2 1 5
	L1->imprimir();

	Nodo * e1 = L1->eliminar(E1);


	(e1 != NULL) ? std::cout << "Se elimino de la lista simple a " << e1->dato.nombre << std::endl : std::cout << "No lo encontro" << std::endl;

	delete e1;

	// 4 3 2 1
	L1->imprimir();

	Nodo * f1 = L1->eliminar(E3);

	(f1 != NULL) ? std::cout << "Se elimino de la lista simple a " << f1->dato.nombre << std::endl : std::cout << "No lo encontro" << std::endl;
	
	delete f1;
	
	// 3 2 1
	L1->imprimir();
	
	Nodo * g1 = L1->eliminar(E2);
	
	(g1 != NULL) ? std::cout << "Se elimino de la lista simple a " << g1->dato.nombre << std::endl : std::cout << "No lo encontro" << std::endl;
	
	delete g1;
	
	// 3 1
	L1->imprimir();
	
	Nodo * h1 = L1->eliminar(E4);
	
	(h1 != NULL) ? std::cout << "Se elimino de la lista simple a " << h1->dato.nombre << std::endl : std::cout << "No lo encontro" << std::endl;

	delete h1;

	// 3
	L1->imprimir();

	return 0;
}

