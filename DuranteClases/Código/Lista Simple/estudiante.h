#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <string>

class Estudiante {
public:
    std::string nombre;
    std::string apellido;
    std::string carrera;
    std::string fechaNacimiento;

    // Constructor
    
    Estudiante(std::string _nombre, std::string _apellido, std::string _carrera, std::string _fechaNacimiento)
        : nombre(_nombre), apellido(_apellido), carrera(_carrera), fechaNacimiento(_fechaNacimiento) {}
    // Método para mostrar la información del estudiante
    void imprimir() const;
};

#endif
