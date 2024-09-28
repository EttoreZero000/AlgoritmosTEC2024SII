#include <iostream>
#include <conio.h>    // Para _kbhit() y _getch()
#include <windows.h>  // Para COORD
#include <thread>     // Para sleep_for
#include <chrono>     // Para milliseconds
#include <fstream>    //Guardar y cargar partidas
#include <sstream>
#include "claseMap.h"
#include "clases/personajesYEnemigos/padre.h"
#include "controladorAcciones.h"
#include "clases/personajesYEnemigos/personajesPrincipales.h"
#include "clases/personajesYEnemigos/enemigos.h"
#include "clases/Armamento/claseArmamento.h"


std::list<personajesH> cargarListaAliados() {
    std::ifstream inFile("appDeDesarrollo/crearAliados/aliados.txt");
    std::list<personajesH> listaAliados;

    if (!inFile.is_open()) {
        std::cerr << "No se pudo abrir el archivo para leer.\n";
        return listaAliados;  // Retorna lista vacía si falla al abrir el archivo
    }

    std::string line;
    while (std::getline(inFile, line)) {
        std::istringstream iss(line);
        std::string nombre, armaNombre;
        int vida, ataque, oro, _vidaMaxima, armaDamage;
        bool tipoPersonaje;

        // Leer los campos separados por coma
        std::getline(iss, nombre, ',');
        iss >> vida;
        iss.ignore(); // Ignorar la coma
        iss >> ataque;
        iss.ignore(); // Ignorar la coma
        iss >> oro;  // Leer el oro como el último valor
        iss.ignore(); // Ignorar la coma
        iss >> tipoPersonaje;
        iss.ignore(); // Ignorar la coma
        std::getline(iss, armaNombre, ','); // Leer el nombre del arma hasta la siguiente coma
        iss >> armaDamage;
        iss.ignore(); // Ignorar la coma
        iss >> _vidaMaxima;  // Leer el oro como el último valor

        // Crear objeto `Arma` y `enemigos`
        Arma arma(armaNombre, armaDamage);
        personajesH personaje(nombre, vida, ataque, tipoPersonaje, arma, oro, _vidaMaxima);
        listaAliados.push_back(personaje);
    }
    inFile.close();
    return listaAliados;
}


std::list<enemigos> cargarListaEnemigos() {
    std::ifstream inFile("appDeDesarrollo/crearEnemigos/enemigos.txt");
    std::list<enemigos> listaEnemigos;

    if (!inFile.is_open()) {
        std::cerr << "No se pudo abrir el archivo para leer.\n";
        return listaEnemigos;  // Retorna lista vacía si falla al abrir el archivo
    }

    std::string line;
    while (std::getline(inFile, line)) {
        std::istringstream iss(line);
        std::string nombre, armaNombre;
        int vida, ataque, oro, armaDamage;
        bool tipoPersonaje, comp;

        // Leer los campos separados por coma
        std::getline(iss, nombre, ',');
        iss >> vida;
        iss.ignore(); // Ignorar la coma
        iss >> ataque;
        iss.ignore(); // Ignorar la coma
        iss >> tipoPersonaje;
        iss.ignore(); // Ignorar la coma
        std::getline(iss, armaNombre, ','); // Leer el nombre del arma hasta la siguiente coma
        iss >> armaDamage;
        iss.ignore(); // Ignorar la coma
        iss >> comp;
        iss.ignore(); // Ignorar la coma
        iss >> oro;  // Leer el oro como el último valor

        // Crear objeto `Arma` y `enemigos`
        Arma arma(armaNombre, armaDamage);
        enemigos enemigo(nombre, vida, ataque, tipoPersonaje, arma, comp, oro);
        listaEnemigos.push_back(enemigo);
    }

    inFile.close();
    return listaEnemigos;
}

// CARGAR LISTA ARMAS

std::list<Arma> cargarListaArmas() {

    std::ifstream inFile("appDeDesarrollo/crearArmas/armas.txt");
    std::list<Arma> listaArmas;

    if (!inFile.is_open()) {
        std::cerr << "No se pudo abrir el archivo para leer.\n";
        return listaArmas; // Es mejor usar return en lugar de exit.
    }

    std::string line;
    while (std::getline(inFile, line)) {
        std::istringstream iss(line);
        std::string nombre;
        int damage;

        // Leer el nombre hasta la coma
        std::getline(iss, nombre, ',');

        // Leer el valor de damage
        iss >> damage;

        // Crear el objeto Arma y agregarlo a la lista
        Arma arma(nombre, damage);
        listaArmas.push_back(arma);
    }

    inFile.close();
    return listaArmas;
}



