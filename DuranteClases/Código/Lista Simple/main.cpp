
#include <iostream>
#include "listasimple.h"
#include "listadoble.h"
#include "listacircular.h"
#include "clase.h"

int main(){

	// PRUEBAS
	
	ListaSimple * L1 = new ListaSimple();
	ListaDoble * L2 = new ListaDoble();
	ListaCircular * L3 = new ListaCircular();
	Estudiante estudent1("Hector1","Leiva Gamboa","Mecatronica","12/03/2024");
	Estudiante estudent2("Hector2","Leiva Gamboa","Mecatronica","12/03/2024");
	Estudiante estudent3("Hector3","Leiva Gamboa","Mecatronica","12/03/2024");
	Estudiante estudent4("Hector4","Leiva Gamboa","Mecatronica","12/03/2024");
	Estudiante estudent5("Hector5","Leiva Gamboa","Mecatronica","12/03/2024");

	L1->insertarAlInicio(estudent1);
	L1->insertarAlInicio(estudent2);
	L1->insertarAlInicio(estudent3);
	L1->insertarAlInicio(estudent4);

	L1->imprimir();

	L1->insertarAlFinal(estudent5);

	L1->imprimir();

	Nodo * e1 = L1->eliminar(estudent5);


	(e1 != NULL) ? std::cout << "Se elimino de la lista simple el " << e1->dato << std::endl : std::cout << "No lo encontro" << std::endl;

	delete e1;

	L1->imprimir();

	Nodo * f1 = L1->eliminar(estudent4);

	(f1 != NULL) ? std::cout << "Se elimino de la lista simple el " << f1->dato << std::endl : std::cout << "No lo encontro" << std::endl;

	delete f1;

	L1->imprimir();

	Nodo * g1 = L1->eliminar(estudent2);

	(g1 != NULL) ? std::cout << "Se elimino de la lista simple el " << g1->dato << std::endl : std::cout << "No lo encontro" << std::endl;
	
	delete g1;

	Nodo * h1 = L1->eliminar(estudent1);

	(h1 != NULL) ? std::cout << "Se elimino de la lista simple el " << h1->dato << std::endl : std::cout << "No lo encontro" << std::endl;

	delete h1;

	L1->imprimir();

	Nodo * i1 = L1->eliminar(estudent3);

	(i1 != NULL) ? std::cout << "Se elimino de la lista simple el " << i1->dato << std::endl : std::cout << "No lo encontro" << std::endl;

	delete i1;

	L1->imprimir();

	std::cin.get();
	return 0;
}

