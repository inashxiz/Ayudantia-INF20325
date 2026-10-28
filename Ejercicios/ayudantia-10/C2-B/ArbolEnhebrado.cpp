#include "ArbolEnhebrado.h"
#include <iostream>
using namespace std;

void reverseInOrden(tNodoEnhebrado *node, tNodoEnhebrado **prev) {
    if (node == NULL)
        return;

    reverseInOrden(node->der, prev);
    (*prev)->sgte = node;
    *prev = node;
    reverseInOrden(node->izq, prev);
}

void ArbolEnhebrado::enhebrar() {
    tNodoEnhebrado *prev = cabecera;
    reverseInOrden(raiz, &prev);
    prev->sgte = nullptr;
}
