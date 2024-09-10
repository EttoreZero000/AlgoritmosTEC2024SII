#include <cstdlib>
#include <ctime>
#include <iostream>
void proyectilParabolica(){
    srand(static_cast<unsigned>(time(NULL)));
    int numeroAngulo= rand() % 90;
    int numeroV_0= rand() % 1000;
    int numeroY= rand() % 500 - 250;
    std::cout << "Angulo: " << numeroAngulo << std::endl;
    std::cout << "Velocidad inicial: " <<numeroV_0 << " m/s" <<std::endl;
    std::cout << "Altura: " <<numeroY << " m" <<std::endl;
    std::cin.get();
    
    return;
}