#include "Clase.h"
#include <iostream>

// Implementación de Persona
Persona::Persona(std::string nombre, int edad, float altura, std::string ocupacion)
    : nombre(nombre), edad(edad), altura(altura), ocupacion(ocupacion) {}

void Persona::hablar(std::string mensaje) {
    std::cout << nombre << " dice: " << mensaje << std::endl;
}

void Persona::caminar(int distancia) {
    std::cout << nombre << " ha caminado " << distancia << " metros" << std::endl;
}

void Persona::trabajar() {
    std::cout << nombre << " está trabajando como " << ocupacion << std::endl;
}

void Persona::celebrarCumpleanos() {
    edad++;
    std::cout << "¡Feliz cumpleaños, " << nombre << "! Ahora tienes " << edad << " años" << std::endl;
}

// Implementación de Perro
Perro::Perro(std::string nombre, std::string raza, int edad, float peso)
    : nombre(nombre), raza(raza), edad(edad), peso(peso) {}

void Perro::ladrar() {
    std::cout << nombre << " está ladrando" << std::endl;
}

void Perro::comer(std::string comida) {
    std::cout << nombre << " está comiendo " << comida << std::endl;
}

void Perro::jugar(std::string juego) {
    std::cout << nombre << " está jugando con " << juego << std::endl;
}

void Perro::dormir(int horas) {
    std::cout << nombre << " ha dormido por " << horas << " horas" << std::endl;
}

// Implementación de Factura
Factura::Factura(int numero, std::string fecha, std::string cliente, double total)
    : numero(numero), fecha(fecha), cliente(cliente), total(total) {}

void Factura::agregarItem(std::string item, double precio) {
    total += precio;
    std::cout << "Item " << item << " agregado por " << precio << "€. Total actualizado: " << total << "€" << std::endl;
}

void Factura::aplicarDescuento(double porcentaje) {
    double descuento = total * (porcentaje / 100);
    total -= descuento;
    std::cout << "Descuento de " << porcentaje << "% aplicado. Total actualizado: " << total << "€" << std::endl;
}

void Factura::generarResumen() {
    std::cout << "Factura N°" << numero << "\nFecha: " << fecha << "\nCliente: " << cliente << "\nTotal: " << total << "€" << std::endl;
}

void Factura::actualizarCliente(std::string nuevoCliente) {
    cliente = nuevoCliente;
    std::cout << "Cliente actualizado a: " << nuevoCliente << std::endl;
}
