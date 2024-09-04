#ifndef JOYA_H
#define JOYA_H

#include <string>
#include <fstream>

class Joyas {
public:
    int id, tipo;
    std::string nombre, ubicacion;
    float precio, peso;
    // Constructor completo (sin ID)
    Joyas(std::string nombre, std::string ubicacion, int tipo, int year, float peso, float precio);
    //Metodos varios
    void imprimir() const;
    std::string getNombre();
    int getTipo();
private:
    static int nextId; // Variable estática para generar IDs automáticamente
};
std::ostream& operator<<(std::ostream& os, const Joyas& armamento);
#endif // JOYA_H
