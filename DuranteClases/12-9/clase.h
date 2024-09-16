#ifndef CLASE_H
#define CLASE_H

#include <iostream>
#include <list>
#include <vector>

class estudiante {
private:
    
public:
    std::string nombre;
    int carnet, cantidadCursosAprobados;
    float promedioGeneral, promedioSemestreAnterior;
    std::list<std::string> listaDeCursosMatriculados;

    
    estudiante(std::string nombre, int carnet, int cantidadCursosAprobados, float promedioGeneral, float promedioSemestreAnterior, std::list<std::string> listaDeCurossMatriculados);

    std::vector<estudiante> ordenarBucketSort(std::vector<estudiante> estudiante);
    
    void imprimir();
};

#endif // CLASE_H
