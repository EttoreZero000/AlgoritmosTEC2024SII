#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <windows.h>

void hideCursor();
COORD getConsoleSize();
void printCentered(const std::string &text, int row, COORD consoleSize);
void printPos(const std::string &text, int row, int col);
void printMenu(std::string (&options)[5], int i, int &selectedOption, COORD consoleSize);
#endif // UTILS_H