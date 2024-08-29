#include <iostream>
#include "listaSimple.h"

int main(){
    ListaSimple<int> lista;
    lista.insertarAlFinal(1);
    lista.insertarAlFinal(2);
    lista.insertarAlFinal(3);
    lista.insertarAlFinal(3);
    lista.insertarAlFinal(4);
    int a=lista.esPar();
    std::cout << a << std::endl;
    lista.imprimir();
    lista.insertarMedio(4);
    lista.imprimir();
    lista.eliminarPosicion(0);
    lista.imprimir();
}