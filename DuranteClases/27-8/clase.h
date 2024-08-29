#ifndef DISPOSITIVO_H
#define DISPOSITIVO_H

#include <string>

class Dispositivo {
private:
    std::string ID;
    char Tipo;
    char Estado;
    int Pureza;
public:
    // Constructor por defecto
    Dispositivo();
    // Constructor completo (sin ID)
    Dispositivo(std::string ID, char Tipo, char Estado, int Pureza);
    // Métodos set
    void setID(std::string ID);
    void setTipo(char Tipo);
    void setEstado(char Estado);
    void setPureza(int Pureza);
    //Metodos get
    std::string getID();
    char getTipo();
    char getEstado();
    int getPureza();
    //Metodo imprimir
    //void imprimir() const;
};
std::ostream& operator<<(std::ostream& os, const Dispositivo& armamento);
#endif // DISPOSITIVO_H
