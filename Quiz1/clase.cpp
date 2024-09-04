#include "clase.h"
#include <iostream>

int Joyas::nextId = 1;

// Constructor
Joyas::Joyas(std::string _nombre, std::string _ubicacion, int _tipo, int _year, float _peso, float _precio) 
    : id(nextId++), nombre(_nombre), ubicacion(_ubicacion), tipo(_tipo), peso(_peso), precio(_precio) {}
void Joyas::imprimir() const {
    std::cout << "------------------------------------" << std::endl;
    std::string nombresTipos[] = {"Collar", "Aretes", "Anillos", "Pulseras", "Anillo compromiso", "Otros"};
    std::cout << "ID: " << id << ", nombre: " << nombre << ", tipo: " << nombresTipos[tipo-1] <<", ubicacion: " << ubicacion << ", peso: " << peso << ", precio: " << precio << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Joyas& Joyas) {
    Joyas.imprimir();
    return os;
}

std::string Joyas::getNombre(){
    return nombre;
}
int Joyas::getTipo(){
    return tipo;
}