// Maximizar la ventana
void maximizar() {
    HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd, WS_MINIMIZE);
}

// Número random de 1 a 6
int setDados(){
    return rand() % 6 + 1;
}
// Ocultar el cursor
void hideCursor() { 
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE; // Ocultar el cursor
    SetConsoleCursorInfo(consoleHandle, &info);
}

// Función para obtener el tamaño de la consola real
COORD getConsoleSize() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    COORD size;
    size.X = csbi.srWindow.Right - csbi.srWindow.Left + 1; // Columnas
    size.Y = csbi.srWindow.Bottom - csbi.srWindow.Top + 1; // Filas
    return size;
}

// Función que gestiona el tamaño de la consola
bool boolSize(COORD &prevConsoleSize, COORD &consoleSize){
    consoleSize = getConsoleSize();
    if(consoleSize.X != prevConsoleSize.X || consoleSize.Y != prevConsoleSize.Y){
        prevConsoleSize = consoleSize;
        system("cls");
        return true;
    }
    return false;
}

// Función para imprimir un texto centrado en una fila específica
void printCentered(const std::string &text, int row, COORD consoleSize) {
    int col = (consoleSize.X - text.length()) / 2;
    COORD pos = { (short)col, (short)row };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    std::cout << text;
}

// Posicionar en X y Y arbitrarias
void printPos(const std::string &text, int row, int col) {
    COORD pos = { (short)col, (short)row };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    std::cout << text;
}

// Mostrar la historia
void verHistoria(COORD consoleSize){
    system("cls");
    printCentered("Thorfinn es un vikingo que quiere matar a sus enemigos por ver sangre de sus enemigos.", consoleSize.Y/2, consoleSize);
    Sleep(1000);
    printCentered("Thorfinn viaja a un calabozo para matar a los enemigos más fuertes.", consoleSize.Y/2+2, consoleSize);
    printCentered("Para demostrar a su padre que su hijo es el más fuerte del planeta.", consoleSize.Y/2+3, consoleSize);
    Sleep(1000);
    printPos("Preciono Z o A para continuar", consoleSize.Y, consoleSize.X-29);
    while (true){
        if(controladorInput()==5){
            break;
        }
    }
}

// Función auxiliar para mostrar el menú rápidamente
void printMenu(std::string (&options)[9], int startIndex, int &selectedOption, COORD consoleSize, int cantidadLista) {
    for (int i = 0; i < cantidadLista+1; i++) {
        int optionIndex = startIndex + i;
        if (optionIndex == selectedOption) {
            printCentered("> " + options[optionIndex] + " <", (consoleSize.Y / 1.2) + i, consoleSize);
        } else {
            printCentered(options[optionIndex], (consoleSize.Y / 1.2) + i, consoleSize);
        }
    }
}

void printMenuArmas(const std::list<Arma> &listaArmas, std::list<Arma>::const_iterator selectedOption) {
    system("cls"); // Limpiar la pantalla
    int PosArma = 0;
    for (auto it = listaArmas.begin(); it != listaArmas.end(); ++it) {
        if (it == selectedOption) {
            std::string arma = ">" + it->nombre + " | Daño: " + std::to_string(it->damage) + "<"; 
            printPos(arma, PosArma, 0);
        } else {
            std::string arma = it->nombre + " | Daño: " + std::to_string(it->damage); 
            printPos(arma, PosArma, 0);
        }
        PosArma++;
    }
}

// Función para manejar la navegación del menú
Arma manejarMenuArmas(std::list<Arma> &listaArmas, std::list<Arma>::iterator &selectedOption, bool& refresh) {
    int input;
    auto previousOption = selectedOption; // Guardar el estado inicial
    printMenuArmas(listaArmas, selectedOption);

    while (true) {
        // Verificar si hay un cambio entre la opción anterior y la actual
        if (previousOption != selectedOption) {
            printMenuArmas(listaArmas, selectedOption); // Mostrar el menú solo si ha habido un cambio
            previousOption = selectedOption; // Actualizar la opción previa
        }

        input = controladorInput(); // Capturar la entrada del usuario

        if (input == 1) { // Presiona abajo
            ++selectedOption;
            if (selectedOption == listaArmas.end()) selectedOption = listaArmas.begin(); // Si supera el límite, regresa al primero
            Sleep(250);
        }
        else if (input == 2) { // Presiona arriba
            if (selectedOption == listaArmas.begin()) {
                selectedOption = listaArmas.end(); // Si está en el primero y sube, va al último
            }
            --selectedOption;
            Sleep(250);
        }
        else if (input == 5) { // Presiona Enter
            // Puntero del Arma seleccionada
            Arma armaSeleccionada = *selectedOption;
            listaArmas.erase(selectedOption);
            refresh = true;
            return armaSeleccionada;
        }
    }
}

