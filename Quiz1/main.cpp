//Hector leiva 2024086486
//Copilador g++ de msys2 creo
#include <iostream>
#include "lista.h"
#include "clase.h"

void menu(){
    std::cout << "Menu\n1) Agregar Joyas\n2) Vender joya por nombre\n3) Lista por tipos\n4) Lista por precio menor\n5) Lista completa\n6) Mostrar 3 joyas, dos lado de un nombre\n7) Salir\nOpcion: ";
}
void agregarJoya(ListaCircularDoble<Joyas>& lista){
    std::string nombre, ubicacion;
    int tipo, year;
    float peso, precio;
    std::cout << "Nombre de joya: ";
    std::cin.ignore();
    std::getline(std::cin, nombre);
    std::cout << "Ubicacion de la joya (string): ";
    std::ignore;
    std::getline(std::cin, ubicacion);
    std::cout << "Tipo de joya. \n1) Collar \n2) Aretes \n3) Anillos \n4) Pulseras \n5) Compromiso \n6) Otros \nOpciones: ";
    std::cin >> tipo;
    std::cout << "Peso en gramos de la joya: ";
    std::cin >> peso;
    std::cout << "Precio de la joya: ";
    std::cin >> precio;
    std::cout << "Año de la joya: ";
    std::cin >> year;

    Joyas joyaNueva(nombre, ubicacion, tipo, year, peso, precio);
    lista.insertarMenorAMayor(joyaNueva);
}
void venderJoya(ListaCircularDoble<Joyas>& lista){
    std::string nombre;
    std::cout << "Que joya quieres vender: ";
    std::cin >> nombre;
    NodoCircularDoble<Joyas>* joyaVender = lista.buscar(nombre);
    joyaVender->anterior->siguiente=joyaVender->siguiente;
    joyaVender->siguiente->anterior=joyaVender->anterior;
}
void mostrarTipo(ListaCircularDoble<Joyas> lista){
    int tipo;
    std::cout << "Tipo de joya. \n1) Collar \n2) Aretes \n3) Anillos \n4) Pulseras \n5) Compromiso \n6) Otros \nOpciones: ";
    std::cin >> tipo;
    lista.imprimirTipo(tipo);
}
void mostrarPrecio(ListaCircularDoble<Joyas>& lista){
    float precio;
    std::cout << "Que precio para abajo quieres: ";
    std::cin >> precio;
    lista.imprimirPrecio(precio);
}
void mostarJoyaAntesDespues(ListaCircularDoble<Joyas>& lista){
    std::string nombre;
    std::cout << "Dime el nombre que quieres buscar y sus anterior y posterior: ";
    std::cin >> nombre;
    lista.mostarJoyaAntesDespues(nombre);
}
int main(){
    int opciones=0;
    ListaCircularDoble<Joyas> lista;
    while(true){
        menu();
        std::cin >> opciones;
        if (opciones==1){
            agregarJoya(lista);
            std::cout << "Joya agregada con exito" << std::endl;
        }else if (opciones==2)
        {
            venderJoya(lista);
            std::cout << "Se vendio la joya";
        }else if (opciones==3)
        {
            mostrarTipo(lista);
        }else if (opciones==4)
        {
            mostrarPrecio(lista);
        }else if (opciones==5)
        {
            lista.imprimir();
        }else if (opciones==6)
        {
            mostarJoyaAntesDespues(lista);
        }else if (opciones==7){
            return 0;
        }else{
            std::cout << "Elija una opcion valida";
        }
    }
    return 0;
}