#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include "claseArmamento.h"
#include "listasimple.h"

// Función para guardar el vector de Armamento en un archivo
//void guardarVector(const std::vector<Armamento>& vec, const std::string& nombreArchivo) {
//    std::ofstream archivoSalida(nombreArchivo, std::ios::binary);
//    if (archivoSalida.is_open()) {
//        for (const auto& armamento : vec) {
//            archivoSalida.write(reinterpret_cast<const char*>(&armamento.id), sizeof(armamento.id));
//
//            size_t nombreSize = armamento.nombre.size();
//            archivoSalida.write(reinterpret_cast<const char*>(&nombreSize), sizeof(nombreSize));
//            archivoSalida.write(armamento.nombre.c_str(), nombreSize);
//
//            size_t atributosSize = armamento.listaAtributos.size();
//            archivoSalida.write(reinterpret_cast<const char*>(&atributosSize), sizeof(atributosSize));
//            archivoSalida.write(reinterpret_cast<const char*>(armamento.listaAtributos.data()), atributosSize * sizeof(int));
//
//            archivoSalida.write(reinterpret_cast<const char*>(&armamento.usos), sizeof(armamento.usos));
//            archivoSalida.write(reinterpret_cast<const char*>(&armamento.tipo), sizeof(armamento.tipo));
//            archivoSalida.write(reinterpret_cast<const char*>(&armamento.disponibles), sizeof(armamento.disponibles));
//
//            size_t modificadoresSize = armamento.listaModificadores.size();
//            archivoSalida.write(reinterpret_cast<const char*>(&modificadoresSize), sizeof(modificadoresSize));
//            archivoSalida.write(reinterpret_cast<const char*>(armamento.listaModificadores.data()), modificadoresSize * sizeof(int));
//        }
//        archivoSalida.close();
//    } else {
//        std::cerr << "No se pudo abrir el archivo para guardar los datos." << std::endl;
//    }
//}
//
//// Función para cargar el vector de Armamento desde un archivo
//std::vector<Armamento> cargarVector(const std::string& nombreArchivo) {
//    std::vector<Armamento> vec;
//    std::ifstream archivoEntrada(nombreArchivo, std::ios::binary);
//    if (archivoEntrada.is_open()) {
//        while (archivoEntrada.peek() != EOF) {
//            int id;
//            std::string nombre;
//            int usos, tipo, disponibles;
//            std::vector<int> listaAtributos;
//            std::vector<int> modificadores;
//
//            archivoEntrada.read(reinterpret_cast<char*>(&id), sizeof(id));
//
//            size_t nombreSize;
//            archivoEntrada.read(reinterpret_cast<char*>(&nombreSize), sizeof(nombreSize));
//            nombre.resize(nombreSize);
//            archivoEntrada.read(&nombre[0], nombreSize);
//
//            size_t atributosSize;
//            archivoEntrada.read(reinterpret_cast<char*>(&atributosSize), sizeof(atributosSize));
//            listaAtributos.resize(atributosSize);
//            archivoEntrada.read(reinterpret_cast<char*>(listaAtributos.data()), atributosSize * sizeof(int));
//
//            archivoEntrada.read(reinterpret_cast<char*>(&usos), sizeof(usos));
//            archivoEntrada.read(reinterpret_cast<char*>(&tipo), sizeof(tipo));
//            archivoEntrada.read(reinterpret_cast<char*>(&disponibles), sizeof(disponibles));
//
//            size_t modificadoresSize;
//            archivoEntrada.read(reinterpret_cast<char*>(&modificadoresSize), sizeof(modificadoresSize));
//            modificadores.resize(modificadoresSize);
//            archivoEntrada.read(reinterpret_cast<char*>(modificadores.data()), modificadoresSize * sizeof(int));
//
//            vec.emplace_back(id, nombre, listaAtributos, usos, tipo, disponibles, modificadores);
//        }
//        archivoEntrada.close();
//    } else {
//        std::cerr << "No se pudo abrir el archivo para cargar los datos." << std::endl;
//    }
//    return vec;
//}