void printMenuAliados(const std::list<personajesH> &listaAliados, std::list<personajesH>::const_iterator selectedOption) {
    system("cls"); // Limpiar la pantalla
    int PosAliado = 0;
    for (auto it = listaAliados.begin(); it != listaAliados.end(); ++it) {
        if (it == selectedOption) {
            std::string aliado = ">" + it->getNombre() + "<"; // Muestra el aliado seleccionado
            printPos(aliado, PosAliado, 0);
        } else {
            std::string aliado = it->getNombre(); // Muestra los demás aliados
            printPos(aliado, PosAliado, 0);
        }
        PosAliado++;
    }
}

// Función para manejar la navegación del menú de aliados
personajesH& manejarMenuAliados(std::list<personajesH> &listaAliados, std::list<personajesH>::iterator &selectedOption) {
    int input;
    auto previousOption = selectedOption; // Guardar el estado inicial
    printMenuAliados(listaAliados, selectedOption);

    while (true) {
        // Verificar si hay un cambio entre la opción anterior y la actual
        if (previousOption != selectedOption) {
            printMenuAliados(listaAliados, selectedOption); // Mostrar el menú solo si ha habido un cambio
            previousOption = selectedOption; // Actualizar la opción previa
        }

        input = controladorInput(); // Capturar la entrada del usuario

        if (input == 1) { // Presiona abajo
            ++selectedOption;
            if (selectedOption == listaAliados.end()) selectedOption = listaAliados.begin(); // Regresar al primero
            Sleep(250);
        }
        else if (input == 2) { // Presiona arriba
            if (selectedOption == listaAliados.begin()) {
                selectedOption = listaAliados.end(); // Si está en el primero y sube, va al último
            }
            --selectedOption;
            Sleep(250);
        }
        else if (input == 5) { // Presiona Enter
            return *selectedOption; // Retorna el aliado seleccionado
        }
    }
}

void actualizarVidaMaxima(std::list<personajesH> &listaAliados) {
    for (auto &aliado : listaAliados) { // Iterar sobre cada aliado en la lista
        aliado.setVidaMaxima(); // Aplicar setVidaMaxima
    }
}
void actualizarVida(std::list<personajesH> &listaAliados) {
    for (auto &aliado : listaAliados) { // Iterar sobre cada aliado en la lista
        aliado.curarVida(); // Aplicar setVidaMaxima
    }
}

void asignarArmaAaliado(std::list<Arma> &listaArmas, std::list<personajesH> &listaAliados, bool &refresh) {
    
    std::list<personajesH>::iterator selectedAliado = listaAliados.begin();
    personajesH& aliadoSeleccionado = manejarMenuAliados(listaAliados, selectedAliado);

    Arma preArma = aliadoSeleccionado.getArma();

    std::list<Arma>::iterator selectArma = listaArmas.begin();
    Arma armaSeleccionada = manejarMenuArmas(listaArmas, selectArma, refresh);
    
    aliadoSeleccionado.setArma(armaSeleccionada);

    listaArmas.push_back(preArma);
}


