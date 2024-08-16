#include "Armamento.h"
#include <iostream>

Armamento::Armamento(int id, const std::string& nombre, const std::vector<std::string>& atributos, int usos, const std::string& tipo, int numeroDisponible, const std::vector<int>& modificadores)
    : id(id), nombre(nombre), atributos(atributos), usos(usos), tipo(tipo), numeroDisponible(numeroDisponible), modificadores(modificadores) {}

void Armamento::mostrarInformacion() const {
    std::cout << "ID: " << id << "\nNombre: " << nombre << "\nAtributos: ";
    for (const auto& atributo : atributos) {
        std::cout << atributo << " ";
    }
    std::cout << "\nUsos: " << usos << "\nTipo: " << tipo << "\nNumero Disponible: " << numeroDisponible << "\nModificadores: ";
    for (const auto& mod : modificadores) {
        std::cout << mod << " ";
    }
    std::cout << std::endl;
}

void Armamento::modificarAtributos(const std::vector<int>& nuevosModificadores) {
    modificadores = nuevosModificadores;
}
