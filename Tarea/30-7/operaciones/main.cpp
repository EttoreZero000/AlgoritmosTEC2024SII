#include <iostream>
#include <cmath> // Para la función pow

using namespace std;

// Función para sumar dos números
double sumar(double a, double b) {
    return a + b;
}

// Función para restar dos números
double restar(double a, double b) {
    return a - b;
}

// Función para multiplicar dos números
double multiplicar(double a, double b) {
    return a * b;
}

// Función para dividir dos números
double dividir(double a, double b) {
    if (b != 0) {
        return a / b;
    } else {
        cout << "Error: División por cero no permitida." << endl;
        return 0;
    }
}

// Función para potenciar un número
double potenciar(double base, double exponente) {
    return pow(base, exponente);
}

int main() {
    double num1, num2;

    cout << "Ingrese el primer número: ";
    cin >> num1;
    cout << "Ingrese el segundo número: ";
    cin >> num2;

    cout << "Resultados:" << endl;
    cout << "Suma: " << sumar(num1, num2) << endl;
    cout << "Resta: " << restar(num1, num2) << endl;
    cout << "Multiplicación: " << multiplicar(num1, num2) << endl;
    cout << "Potenciación: " << potenciar(num1, num2) << endl;

    cout << "Presiona Enter para salir...";
    cin.ignore();
    cin.get();

    return 0;
}
