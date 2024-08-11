#include <iostream>
#include "nodoclass.h"
class Estudiante {
private:
    std::string nombre;
    std::string apellido;
    std::string carrera;
    std::string fechaNacimiento;
public:
    //Contructor
    Estudiante(std::string _nombre, std::string _apellido, std::string _carrera, std::string _fechaNacimiento){
        nombre=_nombre;
        apellido=_apellido;
        carrera=_carrera;
        fechaNacimiento=_fechaNacimiento;
    };
};