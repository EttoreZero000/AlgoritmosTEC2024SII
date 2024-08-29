#include <iostream>
#include <thread>
#include "clase.h"
#include <stack>
#include <windows.h>
void timer(int sec){
    Sleep(sec*1000);
}
bool Dividir(int numero, int segundo){
    if((segundo % numero == 0) && (segundo!=0)){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    std::stack<Dispositivo> pila;   
    int tiempo=0;
    char tipo=0;
    bool cambio=true, A=false, B=false, C=false;
    std::string ID;
    while (true){
        if(cambio){
            std::cout << "Elija una de estas opciones.\nA \nB \nC"; 
            std::cin  >> tipo;
        }
        timer(1);
        tiempo++;
        if(Dividir(3,tiempo) && tipo=='A' || A==true){
            A=true;
            ID = "A"+tiempo;
            Dispositivo DispositivoA(ID,'A','C',rand()%11);
            timer(3);
            DispositivoA.setEstado('E');
        }
        if(Dividir(4,tiempo) && tipo=='B'){
            B=true;
            ID = "B"+tiempo;
            Dispositivo DispositivoA(ID,'B','C',rand()%11);
        }
        if(Dividir(5,tiempo) && tipo=='C'){
            C=true;
            ID = "C"+tiempo;
            Dispositivo DispositivoA(ID,'C','C',rand()%11);
        }
    }
    return 0;
}

//thread