#include "utils.h"

int generarId() {
    static int id = 1;
    return id++;
}
