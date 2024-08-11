#include "funciones.h"
#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>
#include <cstring>
bool esPar(int numero) {
    return (numero % 2 == 0);
}
int convertirABase10(const std::string& numero, int baseOriginal) {
    const char* digitos = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int valor = 0;
    int longitud = numero.length();

    for (int i = 0; i < longitud; ++i) {
        char c = numero[i];
        const char* posicion = std::strchr(digitos, c);
        if (!posicion || (posicion - digitos) >= baseOriginal) {
            throw std::invalid_argument("Número inválido para la base original");
        }
        int valorDigito = posicion - digitos;
        valor += valorDigito * std::pow(baseOriginal, longitud - 1 - i);
    }
    return valor;
}
std::string convertirDeBase10(int numero, int base) {
    if (base < 2 || base > 36) {
        return "Base no soportada";
    }
    const char* digitos = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string resultado;
    while (numero > 0) {
        int residuo = numero % base;
        resultado = digitos[residuo] + resultado;
        numero /= base;
    }
    if (resultado.empty()) {
        return "0";
    }
    return resultado;
}
std::string convertirBases(const std::string& numero, int baseOriginal, int baseDestino) {
    int numeroBase10 = convertirABase10(numero, baseOriginal);
    return convertirDeBase10(numeroBase10, baseDestino);
}