#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <string>

#include "funciones.h"
// Función para abrir el archivo
bool abrirArchivoEscritura(std::fstream& archivo, const std::string& nombreArchivo, bool tipo) {
    if(tipo){
    archivo.open(nombreArchivo, std::ios::out);
    return archivo.is_open();
    }else{
        archivo.open(nombreArchivo, std::ios::in);
    return archivo.is_open();
    }
}
// Función para cerrar el archivo
void cerrarArchivo(std::fstream& archivo) {
    if (archivo.is_open()) {
        archivo.close();
    }
}
// Función para escribir en el archivo
template<typename T>
void escribirEnArchivo(std::fstream& archivo, const T& dato) {
    if (archivo.is_open()) {
        archivo << dato << std::endl;
    }
}