#ifndef CLASE_H
#define CLASE_H

#include <string>

class Persona {
public:
    std::string nombre;
    int edad;
    float altura;
    std::string ocupacion;

    Persona(std::string nombre, int edad, float altura, std::string ocupacion);

    void hablar(std::string mensaje);
    void caminar(int distancia);
    void trabajar();
    void celebrarCumpleanos();
};

class Perro {
public:
    std::string nombre;
    std::string raza;
    int edad;
    float peso;

    Perro(std::string nombre, std::string raza, int edad, float peso);

    void ladrar();
    void comer(std::string comida);
    void jugar(std::string juego);
    void dormir(int horas);
};

class Factura {
public:
    int numero;
    std::string fecha;
    std::string cliente;
    double total;

    Factura(int numero, std::string fecha, std::string cliente, double total);

    void agregarItem(std::string item, double precio);
    void aplicarDescuento(double porcentaje);
    void generarResumen();
    void actualizarCliente(std::string nuevoCliente);
};

#endif // CLASE_H