// Función para guardar la lista de Armamento en un archivo
void guardarListaSimple(const ListaSimple<Armamento>& lista, const std::string& nombreArchivo) {
    std::ofstream archivoSalida(nombreArchivo, std::ios::binary);
    if (archivoSalida.is_open()) {
        Nodo<Armamento>* actual = lista.getInicio();
        while (actual != nullptr) {
            const Armamento& armamento = actual->dato;

            // Guardar el ID
            archivoSalida.write(reinterpret_cast<const char*>(&armamento.id), sizeof(armamento.id));

            // Guardar el nombre
            size_t nombreSize = armamento.nombre.size();
            archivoSalida.write(reinterpret_cast<const char*>(&nombreSize), sizeof(nombreSize));
            archivoSalida.write(armamento.nombre.c_str(), nombreSize);

            // Guardar la lista de atributos
            Nodo<int>* nodoAtributo = armamento.listaAtributos.getInicio();
            size_t atributosSize = 0;
            Nodo<int>* temp = nodoAtributo;
            while (temp != nullptr) {
                atributosSize++;
                temp = temp->siguiente;
            }
            archivoSalida.write(reinterpret_cast<const char*>(&atributosSize), sizeof(atributosSize));
            while (nodoAtributo != nullptr) {
                archivoSalida.write(reinterpret_cast<const char*>(&nodoAtributo->dato), sizeof(int));
                nodoAtributo = nodoAtributo->siguiente;
            }

            // Guardar usos, tipo y disponibles
            archivoSalida.write(reinterpret_cast<const char*>(&armamento.usos), sizeof(armamento.usos));
            archivoSalida.write(reinterpret_cast<const char*>(&armamento.tipo), sizeof(armamento.tipo));
            archivoSalida.write(reinterpret_cast<const char*>(&armamento.disponibles), sizeof(armamento.disponibles));

            // Guardar la lista de modificadores
            Nodo<int>* nodoModificador = armamento.listaModificadores.getInicio();
            size_t modificadoresSize = 0;
            temp = nodoModificador;
            while (temp != nullptr) {
                modificadoresSize++;
                temp = temp->siguiente;
            }
            archivoSalida.write(reinterpret_cast<const char*>(&modificadoresSize), sizeof(modificadoresSize));
            while (nodoModificador != nullptr) {
                archivoSalida.write(reinterpret_cast<const char*>(&nodoModificador->dato), sizeof(int));
                nodoModificador = nodoModificador->siguiente;
            }

            // Mover al siguiente nodo
            actual = actual->siguiente;
        }
        archivoSalida.close();
    } else {
        std::cerr << "No se pudo abrir el archivo para guardar los datos." << std::endl;
    }
}
ListaSimple<Armamento> cargarListaSimple(const std::string& nombreArchivo) {
    ListaSimple<Armamento> lista;
    std::ifstream archivoEntrada(nombreArchivo, std::ios::binary);
    if (archivoEntrada.is_open()) {
        while (archivoEntrada.peek() != EOF) {
            int id;
            std::string nombre;
            int usos, tipo, disponibles;
            ListaSimple<int> listaAtributos;
            ListaSimple<int> listaModificadores;

            // Cargar el ID
            archivoEntrada.read(reinterpret_cast<char*>(&id), sizeof(id));

            // Cargar el nombre
            size_t nombreSize;
            archivoEntrada.read(reinterpret_cast<char*>(&nombreSize), sizeof(nombreSize));
            nombre.resize(nombreSize);
            archivoEntrada.read(&nombre[0], nombreSize);

            // Cargar la lista de atributos
            size_t atributosSize;
            archivoEntrada.read(reinterpret_cast<char*>(&atributosSize), sizeof(atributosSize));
            for (size_t i = 0; i < atributosSize; ++i) {
                int atributo;
                archivoEntrada.read(reinterpret_cast<char*>(&atributo), sizeof(int));
                listaAtributos.insertarAlFinal(atributo);
            }

            // Cargar usos, tipo y disponibles
            archivoEntrada.read(reinterpret_cast<char*>(&usos), sizeof(usos));
            archivoEntrada.read(reinterpret_cast<char*>(&tipo), sizeof(tipo));
            archivoEntrada.read(reinterpret_cast<char*>(&disponibles), sizeof(disponibles));

            // Cargar la lista de modificadores
            size_t modificadoresSize;
            archivoEntrada.read(reinterpret_cast<char*>(&modificadoresSize), sizeof(modificadoresSize));
            for (size_t i = 0; i < modificadoresSize; ++i) {
                int modificador;
                archivoEntrada.read(reinterpret_cast<char*>(&modificador), sizeof(int));
                listaModificadores.insertarAlFinal(modificador);
            }

            // Insertar el armamento cargado en la lista
            Armamento armamento(id, nombre, listaAtributos, usos, tipo, disponibles, listaModificadores);
            lista.insertarAlFinal(armamento);
        }
        archivoEntrada.close();
    } else {
        std::cerr << "No se pudo abrir el archivo para cargar los datos." << std::endl;
    }
    return lista;
}
void menu(){
    std::cout << "Menu\n1) Agregar Arma\n2) Modificar Arma\n3) Sacar Arma\n4) Evolucionar Arma\n5) Salir\nOpcion: ";
}
Armamento agregarArma() {
    std::string nombre;
    char opciones;
    int tipo, usos, disponibles, intModificadores;
    ListaSimple<int> listaAtributos;
    ListaSimple<int> listaModificadores;
    
    std::cout << "Nombre del arma: ";
    std::cin.ignore(); // Ignorar el salto de línea que queda en el buffer
    std::getline(std::cin, nombre); // Leer el nombre completo, incluyendo espacios
    
    std::cout << "Tipo de arma\n1) Lanza\n2) Espada\n3) Varita\n4) Maza\n5) Arco\n6) Hacha\nDigite una: ";
    std::cin >> tipo;
    
    std::cout << "Cuantos usos tiene: ";
    std::cin >> usos;
    
    std::cout << "Numeros disponibles: ";
    std::cin >> disponibles;
    
    const std::string nombresAtributos[] = {"Luz", "Fuego", "Tierra", "Agua", "Viento", "Oscuridad"};
    std::cout << "Atributos:\n";
    for (const auto& atributo : nombresAtributos) {
        std::cout << atributo << " (Y/N): ";
        std::cin >> opciones;
        listaAtributos.insertarAlInicio(opciones == 'y' || opciones == 'Y' ? 1 : 0);
    }

    const std::string nombresModificadores[] = {"Tiro", "Peso", "Agilidad", "Daño", "Fuerza", "Magia"};
    std::cout << "Modificadores: Ingrese un número para cada modificador\n";
    for (const auto& modificador : nombresModificadores){
        std::cout << modificador << ": ";
        std::cin >> intModificadores;
        listaModificadores.insertarAlInicio(intModificadores);
    }

    Armamento nuevaArma(nombre, listaAtributos, usos, tipo, disponibles, listaModificadores);
    return nuevaArma;
}
void modificarArma(Nodo<Armamento>* arma){
    char opciones;
    int intModificadores;
    ListaSimple<int> listaAtributos;
    ListaSimple<int> listaModificadores;
    const std::string nombresAtributos[] = {"Luz", "Fuego", "Tierra", "Agua", "Viento", "Oscuridad"};
    std::cout << "Atributos."<< std::endl;
    for (const auto& atributo : nombresAtributos) {
        std::cout << atributo << " Y/N: ";
        std::cin >> opciones;
        if (opciones == 'y' || opciones == 'Y') {
            listaAtributos.insertarAlInicio(1);
        } else {
            listaAtributos.insertarAlInicio(0);
        }
    }

    const std::string nombresModificadores[] = {"Tiro", "Peso", "Agilidad", "Daño", "Fuerza", "Magia"};
    std::cout << "Modificadores, elige un numero por cada modificación que quieras "<< std::endl;
    for (const auto& modificadores : nombresModificadores){
        std::cout << modificadores << ": ";
        std::cin >> intModificadores;
        listaModificadores.insertarAlInicio(intModificadores);
    }

    arma->dato.setAtributos(listaAtributos);
    arma->dato.setModificadores(listaModificadores);
}
void sacarArma(Nodo<Armamento>* arma){
    int unidades=0;
    std::cout << "Cuantas \""<< arma->dato.nombre <<"\" quieres sacar, hay " << arma->dato.disponibles << " disponibles: ";
    while(true){
        std::cin>> unidades;
        if (arma->dato.disponibles<unidades || unidades<=0){
            std::cout << "No hay más de " << arma->dato.disponibles << ", de " << arma->dato.nombre << std::endl;
        }else{
            std::cout << "Se esta sacando " << unidades << " de " << arma->dato.nombre << std::endl;
            arma->dato.disponibles=arma->dato.disponibles-unidades;
            break;
        }
        std::cout << "No seas tonto, cuantas quieres sacar: ";
    }
}
Armamento evolucionarArma(Nodo<Armamento>* arma){
    std::cout << "Tienes infinitas oportunidades para evolucionar esta arma que es total mente aleatorio";
    ListaSimple<int> listaModificadores;
    for(int i=0;i<7;i++){
        listaModificadores.insertarAlInicio(rand()%1000);
    }
    Armamento nuevaArma(arma->dato.nombre, arma->dato.listaAtributos, arma->dato.usos, arma->dato.tipo, 1,listaModificadores);
    return nuevaArma;
}
Nodo<Armamento>* pedirID(ListaSimple<Armamento> listaCargada){
    int id=0;
    std::cout << "Lista de armas" << std::endl;
    listaCargada.imprimir();
    std::cout << "Digite el ID: ";
    std::cin >> id;
    Nodo<Armamento>* arma = listaCargada.buscar(id);
    return arma;
}
int main() {
    srand(time(NULL));
    const std::string filename = "armamentos.dat";
    int opciones=0;
    Armamento::loadNextId();
    while(true){
        ListaSimple<Armamento> listaCargada = cargarListaSimple(filename);
        menu();
        std::cin >> opciones;
        if (opciones==1){
            Armamento arma=agregarArma();
            listaCargada.insertarAlInicio(arma);
        }else if (opciones==2)
        {
            Nodo<Armamento>* arma;
            arma=pedirID(listaCargada);
            if (arma!=nullptr){
            modificarArma(arma);
            }else{
                std::cout << "No existe ese ID" << std::endl;
            }
        }else if(opciones==3){
           Nodo<Armamento>* arma;
            arma=pedirID(listaCargada);
            if (arma!=nullptr){
            sacarArma(arma);
            }else{
                std::cout << "No existe ese ID" << std::endl;
            }
        }else if (opciones==4){
            Nodo<Armamento>* arma;
            arma=pedirID(listaCargada);
            if (arma!=nullptr){
            Armamento nuevaArma = evolucionarArma(arma);
            listaCargada.insertarAlInicio(nuevaArma);
            }else{
                std::cout << "No existe ese ID" << std::endl;
            }
        }else if (opciones==5){
            std::cout << "Guardando datos y cerrando programa";
            guardarListaSimple(listaCargada, filename);
            return 0;
        }
        else{
            std::cout << "Digite un numero valido" << std::endl;
        }
        guardarListaSimple(listaCargada, filename);
    } //while (true)
    return 0;
}
