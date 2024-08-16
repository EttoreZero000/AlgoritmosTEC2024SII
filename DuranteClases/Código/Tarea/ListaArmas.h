#ifndef LISTAARMAS_H
#define LISTAARMAS_H

#include "Armamento.h"

class Nodo {
public:
    Armamento arma;
    Nodo* siguiente;

    Nodo(const Armamento& arma);
};

class ListaArmas {
private:
    Nodo* cabeza;
    int contadorId; // Para generar IDs automáticamente

    void guardarEnDisco();
    void cargarDesdeDisco();

public:
    ListaArmas();
    ~ListaArmas();

    void agregarArma(const Armamento& arma);
    void modificarArmas(int id, const std::vector<int>& nuevosModificadores);
    void sacarArma(int id);
    void evolucionarArma(int id, const std::vector<int>& nuevosModificadores);
    void mostrarArmas() const;
    void guardarEnArchivo() const;
};

#endif // LISTAARMAS_H
