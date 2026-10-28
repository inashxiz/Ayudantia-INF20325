// ─────────────────────────────────────────────────────────────────────────────
//  CERTAMEN 2 — Pilas y Colas
//  A2 – El Patio de Maniobras
//  INF-20325 Estructuras de Datos | UTFSM 2026-2
// ─────────────────────────────────────────────────────────────────────────────

#include <iostream>
#include "tCola.h"
#include "tPila.h"

bool esOrdenable(tCola& entrada, tCola& salida);   // implementada en esOrdenable.cpp

int main() {
    int n;
    std::cin >> n;

    tCola entrada;
    for (int i = 0; i < n; i++) {
        int v;
        std::cin >> v;
        entrada.enqueue(v);
    }

    tCola salida;
    if (esOrdenable(entrada, salida)) {
        std::cout << "SI" << std::endl;
        salida.print();
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}
