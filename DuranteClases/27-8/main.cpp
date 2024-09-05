#include <iostream>
#include <thread>
#include "clase.h"
#include <stack>
#include <thread>
#include <windows.h>
std::stack<Dispositivo> pila;
void cambiarEstadoLote(std::stack<Dispositivo>& pila, int cantidad, char tipoDispositivo) {
    for (int i = 0; i < cantidad; i++) {
        if (!pila.empty()) {
            Dispositivo dispositivo = pila.top();
            pila.pop();
            if (dispositivo.getTipo() == tipoDispositivo) {
                dispositivo.setEstado('D');
                std::cout << "Dispositivo " << tipoDispositivo << " con estado 'D'\n";
            } else {
                pila.push(dispositivo);
                std::cout << "Dispositivo no es del tipo " << tipoDispositivo << "\n";
            }
        } else {
            std::cout << "No hay dispositivos en la pila\n";
            break;
        }
    }
}  
void timer(int sec){
    Sleep(sec*1000);
}
void crearA(int time){
    Dispositivo nuevoDispositivo("A10",'A','C',10);
    pila.push(nuevoDispositivo);
    std::cout << "Dispositivo 'A' confeccion\n";
    timer(time);
    Dispositivo dispositivo = pila.top();
    pila.pop();
    dispositivo.setEstado('E');
    pila.push(dispositivo);
    std::cout << "Dispositivo 'A' enfriamiento\n";
    timer(1);
    Dispositivo topDispositivo = pila.top();
    pila.pop();
    topDispositivo.setEstado('P');
    pila.push(topDispositivo);
    std::cout << "Dispositivo 'A' preparado\n";
}
void crearB(int time){
    Dispositivo nuevoDispositivo("B10",'A','C',10);
    pila.push(nuevoDispositivo);
    timer(time);
    std::cout << "Dispositivo B confeccionado\n";
    Dispositivo dispositivo = pila.top();
    pila.pop();
    dispositivo.setEstado('E');
    pila.push(dispositivo);
    timer(1);
    std::cout << "Dispositivo B enfriamiento\n";
    Dispositivo topDispositivo = pila.top();
    pila.pop();
    topDispositivo.setEstado('P');
    pila.push(topDispositivo);
    std::cout << "Dispositivo B preparado\n";
}
void crearC(int time){
    Dispositivo nuevoDispositivo("C10",'A','C',10);
    pila.push(nuevoDispositivo);
    timer(time);
    std::cout << "Dispositivo C confeccionado\n";
    Dispositivo dispositivo = pila.top();
    pila.pop();
    dispositivo.setEstado('E');
    pila.push(dispositivo);
    timer(1);
    std::cout << "Dispositivo C enfriamiento\n";
    Dispositivo topDispositivo = pila.top();
    pila.pop();
    topDispositivo.setEstado('P');
    pila.push(topDispositivo);
    std::cout << "Dispositivo C preparado\n";
}
int main(){
    int numeroA=0,numeroB=0,numeroC=0, loteA=0,loteB=0,loteC=0;
    bool a=true, b=false, c=false;
    while (true){
        if (a==true){
            std::thread A(crearA, 3);
            A.join();
            numeroA++;
            if(numeroA%8==0){
                loteA++;
                cambiarEstadoLote(pila, 8, 'A');
            }
        }
        if (b==true){
            std::thread B(crearB, 4);
            B.join();
            numeroB++;
            if(numeroB%6==0){
                loteB++;
                cambiarEstadoLote(pila, 6, 'B');
            }
        }
        if (c==true){
            std::thread C(crearC, 5);
            C.join();
            numeroC++;
            if(numeroC%10==0){
                loteC++;
                cambiarEstadoLote(pila, 10, 'C');
            }
        }
    }
    return 0;
}