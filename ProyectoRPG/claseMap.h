#ifndef CLASEMAP_H
#define CLASEMAP_H

#include <vector>
#include <windows.h>  // Para COORD

class claseMap {
private:
    
public:
    int size;
    int floor;
    std::vector<char> box;
    
    claseMap(int _size, int _floor);
    claseMap(int _size, int _floor, std::vector<char> _box);

    void generarMapa();
    void imprimirBox(COORD consoleSize);
    char verCasilla(int x, int y);
};

#endif // CLASEMAP_H
