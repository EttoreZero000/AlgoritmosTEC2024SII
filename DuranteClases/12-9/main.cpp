#include <iostream>
#include <vector>
#include "clase.h"
#include "utils.h"
int main(){

    estudiante e4("Hector", 2024086486, 7, 70, 82, {"Mate", "PC", "Hi"});
    estudiante e5("Manuel", 2024000000, 7, 69, 82, {"Mate", "PC", "Hi"});
    estudiante e6("Luis Roberto Arias", 200700001, 7, 82, 82, {"Mate", "PC", "Hi"});
    estudiante e1("Juanjo", 2024067821, 7, 82, 85, {"Mate", "PC", "Hi"});
    estudiante e2("Pinea Lizano", 2024123456, 10, 90, 99, {"Mate", "PC", "Hi"});
    estudiante e3("Jorge Monge Fallas", 2024234567, 12, 90, 100, {"Mate", "PC", "Hi"});
    estudiante e7("Joel Punombaya", 2024345678, 20, 90, 100, {"Mate", "PC", "Hi"});
    estudiante e8("Frander", 2024567890, 100, 90, 100, {"Mate", "PC", "Hi"});
    std::vector<estudiante> vectorEstudiante = {e1, e2, e3, e4, e5, e6, e7, e8};

    vectorEstudiante = ordenarBucketSort(vectorEstudiante);
    for (estudiante e : vectorEstudiante){
        e.imprimir();
        std::cout << std::endl;
    }
}