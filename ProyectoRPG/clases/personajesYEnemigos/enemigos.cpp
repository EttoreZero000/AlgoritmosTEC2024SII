#include <iostream>
#include "../Armamento/claseArmamento.h"
#include "enemigos.h"
#include "personajesPrincipales.h"

// Definir el constructor de personajesHeroes correctamente
enemigos::enemigos(): padrePersonajes("", 0, 0, false, arma, 0), comp(false) // Llamamos al constructor del padre
{
}

// Definir el constructor de personajesHeroes correctamente
enemigos::enemigos(std::string nombre, int vida, int ataque, bool tipoPersonaje, Arma arma, bool _comp, int oro)
    : padrePersonajes(nombre, vida, ataque, tipoPersonaje, arma, oro), comp(_comp) // Llamamos al constructor del padre
{
}
int enemigos::getPunch() {
    if (comp){
        return arma.getDamage() + ataque;
    }else{
        return ataque;
    }
}
void enemigos::setPunch(int damage) {
    vida-=damage;
}
Arma enemigos::getArma(){
    return arma;
}
int enemigos::getOro(){
    return oro;
}
int enemigos::getVida(){
    return vida;
}
std::string enemigos::getNombre(){
    return nombre;
}

int enemigos::getComp(){
    return comp;
}
void enemigos::setDamage(int _damage){
    ataque=_damage;
}
void enemigos::setVida(int _vida){
    vida+=_vida;
}
void enemigos::guardar(std::ofstream& out) {
    // Guardar el nombre del enemigo
    size_t len = nombre.length();
    out.write(reinterpret_cast<char*>(&len), sizeof(len));
    out.write(nombre.c_str(), len);

    // Guardar otros atributos simples como vida, ataque, oro
    out.write(reinterpret_cast<char*>(&vida), sizeof(vida));
    out.write(reinterpret_cast<char*>(&ataque), sizeof(ataque));
    out.write(reinterpret_cast<char*>(&oro), sizeof(oro));

    // Guardar atributos booleanos como tipoPersonaje y comp
    out.write(reinterpret_cast<char*>(&tipoPersonaje), sizeof(tipoPersonaje));
    out.write(reinterpret_cast<char*>(&comp), sizeof(comp));

    // Guardar el arma
    arma.guardar(out);  // Asumiendo que el objeto arma tiene un método guardar
}