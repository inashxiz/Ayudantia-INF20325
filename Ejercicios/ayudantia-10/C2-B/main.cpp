#include <iostream>
#include "ArbolEnhebrado.h"

using namespace std;

int main()
{
    ArbolEnhebrado arbol;
    int n, aux;
    cin >> n;
    while (n != 0)
    {
        cin >> aux;
        arbol.insertar(aux);
        n--;
    }
    arbol.enhebrar();
    arbol.recorrerEnhebrado();
    return 0;
}