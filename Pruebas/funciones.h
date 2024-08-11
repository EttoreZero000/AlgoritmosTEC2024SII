#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <fstream>

bool abrirArchivoEscritura(std::fstream& archivo, const std::string& nombreArchivo, bool tipo);
void cerrarArchivo(std::fstream& archivo);
#endif