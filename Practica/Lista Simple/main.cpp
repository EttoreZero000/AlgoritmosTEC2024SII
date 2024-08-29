
#include <iostream>
#include "listasimple.h"
#include "listadoble.h"
#include "listacircular.h"

int main(){

	// PRUEBAS
	
	ListaSimple * L1 = new ListaSimple();
	ListaDoble * L2 = new ListaDoble();
	ListaCircular * L3 = new ListaCircular();
	L1->insertarAlInicio(1);
	L2->insertarAlInicio(1);
	L3->insertarAlInicio(1);
	L1->insertarAlInicio(2);
	L2->insertarAlInicio(2);
	L3->insertarAlInicio(2);
	L1->insertarAlInicio(3);
	L2->insertarAlInicio(3);
	L3->insertarAlInicio(3);
	L1->insertarAlInicio(4);
	L2->insertarAlInicio(4);
	L3->insertarAlInicio(4);

	// 4 3 2 1

	L1->imprimir();
	L2->imprimir();
	L3->imprimir();

	L1->insertarAlFinal(5);
	L2->insertarAlFinal(5);
	L3->insertarAlFinal(5);

	// 4 3 2 1 5
	L1->imprimir();
	L2->imprimir();
	L3->imprimir();

	Nodo * e1 = L1->eliminar(5);
	NodoDoble * e2 = L2->eliminar(5);
	NodoCircular * e3 = L3->eliminar(5);


	(e1 != NULL) ? std::cout << "Se elimino de la lista simple el " << e1->dato << std::endl : std::cout << "No lo encontro" << std::endl;
	(e2 != NULL) ? std::cout << "Se elimino de la lista doble el " << e2->dato << std::endl : std::cout << "No lo encontro" << std::endl;
	(e3 != NULL) ? std::cout << "Se elimino de la lista circular el " << e3->dato << std::endl : std::cout << "No lo encontro" << std::endl;

	delete e1;
	delete e2;
	delete e3;

	// 4 3 2 1
	L1->imprimir();
	L2->imprimir();
	L3->imprimir();

	Nodo * f1 = L1->eliminar(4);
	NodoDoble * f2 = L2->eliminar(4);
	NodoCircular * f3 = L3->eliminar(4);

	(f1 != NULL) ? std::cout << "Se elimino de la lista simple el " << f1->dato << std::endl : std::cout << "No lo encontro" << std::endl;
	(f2 != NULL) ? std::cout << "Se elimino de la lista doble el " << f2->dato << std::endl : std::cout << "No lo encontro" << std::endl;
	(f3 != NULL) ? std::cout << "Se elimino de la lista circular el " << f3->dato << std::endl : std::cout << "No lo encontro" << std::endl;

	delete f1;
	delete f2;
	delete f3;

	// 3 2 1
	L1->imprimir();
	L2->imprimir();
	L3->imprimir();

	Nodo * g1 = L1->eliminar(2);
	NodoDoble * g2 = L2->eliminar(2);
	NodoCircular * g3 = L3->eliminar(2);

	(g1 != NULL) ? std::cout << "Se elimino de la lista simple el " << g1->dato << std::endl : std::cout << "No lo encontro" << std::endl;
	(g2 != NULL) ? std::cout << "Se elimino de la lista doble el " << g2->dato << std::endl : std::cout << "No lo encontro" << std::endl;
	(g3 != NULL) ? std::cout << "Se elimino de la lista circular el " << g3->dato << std::endl : std::cout << "No lo encontro" << std::endl;

	delete g1;
	delete g2;
	delete g3;

	// 3 1
	L1->imprimir();
	L2->imprimir();
	L3->imprimir();

	Nodo * h1 = L1->eliminar(1);
	NodoDoble * h2 = L2->eliminar(1);
	NodoCircular * h3 = L3->eliminar(1);

	(h1 != NULL) ? std::cout << "Se elimino de la lista simple el " << h1->dato << std::endl : std::cout << "No lo encontro" << std::endl;
	(h2 != NULL) ? std::cout << "Se elimino de la lista doble el " << h2->dato << std::endl : std::cout << "No lo encontro" << std::endl;
	(h3 != NULL) ? std::cout << "Se elimino de la lista circular el " << h3->dato << std::endl : std::cout << "No lo encontro" << std::endl;

	delete h1;
	delete h2;
	delete h3;

	// 3
	L1->imprimir();
	L2->imprimir();
	L3->imprimir();

	Nodo * i1 = L1->eliminar(3);
	NodoDoble * i2 = L2->eliminar(3);
	NodoCircular * i3 = L3->eliminar(3);

	(i1 != NULL) ? std::cout << "Se elimino de la lista simple el " << i1->dato << std::endl : std::cout << "No lo encontro" << std::endl;
	(i2 != NULL) ? std::cout << "Se elimino de la lista doble el " << i2->dato << std::endl : std::cout << "No lo encontro" << std::endl;
	(i3 != NULL) ? std::cout << "Se elimino de la lista circular el " << i3->dato << std::endl : std::cout << "No lo encontro" << std::endl;

	delete i1;
	delete i2;
	delete i3;

	// 
	L1->imprimir();
	L2->imprimir();
	L3->imprimir();


	return 0;
}

