
#include "clase.h"
#include <iostream>

estudiante::estudiante(std::string _nombre, int _carnet, int _cantidadCursosAprobados, float _promedioGeneral, float _promedioSemestreAnterior, std::list<std::string> _listaDeCursosMatriculados)
    : nombre(_nombre), carnet(_carnet), cantidadCursosAprobados(_cantidadCursosAprobados), promedioGeneral(_promedioGeneral), promedioSemestreAnterior(_promedioSemestreAnterior), listaDeCursosMatriculados(_listaDeCursosMatriculados){
}

void estudiante::imprimir(){
    std::cout << nombre << std::endl;
    std::cout << carnet << std::endl;
    std::cout << cantidadCursosAprobados << std::endl;
    std::cout << promedioGeneral << std::endl;
    std::cout << promedioSemestreAnterior << std::endl;
}