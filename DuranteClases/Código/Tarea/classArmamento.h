#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <iostream>
#include <string>
#include <memory>
#include <fstream>
#include "listasimple.h"

class Armamento {
private:
    int ID;
    int usos;
    int disponibles;
    std::string nombre;
    std::string tipo;
    ListaSimple<std::string> * atributo = new ListaSimple<std::string>(); //LS
    ListaSimple<std::string> * modificar = new ListaSimple<std::string>(); //LS

    static int counter;
    static bool isCounterInitialized;

    static void initializeCounter() {   
        std::ifstream infile("counter.txt");
        if (infile.good()) {
            infile >> counter;
        }
        else {
            counter = 0; // Si el archivo no existe, comenzamos desde cero
        }
        isCounterInitialized = true;
    }
    static int generateID() {
        if (!isCounterInitialized) {
            initializeCounter();
        }
        return ++counter;
    }
    static void saveCounter() {
        std::ofstream outfile("counter.txt");
        if (outfile.good()) {
            outfile << counter;
        }
    }

public:
    Armamento()
        : ID(generateID()){}
    Armamento(std::string _nombre, ListaSimple<std::string> * _atributos, int _usos, std::string _tipo, int _disponibles, ListaSimple<std::string> * _modificar)
        : ID(generateID()), nombre(_nombre), atributo(_atributos), usos(_usos), tipo(_tipo), disponibles(_disponibles), modificar(_modificar){}
    bool operator==(const Armamento& other) const {
        return ID == other.ID; // O cualquier otra comparación que consideres apropiada
    }
    // Métodos de acceso
    int getID() const { return ID; }
    int getUsos() const { return usos; }
    int getDisponibles() const { return disponibles; }
    const std::string& getNombre() const { return nombre; }
    const std::string& getTipo() const { return tipo; }
    ListaSimple<std::string>* getAtributo() const { return atributo; }
    ListaSimple<std::string>* getModificar() const { return modificar; }

    // Métodos de modificación
    void setID(int id) { ID = id; }
    void setUsos(int usos) { this->usos = usos; }
    void setDisponibles(int disponibles) { this->disponibles = disponibles; }
    void setNombre(const std::string& nombre) { this->nombre = nombre; }
    void setTipo(const std::string& tipo) { this->tipo = tipo; }
    void imprimir() const {
        std::cout << "ID: " << ID << ", "
                  << "Nombre: " << nombre << ", "
                  << "Tipo: " << tipo << ", "
                  << "Usos: " << usos << ", "
                  << "Disponibles: " << disponibles << std::endl;
    }
    friend std::ostream& operator<<(std::ostream& os, const Armamento& arm);
};
// Definición del operador de salida
#endif
