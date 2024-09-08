#ifndef CLASEMAP_H
#define CLASEMAP_H

#include <list>
#include <windows.h>  // Para COORD

class claseMap {
private:
    
public:
    int size;
    int floor;
    std::list<char> box;
    claseMap(int _size, int _floor);
    claseMap(int _size, int _floor, std::list<char> _box);
    void generarMapa();
    void imprimirBox(COORD consoleSize);
};

#endif // CLASEMAP_H
