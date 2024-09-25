#include <iostream>
#include <conio.h>

int main() {
    std::cout << "Presiona una tecla...\n";
    int ch = _getch();  // Captura el primer valor

    if (ch == 0 || ch == 224) {
        // Si es una tecla especial, capturar el segundo valor
        ch = _getch();
        if (ch == 59) {  // 59 es el código para la tecla F1
            std::cout << "Tecla F1 presionada\n";
        } else {
            std::cout << "Otra tecla de función presionada: " << ch << "\n";
        }
    } else {
        std::cout << "Tecla ordinaria presionada: " << ch << "\n";
    }
    std::cin.get();
    return 0;
}