// Menú que se actualiza cuando hay un cambio de selección o de tamaño de la consola
int menu(std::string title, std::string (&options)[9], int selectedOption, COORD consoleSize) {
    COORD prevConsoleSize = consoleSize;
    int prevSelectedOption = -1;

    // Dibujar el menú la primera vez
    system("cls");
    printCentered(title, consoleSize.Y / 4, consoleSize);
    for (int i = 0; i < 3; i++) {
        if (i == selectedOption) {
            printCentered("> " + options[i] + " <", (consoleSize.Y / 2) + i, consoleSize);
        } else {
            printCentered(options[i], (consoleSize.Y / 2) + i, consoleSize);
        }
    }

    while (true) {
        consoleSize = getConsoleSize();
        if (consoleSize.X != prevConsoleSize.X || consoleSize.Y != prevConsoleSize.Y) {
            prevConsoleSize = consoleSize;
            system("cls");
            printCentered(title, consoleSize.Y / 4, consoleSize);
            for (int i = 0; i < 3; i++) {
                if (i == selectedOption) {
                    printCentered("> " + options[i] + " <", (consoleSize.Y / 2) + i, consoleSize);
                } else {
                    printCentered(options[i], (consoleSize.Y / 2) + i, consoleSize);
                }
            }
        }
        int input = controladorInput();
        if (input > 0) {
            if (input == 2) { // Flecha hacia arriba
                selectedOption--;
                if (selectedOption < 0) selectedOption = 2;
            } else if (input == 1) { // Flecha hacia abajo
                selectedOption++;
                if (selectedOption > 2) selectedOption = 0;
            } else if (input == 5) { // Enter
                return selectedOption;
            }
            if (selectedOption != prevSelectedOption) {
                prevSelectedOption = selectedOption;
                system("cls");
                printCentered(title, consoleSize.Y / 4, consoleSize);
                for (int i = 0; i < 3; i++) {
                    if (i == selectedOption) {
                        printCentered("> " + options[i] + " <", (consoleSize.Y / 2) + i, consoleSize);
                    } else {
                        printCentered(options[i], (consoleSize.Y / 2) + i, consoleSize);
                    }
                }
            }
        }
        Sleep(0);
    }
}

void crearMapa(claseMap &mapa, COORD &consoleSize, bool &viewBox) {
    mapa.setFloor();
    mapa.setX(0);
    mapa.setY(0);
    mapa.generarMapa();
    mapa.imprimirBox(consoleSize, viewBox);
}

personajesH crearPersonajePrincipal(std::list<personajesH> &listaAliados, const std::string &nombre, int fuerza, int agilidad, Arma &arma) {
    personajesH personajeP(nombre, fuerza, agilidad, true, arma, 0, 3);
    listaAliados.push_back(personajeP);
    return personajeP;
}

int manejarMenu(claseMap &mapa, COORD &consoleSize, std::string (&options)[9], int &selectedOption, bool &viewBox, bool &refresh, int indice, int cantidad) {
    int prevSelectedOption = selectedOption;
    
    // Manejo de input
    int input = controladorInput();
    
    if (input > 0) {
        // Movimiento hacia arriba
        if (input == 2) {
            selectedOption--;
            if (selectedOption < indice) selectedOption = cantidad+indice; // Mantener dentro del rango
        }
        // Movimiento hacia abajo
        
        else if (input == 1) {
            selectedOption++;
            if (selectedOption > cantidad+indice) selectedOption = indice; // Mantener dentro del rango
        }
        // Si se presiona Enter, salir del bucle
        else if (input == 5) {
            return selectedOption;
        }
        // Preciona F1
        else if (input == 10) {
            viewBox = !viewBox;
            refresh = true;
        }

        // Actualizar si la selección ha cambiado o si se requiere refrescar
        if (selectedOption != prevSelectedOption || refresh) {
            refresh = false;
            prevSelectedOption = selectedOption;
            system("cls"); // Limpia la pantalla antes de dibujar
            // Imprimir el submenú
            mapa.imprimirBox(consoleSize, viewBox);
            printMenu(options, indice, selectedOption, consoleSize, cantidad);
        }
    }
    return 0;
}

