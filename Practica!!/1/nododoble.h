#ifndef NODODOBLE_H
#define NODODOBLE_H

#include "juguete.h"

struct NodoDoble {
    Juguete dato;
    NodoDoble* siguiente;
    NodoDoble* anterior;

    NodoDoble(const Juguete& juguete) : dato(juguete), siguiente(nullptr), anterior(nullptr) {}
};

#endif
