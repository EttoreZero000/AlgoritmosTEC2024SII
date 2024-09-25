#ifndef CLASEMAP_H
#define CLASEMAP_H

#include <list>
#include <windows.h>  // Para COORD

class claseMap {
private:
    
public:
    int size, x, y, floor;
    std::list<char> box;
    
    claseMap(int _size, int _floor);
    claseMap(int _size, int _floor, std::list<char> _box);

    void setX(int x);
    void setY(int y);
    void generarMapa();
    void imprimirBox(COORD consoleSize, bool viewBox);
    char Casilla();
    int getFloor();
    void setFloor();
};

#endif // CLASEMAP_H
