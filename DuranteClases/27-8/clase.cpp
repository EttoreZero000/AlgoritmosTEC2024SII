// clase.cpp
#include "clase.h"
#include <sstream> // Para convertir enteros a string

int Dispositivo::contadorID = 1; // Inicializar el contador

Dispositivo::Dispositivo(std::string ID, char Tipo, char Estado, int Pureza)
    : ID(ID), Tipo(Tipo), Estado(Estado), Pureza(Pureza) {
}

void Dispositivo::setID(std::string _ID) {
    ID = _ID;
}

void Dispositivo::setTipo(char _Tipo) {
    Tipo = _Tipo;
}

void Dispositivo::setEstado(char _Estado) {
    Estado = _Estado;
}

void Dispositivo::setPureza(int _Pureza) {
    Pureza = _Pureza;
}

std::string Dispositivo::getID() {
    return ID;
}

char Dispositivo::getTipo() {
    return Tipo;
}

char Dispositivo::getEstado() {
    return Estado;
}

int Dispositivo::getPureza() {
    return Pureza;
}

std::string Dispositivo::generarIDUnico() {
    std::ostringstream idStream;
    idStream << "D" << contadorID++; // Prefijo "D" para ID único
    return idStream.str();
}
