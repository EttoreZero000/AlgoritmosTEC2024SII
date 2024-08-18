
#include <iostream>
#include "listasimple.h"
#include "claseArmamento.h"

int main() {
	Armamento::loadNextId();
    // Crear una instancia de Armamento
    ListaSimple<bool>* atributos = new ListaSimple<bool>();
    atributos->insertarAlFinal(true);
    atributos->insertarAlFinal(false);

    ListaSimple<int>* modificadores = new ListaSimple<int>();
    modificadores->insertarAlFinal(10);
    modificadores->insertarAlFinal(20);

    Armamento miArmamento("Espada Mágica", atributos, 5, 2, 3, modificadores);

    // Imprimir el objeto
    miArmamento.imprimir();

    // Limpiar memoria
    delete atributos;
    delete modificadores;

    return 0;
}