#ifndef LISTADOBLE_H
#define LISTADOBLE_H

#include "nodoDoble.h"
#include <iostream>

class ListaDoble {
private:
    NodoDoble* cabeza;
    NodoDoble* cola;
    int tamano;

public:
    ListaDoble() : cabeza(nullptr), cola(nullptr), tamano(0) {}

    bool estaVacia() const {
        return tamano == 0;
    }

    int obtenerTamano() const {
        return tamano;
    }

    void insertar(const Juguete& juguete) {
        NodoDoble* nuevo = new NodoDoble(juguete);

        if (estaVacia()) {
            cabeza = cola = nuevo;
        } else if (tamano == 1) {
            // Si solo hay un elemento, el nuevo se inserta al final
            nuevo->anterior = cola;
            cola->siguiente = nuevo;
            cola = nuevo;
        } else {
            // Encontrar la posición del medio
            NodoDoble* medio = cabeza;
            for (int i = 0; i < tamano / 2; i++) {
                medio = medio->siguiente;
            }

            // Insertar en el medio
            nuevo->siguiente = medio;
            nuevo->anterior = medio->anterior;
            if (medio->anterior) {
                medio->anterior->siguiente = nuevo;
            }
            medio->anterior = nuevo;

            // Si se inserta al inicio, actualizar la cabeza
            if (nuevo->anterior == nullptr) {
                cabeza = nuevo;
            }
        }

        tamano++;
    }

    void eliminar() {
        if (estaVacia()) {
            std::cout << "La lista está vacía, no se puede eliminar ningún juguete.\n";
            return;
        }

        NodoDoble* temp;
        if (tamano % 2 == 0) {
            // Eliminar del inicio si el tamaño es par
            temp = cabeza;
            cabeza = cabeza->siguiente;
            if (cabeza) cabeza->anterior = nullptr;
        } else {
            // Eliminar del final si el tamaño es impar
            temp = cola;
            cola = cola->anterior;
            if (cola) cola->siguiente = nullptr;
        }

        delete temp;
        tamano--;

        if (tamano == 0) cabeza = cola = nullptr;
    }

    void venderJuguete(const std::string& nombre) {
        NodoDoble* actual = cabeza;
        while (actual != nullptr) {
            if (actual->dato.nombre == nombre) {
                if (actual->dato.unidadesDisponibles > 0) {
                    actual->dato.unidadesDisponibles--;
                    std::cout << "Se ha vendido una unidad de " << nombre << ". Unidades restantes: " << actual->dato.unidadesDisponibles << "\n";
                } else {
                    std::cout << "No hay unidades disponibles para vender de " << nombre << ".\n";
                }
                return;
            }
            actual = actual->siguiente;
        }
        std::cout << "Juguete " << nombre << " no encontrado.\n";
    }

    void buscarJuguete(const std::string& nombre) const {
        NodoDoble* actual = cabeza;
        int posicion = 1;
        while (actual != nullptr) {
            if (actual->dato.nombre == nombre) {
                std::cout << "Juguete encontrado en la posición " << posicion << " con " << actual->dato.unidadesDisponibles << " unidades disponibles.\n";
                return;
            }
            actual = actual->siguiente;
            posicion++;
        }
        std::cout << "Juguete " << nombre << " no encontrado.\n";
    }

    void mostrarLista() const {
        NodoDoble* actual = cabeza;
        while (actual != nullptr) {
            std::cout << "Nombre: " << actual->dato.nombre << ", Marca: " << actual->dato.marca
                      << ", Año de emisión: " << actual->dato.anioEmision << ", Precio: $" << actual->dato.precioPorUnidad
                      << ", Unidades disponibles: " << actual->dato.unidadesDisponibles << "\n";
            actual = actual->siguiente;
        }
    }
};

#endif
    