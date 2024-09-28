#include <iostream>
#include "../Armamento/claseArmamento.h"
#include "personajesPrincipales.h"

// Definir el constructor de personajesH correctamente
personajesH::personajesH(std::string nombre, int vida, int ataque, bool tipoPersonaje, Arma arma, int oro, int _vidaMaxima)
    : padrePersonajes(nombre, vida, ataque, tipoPersonaje, arma, oro), vidaMaxima(_vidaMaxima) // Llamamos al constructor del padre
{
}

int personajesH::getPunch() {
    return arma.getDamage() + ataque;
}
int personajesH::getVida() const{
    return vida;
}
void personajesH::setVidaMaxima(){
    vida+=1;
    vidaMaxima+=1;
}

void personajesH::setPunch(int damage) {
    vida-=damage;
}
void personajesH::setOro(int _oro){
    oro+=_oro;
}
int personajesH::getOro() const{
    return oro;
}
Arma personajesH::getArma(){
    return arma;
}
void personajesH::setArma(Arma _arma){
    arma=_arma;
}

void personajesH::curarVida(){
    if ((vidaMaxima*10)/100>0){
        if(vida+(vidaMaxima*10)/100>vidaMaxima){
            vida=vidaMaxima;
        }else{
            vida+=(vidaMaxima*10)/100;
        }
    }else {
        if(vida<vidaMaxima){
            vida+=1;
        }
    }
}

std::string personajesH::getNombre() const{
    return nombre;
}
