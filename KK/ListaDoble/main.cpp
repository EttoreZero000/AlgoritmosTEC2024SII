#include <iostream>
#include "listaDoble.h" // Asegúrate de que esta ruta sea correcta para tu proyecto

// Suponiendo que T es un tipo que tiene un método getId() y un operador de salida definido
class Elemento {
public:
    int id;
    std::string nombre;

    Elemento(int _id, const std::string& _nombre) : id(_id), nombre(_nombre) {}

    int getId() const { return id; }
    friend std::ostream& operator<<(std::ostream& os, const Elemento& elem) {
        os << "ID: " << elem.id << ", Nombre: " << elem.nombre;
        return os;
    }
    
    bool operator==(const Elemento& other) const {
        return id == other.id;
    }
};

int main() {
    ListaDoble<Elemento> lista;

    // Insertar elementos
    lista.insertarAlInicio(Elemento(1, "Elemento 1"));
    lista.insertarAlFinal(Elemento(2, "Elemento 2"));
    lista.insertarAlFinal(Elemento(3, "Elemento 3"));
    lista.insertarMedio(Elemento(4, "Elemento 4"));

    // Imprimir la lista
    std::cout << "Lista después de inserciones:" << std::endl;
    lista.imprimir();

    // Buscar un elemento
    NodoDoble<Elemento>* encontrado = lista.buscar(2);
    if (encontrado) {
        std::cout << "Elemento encontrado: " << encontrado->dato << std::endl;
    } else {
        std::cout << "Elemento no encontrado" << std::endl;
    }

    // Eliminar un elemento
    NodoDoble<Elemento>* eliminado = lista.eliminar(Elemento(3, "Elemento 3"));
    if (eliminado) {
        std::cout << "Elemento eliminado: " << eliminado->dato << std::endl;
        delete eliminado;
    } else {
        std::cout << "Elemento no encontrado para eliminar" << std::endl;
    }

    // Imprimir la lista después de eliminar un elemento
    std::cout << "Lista después de eliminar:" << std::endl;
    lista.imprimir();

    // Eliminar un elemento en una posición específica
    NodoDoble<Elemento>* eliminadoPos = lista.eliminarPosicion(1);
    if (eliminadoPos) {
        std::cout << "Elemento eliminado en posición 1: " << eliminadoPos->dato << std::endl;
        delete eliminadoPos;
    } else {
        std::cout << "Posición no válida o elemento no encontrado" << std::endl;
    }

    // Imprimir la lista después de eliminar en posición
    std::cout << "Lista después de eliminar en posición:" << std::endl;
    lista.imprimir();

    return 0;
}