void manejarPartidaNueva(COORD &consoleSize, COORD &prevConsoleSize, std::string (&options)[9], int &selectedOption) {
    //Cargar aqui las armas ya creadas.
    //Cargar aqui las enemigos ya creadas.
    std::list<Arma> listaCargadaArmas = cargarListaArmas();
    std::list<enemigos> listaCargadaEnemigos = cargarListaEnemigos();
    std::list<personajesH> listaCargadaAliados = cargarListaAliados();

    std::srand(std::time(0));
    bool viewBox = false, refresh = false, vidaCero = false;
    int tiradas=10;
    selectedOption = 3;
    std::string accionRealizada;

    // Crear el mapa
    claseMap mapa1(10, 0);
    //crearMapa(mapa1, consoleSize, viewBox);
    mapa1.load("map1.txt");
    mapa1.setX(0);
    mapa1.setY(0);
    // Crear arma y personajes
    //mapa1.save("map1.txt");
    Arma arma1("Cuchillo", 2);
    std::list<personajesH> listaAliados;
    personajesH personajePrincipal = crearPersonajePrincipal(listaAliados, "Thorfinn", 3, 3, arma1);

    std::list<Arma> listaArmas;
    // Imprimir el menú inicial
    printMenu(options, 3, selectedOption, consoleSize, 2);
    // Print nuestro vida y cantidad de oro
    std::string stats1 = "Vida: "+std::to_string(listaAliados.front().getVida())+" Oro: " + std::to_string(listaAliados.front().getOro());
    printPos(stats1, 1, consoleSize.Y-10);
    std::string stats2 = "Piso: " +std::to_string(mapa1.getFloor()) + " Tiradas: " + std::to_string(tiradas);
    printPos(stats2, 2, consoleSize.Y-10);

    // Bucle para el manejo del menú
    while (true) {
        // Verificar si el tamaño de la consola ha cambiado
        if (boolSize(prevConsoleSize, consoleSize) || refresh) {
            refresh=false;
            mapa1.imprimirBox(consoleSize, viewBox);
            printMenu(options, 3, selectedOption, consoleSize, 2);
            std::string stats1 = "Vida: "+std::to_string(listaAliados.front().getVida())+" Oro: " + std::to_string(listaAliados.front().getOro());
            printPos(stats1, 1, consoleSize.Y-10);
            std::string stats2 = "Piso: " +std::to_string(mapa1.getFloor()) + " Tiradas: " + std::to_string(tiradas);
            printPos(stats2, 2, consoleSize.Y-10);
        }

        // Manejar el menú
        int opcion=manejarMenu(mapa1, consoleSize, options, selectedOption, viewBox, refresh, 3, 2);

        if (opcion == 3) {
            tiradas-=1;
            if(tiradas == -1){
                mapa1.setFloor();
                tiradas=10;
                mapa1.setX(0);
                mapa1.setY(0);
                mapa1.clearMap();
                mapa1.generarMapa();
            }
            int dado1 = setDados();
            int dado2 = setDados();

            // Mostrar los resultados de los dados en la consola
            std::string dado1String = "Dado 1: " + std::to_string(dado1);
            std::string dado2String = "Dado 2: " + std::to_string(dado2);

            int input = 0;  // Para almacenar la entrada del controlador
            bool dado1Usado = false;  // Para saber si el dado 1 fue usado
            bool dado2Usado = false;  // Para saber si el dado 2 fue usado

            // Temporizador para evitar que ambos dados se consuman a la vez
            auto ultimoMovimiento = std::chrono::steady_clock::now();

            while (!dado1Usado || !dado2Usado) {
                printPos(dado1String, consoleSize.Y / 2, consoleSize.X / 4);
                printPos(dado2String, consoleSize.Y / 2 + 1, consoleSize.X / 4);
                // Control de tiempo para evitar que se consuman los dados muy rápido
                auto ahora = std::chrono::steady_clock::now();
                std::chrono::duration<double> tiempoPasado = ahora - ultimoMovimiento;

                // Si ha pasado menos de medio segundo, no permitimos un nuevo input
                if (tiempoPasado.count() < 0.2) {
                    continue;  // Esperamos un poco antes de procesar la siguiente entrada
                }

                // Leer entrada del controlador
                input = controladorInput();

                // Mover con dado 1 si aún no se ha usado
                if (!dado1Usado) {
                    if (input == 1) {  // Abajo
                        mapa1.setY(std::min(mapa1.getY() + dado1, 9));  // Mover hacia abajo
                        dado1Usado = true;  // Marcar dado 1 como usado
                    } 
                    else if (input == 2) {  // Arriba
                        mapa1.setY(std::max(mapa1.getY() - dado1, 0));  // Mover hacia arriba
                        dado1Usado = true;
                    } 
                    else if (input == 3) {  // Izquierda
                        mapa1.setX(std::max(mapa1.getX() - dado1, 0));  // Mover a la izquierda
                        dado1Usado = true;
                    } 
                    else if (input == 4) {  // Derecha
                        mapa1.setX(std::min(mapa1.getX() + dado1, 9));  // Mover a la derecha
                        dado1Usado = true;
                    }

                    // Registrar el tiempo del último movimiento
                    ultimoMovimiento = std::chrono::steady_clock::now();
                }

                // Mover con dado 2 si el dado 1 ya fue usado
                else if (dado1Usado && !dado2Usado) {
                    if (input == 1) {  // Abajo
                        mapa1.setY(std::min(mapa1.getY() + dado2, 9));  // Mover hacia abajo
                        dado2Usado = true;  // Marcar dado 2 como usado
                    } 
                    else if (input == 2) {  // Arriba
                        mapa1.setY(std::max(mapa1.getY() - dado2, 0));  // Mover hacia arriba
                        dado2Usado = true;
                    } 
                    else if (input == 3) {  // Izquierda
                        mapa1.setX(std::max(mapa1.getX() - dado2, 0));  // Mover a la izquierda
                        dado2Usado = true;
                    } 
                    else if (input == 4) {  // Derecha
                        mapa1.setX(std::min(mapa1.getX() + dado2, 9));  // Mover a la derecha
                        dado2Usado = true;
                    }

                    // Registrar el tiempo del último movimiento
                    ultimoMovimiento = std::chrono::steady_clock::now();
                }

                // Imprimir la nueva posición del personaje en el mapa
                mapa1.imprimirBox(consoleSize, viewBox);

                // Verificar si ambos dados ya fueron utilizados
                if (dado1Usado && dado2Usado) {
                    refresh=true;

                    char casilla = mapa1.Casilla();

                    //Que pasa si caigo en casillas
                    if (casilla == 'C'){
                        int porcentaje = std::rand() % 3 + 1;
                        if(porcentaje==1){
                            //Se aumenta la vida solo el personajePrincipal
                            actualizarVidaMaxima(listaAliados);
                            accionRealizada = "Abriste un cofre y te dio vida maxima";
                        }else if(porcentaje==2){
                            //Se cura solo el personajePrincipal
                            listaAliados.front().curarVida();
                            accionRealizada = "Abriste un cofre y te cura el 10%";
                        }else if(porcentaje==3){
                            //Elegir aleatoria de la lista de Armas
                            accionRealizada = "Abriste un cofre y te obtienes un arma nueva";
                            int randomIndex = std::rand() % listaCargadaArmas.size()+1;
                            auto it = listaCargadaArmas.begin();
                            std::advance(it, randomIndex);
                            listaArmas.push_back(*it);
                        }
                    }else if (casilla == ' '){
                        accionRealizada = "Estas contemplando la vista";
                    }else if (casilla == 'E'){
                        // accionRealizada = "Accion Enemigos";
                        int posX = 0;  // Variable para la posición vertical del texto
                        //Agarrar un bicho de la lista
                        int randomIndex = std::rand()% listaCargadaEnemigos.size();
                        auto it = listaCargadaEnemigos.begin();
                        std::advance(it, randomIndex);
                        enemigos e1 = *it;
                        e1.setDamage(mapa1.getFloor());
                        e1.setVida(mapa1.getFloor());

                        int b = rand() % 2;
                        bool turnoEnemigo = (b == 1);
                        while (true) {
                            if (turnoEnemigo) {
                                // Turno del enemigo
                                std::list<personajesH>::iterator it = listaAliados.begin();
                                std::advance(it, rand() % listaAliados.size());  // Enemigo elige un aliado al azar
                                personajesH& aliadoAPegar = *it;
                                aliadoAPegar.setPunch(e1.getPunch());

                                std::string mensajeEnemigo = "El enemigo "+ e1.getNombre() +" pegó " + std::to_string(e1.getPunch()) + " a " + aliadoAPegar.getNombre();
                                printPos(mensajeEnemigo, posX++, 0);  // Imprimir mensaje y aumentar posX para la siguiente línea
                                Sleep(1000);

                                // Comprobamos si el aliado fue derrotado
                                if (aliadoAPegar.getVida() <= 0) {
                                    std::string mensajeDerrotaAliado = aliadoAPegar.getNombre() + " ha sido derrotado";
                                    printPos(mensajeDerrotaAliado, posX++, 0);
                                    listaAliados.erase(it);  // Eliminar el aliado de la lista si su vida es <= 0
                                    if (listaAliados.empty()) {
                                        printPos("Todos los aliados han sido derrotados. Perdiste.", posX++, 0);
                                    }
                                    Sleep(1000);
                                }

                            } else {
                                // Turno de los aliados
                                for (personajesH& h1 : listaAliados) {
                                    e1.setPunch(h1.getPunch());  // Cada aliado ataca al enemigo
                                    std::string mensajeAliado = h1.getNombre() + " pegó " + std::to_string(h1.getPunch()) + " al enemigo " + e1.getNombre();
                                    printPos(mensajeAliado, posX++, 0);  // Imprimir mensaje de ataque aliado
                                    Sleep(1000);
                                }

                                // Comprobamos si el enemigo fue derrotado
                                if (e1.getVida() <= 0) {
                                    printPos("Has derrotado al enemigo. ¡Ganaste!", posX++, 0);
                                    if (e1.getComp()) {
                                        listaArmas.push_back(e1.getArma());  // El enemigo deja caer su arma si la tiene
                                    }
                                    listaAliados.front().setOro(e1.getOro());  // Recompensa en oro
                                    Sleep(1000);
                                    break;
                                }
                            }

                            // Alternar turno
                            turnoEnemigo = !turnoEnemigo;

                            // Comprobar si el personaje principal ha sido derrotado
                            if (personajePrincipal.getVida() <= 0) {
                                printPos("Thorfinn murio. Fin del juego.", posX++, 0);
                                vidaCero=true;
                                Sleep(1000);
                                break;
                            }
                        }
                        Sleep(1000);
                    }else if (casilla == 'T'){
                        accionRealizada = "Accion Taberna";
                        selectedOption=6;
                        printMenu(options, 6, selectedOption, consoleSize, 2);
                        while(true){
                            if (boolSize(prevConsoleSize, consoleSize) || refresh) {
                                refresh=false;
                                mapa1.imprimirBox(consoleSize, viewBox);
                                printMenu(options, 6, selectedOption, consoleSize, 2);
                            }
                            int opcionTaberna=manejarMenu(mapa1, consoleSize, options, selectedOption, viewBox, refresh, 6, 2);
                            
                            if(opcionTaberna==6){
                                std::list<personajesH>::iterator selectMercenario = listaCargadaAliados.begin();
                                personajesH selecionadoMercenario = manejarMenuAliados(listaCargadaAliados, selectMercenario);
                                if(listaAliados.size()>3){
                                    std::list<personajesH>::iterator selectAliado = listaAliados.begin();
                                    personajesH selecionadoAliado = manejarMenuAliados(listaAliados, selectAliado);
                                    listaCargadaAliados.push_back(selecionadoAliado);
                                    listaAliados.erase(selectAliado);
                                    listaAliados.push_back(selecionadoMercenario);
                                }
                                    //Lista del disco
                                listaAliados.erase(selectMercenario);

                            }else if(opcionTaberna==7 && listaAliados.front().getOro()>0){
                                std::list<Arma>::iterator selectArma = listaArmas.begin();

                                Arma evolucionarArma = manejarMenuArmas(listaArmas, selectArma, refresh);

                                evolucionarArma.setDamage(rand() % listaAliados.front().getOro() + 1);
                                listaArmas.push_back(evolucionarArma);
                                listaAliados.front().setOro(-listaAliados.front().getOro());
                            }
                            if(opcionTaberna==8){
                                selectedOption=3;
                                refresh=true;
                                break;
                            }
                        }
                    }else if (casilla == 'S'){
                        accionRealizada = "Accion Save";
                        while(true){
                            input = controladorInput();
                            if(input==5){
                                mapa1.save("map1.txt");
                                break;
                            }else if(input==6){
                                mapa1.load("mapa1.txt");
                                break;
                            }
                        }
                    }
                    break;  // Salir del bucle
                }
            }

            // Mensaje final de la posición del personaje
        }
        if (opcion == 4) {
            asignarArmaAaliado(listaArmas, listaAliados, refresh);
        }else if (opcion == 5){
            //Salir al menu
            break;
        }

        if(vidaCero){
            //Creo que sale al menu
            break;
        }

        printPos(accionRealizada, 0, 0);

        Sleep(100);  // Pausa para no sobrecargar el procesador
    }
}


//void guardarProgreso(const std::string& nombreArchivo, int nivel, int puntaje) {
//    std::ofstream archivo(nombreArchivo);
//    if (archivo.is_open()) {
//        archivo << nivel << "\n" << puntaje << "\n";
//        archivo.close();
//    } else {
//        std::cerr << "No se pudo abrir el archivo para guardar." << std::endl;
//    }
//}  
//}