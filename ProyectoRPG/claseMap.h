#ifndef CLASEMAP_H
#define CLASEMAP_H

#include <list>
#include <fstream>
#include <windows.h>  // Para COORD

class claseMap {
private:
    int size, x, y, floor;
    std::list<char> box;

public:
    claseMap(int _size, int _floor);
    claseMap(int _size, int _floor, std::list<char> _box);

    void setX(int x);
    int getX();
    void setY(int y);
    int getY();
    void generarMapa();
    void imprimirBox(COORD consoleSize, bool viewBox);
    char Casilla();
    int getFloor();
    void setFloor();
    void clearMap();
    std::list<char> getBox();
    
    void save(const std::string& filename) const;
    void load(const std::string& filename);
};

#endif // CLASEMAP_H
