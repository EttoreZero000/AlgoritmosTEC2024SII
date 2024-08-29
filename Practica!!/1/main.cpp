#include "listaDoble.h"
int main(){
    ListaDoble lista;
    lista.insertarAlInicio(1);
    lista.insertarAlInicio(2);
    lista.insertarAlInicio(3);
    lista.insertarAlInicio(4);
    lista.insertarAlFinal(5);
    lista.imprimir();
    lista.imprimirUnico(2);
    return 0;
}