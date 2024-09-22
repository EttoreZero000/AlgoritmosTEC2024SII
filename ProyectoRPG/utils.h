#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <windows.h>

void hideCursor();
COORD getConsoleSize();
void printCentered(const std::string &text, int row, COORD consoleSize);
void printPos(const std::string &text, int row, int col);
void printMenu(std::string (&options)[5], int i, int &selectedOption, COORD consoleSize, int cantidadLista);
void verHistoria(COORD consoleSize);
int menu(std::string title, std::string (&options)[5], int selectedOption, COORD consoleSize);
bool boolSize(COORD &prevConsoleSize, COORD &consoleSize);
void tablero(int selectedOption, COORD consoleSize, COORD prevConsoleSize, std::string* options);
void manejarPartidaNueva(COORD &consoleSize, COORD &prevConsoleSize, std::string (&options)[5], int &selectedOption);
#endif // UTILS_H