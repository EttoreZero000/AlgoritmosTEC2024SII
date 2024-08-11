#include <iostream>
#include <windows.h>
#include "Clase.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);

    Persona persona("Juan", 30, 1.75, "Ingeniero");
    persona.hablar("Hola, ¿cómo estás?");
    persona.caminar(100);
    persona.trabajar();
    persona.celebrarCumpleanos();
    persona.celebrarCumpleanos();

    Perro perro("Fido", "Labrador", 5, 30.0);
    perro.ladrar();
    perro.comer("croquetas");
    perro.jugar("pelota");
    perro.dormir(8);

    Factura factura(12345, "2024-07-30", "ACME Corp.", 1000.0);
    factura.agregarItem("Producto A", 50.0);
    factura.aplicarDescuento(10);
    factura.generarResumen();
    factura.actualizarCliente("XYZ Ltd.");
    std::cin.get();
    return 0;
}
