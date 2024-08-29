#include "clase.h"
#include <iostream>
#include <string>

Dispositivo::Dispositivo(std::string ID, char Tipo, char Estado, int Pureza)
    : ID(ID), Tipo(Tipo), Estado(Estado), Pureza(Pureza) {
}
void Dispositivo::setID(std::string _ID){
    ID=_ID;
}
void Dispositivo::setTipo(char _Tipo){
    Tipo=_Tipo;
}
void Dispositivo::setEstado(char _Estado){
    Estado=_Estado;
}
void Dispositivo::setPureza(int _Pureza){
    Pureza=_Pureza;
}
std::string Dispositivo::getID(){
    return ID;
}
char Dispositivo::getTipo(){
    return Tipo;
}
char Dispositivo::getEstado(){
    return Estado;
}
int Dispositivo::getPureza(){
    return Pureza;
}

//std::ostream& operator<<(std::ostream& os, const Dispositivo& armamento) {
//    armamento.imprimir();
//    return os;
//}