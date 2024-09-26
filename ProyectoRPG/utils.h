#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <windows.h>
#include "clases\personajesYEnemigos\personajesPrincipales.h"
#include "claseMap.h"

void maximizar();
void hideCursor();
COORD getConsoleSize();
void printCentered(const std::string &text, int row, COORD consoleSize);
void printPos(const std::string &text, int row, int col);
void printMenu(std::string (&options)[6], int i, int &selectedOption, COORD consoleSize, int cantidadLista);
void verHistoria(COORD consoleSize);
int menu(std::string title, std::string (&options)[6], int selectedOption, COORD consoleSize);
bool boolSize(COORD &prevConsoleSize, COORD &consoleSize);
void tablero(int selectedOption, COORD consoleSize, COORD prevConsoleSize, std::string* options);
void manejarPartidaNueva(COORD &consoleSize, COORD &prevConsoleSize, std::string (&options)[6], int &selectedOption);
int setDados();
void writesave();
void iniciar(COORD &consoleSize, std::string (&options)[6], int &selectedOption);
void crearMapa(claseMap &mapa, COORD &consoleSize, bool &viewBox);
personajesH crearPersonajePrincipal(std::list<personajesH> &aliados, const std::string &nombre, int fuerza, int agilidad, Arma &arma);
int manejarMenu(claseMap &mapa, COORD &consoleSize, std::string (&options)[6], int &selectedOption, bool &viewBox, bool &refresh);
#endif // UTILS_H