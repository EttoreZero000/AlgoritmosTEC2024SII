#include <iostream>
#include <math.h>
#include <string>

int main(){
    // Recordar que Diccionarios, Listas, entre otros son estructuras de datos no variables
    std::string a="Hola";
    int b=7;
    double c=20.1;
    float d=3.14;
    bool e=true;
    std::cout<< a <<std::endl;
    std::cout<< b <<std::endl;
    std::cout<< c <<std::endl;
    std::cout<< d <<std::endl;
    std::cout<< e <<std::endl;
    std::cout<< "Imprimir operaciones: " <<std::endl;
    std::cout<< b+c <<std::endl;
    std::cout<< c*d <<std::endl;
    std::cout<< d-c <<std::endl;
    std::cout<< d/c <<std::endl;
    std::cout<< pow(c,d) <<std::endl;
    std::cout<< pow(c,d) <<std::endl;
    std::cin.get();
}