#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>

bool esPar(int numero);
int convertirABase10(const std::string& numero, int baseOriginal);
std::string convertirDeBase10(int numero, int base);
std::string convertirBases(const std::string& numero, int baseOriginal, int baseDestino);
#endif
