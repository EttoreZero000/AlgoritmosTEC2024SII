#include <curses.h>
#include <cstring>

int main() {
    // Inicializa la pantalla
    initscr();
    
    // Habilita la entrada de teclas especiales
    keypad(stdscr, TRUE);
    
    // No muestra el cursor
    curs_set(0);
    
    // Obtiene el tamaño de la ventana
    int rows, cols;
    getmaxyx(stdscr, rows, cols);

    // El mensaje que queremos centrar
    const char* message = "111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111";
    int msg_len = strlen(message);

    // Calcula la posición horizontal para centrar el mensaje
    int start_col = (cols - msg_len) / 2;

    // Mueve el cursor a la posición deseada
    move(0, start_col);
    
    // Imprime el mensaje
    for (int i = 0; i < 30; ++i) {
        printw("%s", message);
    }
    
    // Muestra el contenido en la pantalla
    refresh();
    
    // Espera a que el usuario presione una tecla
    getch();
    
    // Finaliza la pantalla
    endwin();

    return 0;
}
