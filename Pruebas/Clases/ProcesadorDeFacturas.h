// ProcesadorDeFacturas.h
#ifndef PROCESADOR_DE_FACTURAS_H
#define PROCESADOR_DE_FACTURAS_H

#include <fstream>
#include <vector>
#include <string>

class ProcesadorDeFacturas {
public:
    bool abrirArchivoEscritura(bool tipo);
    void cerrarArchivo();
    template<typename T>
    void escribirEnArchivo(const std::vector<T>& datos);
    template<typename T>
    void escribirEnArchivo(const T& dato);

    void setNombreArchivo(const std::string& nombre) { nombreArchivo = nombre; }
    std::string getNombreArchivo() const { return nombreArchivo; }

private:
    std::fstream archivo;
    std::string nombreArchivo;
};

#include "ProcesadorDeFacturas.tpp" // Asegúrate de incluir el archivo de implementación de plantillas

#endif // PROCESADOR_DE_FACTURAS_H
