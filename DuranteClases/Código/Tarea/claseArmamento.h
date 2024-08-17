#include <iostream>
#include <fstream>
#include "listasimple.h"

class Armamento {
private:
    //Atributos
    int id;
    std::string nombre;
    ListaSimple<bool> listaAtributos;
    int usos;
    int tipo;
    int numeroDisponibles;
    ListaSimple<int> listaModificadores;
    //Metodos privados
    static int obtenerUltimoID() {
        std::ifstream archivo("ultimo_id.txt");
        int ultimoID = 0;
        if (archivo.is_open()) {
            archivo >> ultimoID;
            archivo.close();
        }
        return ultimoID;
    }
    static void guardarUltimoID(int ultimoID) {
        std::ofstream archivo("ultimo_id.txt");
        if (archivo.is_open()) {
            archivo << ultimoID;
            archivo.close();
        }
    }
    static int generarID() {
        int ultimoID = obtenerUltimoID();
        guardarUltimoID(ultimoID + 1);
        return ultimoID + 1;
    }
public:
    //Constructor
    Armamento()
        : id(generarID()), nombre(""), usos(0), tipo(0), numeroDisponibles(0){}
    Armamento(std::string _nombre, ListaSimple<bool> _listaAtributos, int _usos, int _tipo, int _numeroDisponibles, ListaSimple<int> _listaModificadores)
        : id(generarID()), nombre(_nombre), listaAtributos(_listaAtributos), usos(_usos), tipo(_tipo), numeroDisponibles(_numeroDisponibles), listaModificadores(_listaModificadores) {}
    void imprimir() const {
        std::cout << "ID: " << id << std::endl;
        std::cout << "Nombre: " << nombre << std::endl;
        std::cout << "Atributos: ";
        listaAtributos.imprimir();
        std::cout << "Usos: " << usos << std::endl;
        std::cout << "Tipo: " << tipo << std::endl;
        std::cout << "Numero Disponibles: " << numeroDisponibles << std::endl;
        std::cout << "Modificar: ";
        listaModificadores.imprimir();
    }
    ~Armamento() {
        // Destruir cualquier recurso si es necesario
    }
};
