#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <windows.h>

void hideCursor();
COORD getConsoleSize();
void printCentered(const std::string &text, int row, COORD consoleSize);
#endif // UTILS_H