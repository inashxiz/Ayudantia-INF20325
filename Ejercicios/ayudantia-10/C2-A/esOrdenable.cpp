#include "tCola.h"
#include "tPila.h"

// ── El Patio de Maniobras ─────────────────────────
//
bool esOrdenable(tCola &entrada, tCola &salida) {
    tPila muerta;
    int sgte = 1;

    while (!entrada.vacia()) {
        muerta.push(entrada.frontValue());
        entrada.dequeue();

        if (muerta.topValue() == sgte) {
            while (!muerta.vacia() && muerta.topValue() == sgte) {
                salida.enqueue(muerta.topValue());
                muerta.pop();
                sgte++;
            }
        }
    }
    if (entrada.vacia() && muerta.vacia())
        return true;
    return false;
}
