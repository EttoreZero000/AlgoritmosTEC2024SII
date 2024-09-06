// clase.h
#ifndef CLASE_H
#define CLASE_H

#include <string>

class Dispositivo {
private:
    std::string ID;
    char Tipo;
    char Estado;
    int Pureza;

    static int contadorID; // Contador estático para generar IDs únicos

public:
    Dispositivo(std::string ID, char Tipo, char Estado, int Pureza);
    void setID(std::string _ID);
    void setTipo(char _Tipo);
    void setEstado(char _Estado);
    void setPureza(int _Pureza);
    std::string getID();
    char getTipo();
    char getEstado();
    int getPureza();

    static std::string generarIDUnico(); // Genera un ID único
};

#endif
