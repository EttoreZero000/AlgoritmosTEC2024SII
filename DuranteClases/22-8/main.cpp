#include <iostream>
#include "pila.h"
#include "vehiculo.h"

int main(){
    pilaSimple<Vehiculo> pilaVehiculo;
    char y='y';
    while(y=='y'){
    std::string placa, marca, modelo, color;
    int year;
    std::cout << "Introducir placa: ";
    std::cin >> placa;
    std::cout << "Introducir marca: ";
    std::cin >> marca;
    std::cout << "Introducir modelo: ";
    std::cin >> modelo;
    std::cout << "Introducir color: ";
    std::cin >> color;
    std::cout << "Introducir year: ";
    std::cin >> year;

    Vehiculo objectoVehiculo(placa,marca,modelo,color,year);
    pilaVehiculo.insertarAlFinal(objectoVehiculo);

    std::cout << "Do you want to repeat the process: yes(y) or no(n): ";
    std::cin >> y;
    }
    pilaVehiculo.imprimir();
    return 0;
}