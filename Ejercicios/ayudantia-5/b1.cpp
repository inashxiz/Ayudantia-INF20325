#include "Lista-D.h"

void tLista::revertirPares() {
    Nodo *actual = head->sig;
    while (actual != nullptr) {
        if (actual->info % 2 != 0) {
            actual = actual->sig;
            continue;
        }

        Nodo *inicio = actual;
        Nodo *fin = actual;

        while (fin->sig != nullptr && fin->sig->info % 2 == 0) {
            fin = fin->sig;
        }

        Nodo *antes = inicio->ant;
        Nodo *despues = fin->sig;
        if (inicio != fin) {
            Nodo *p = inicio;

            while (p != despues) {
                Nodo *next = p->sig;
                p->sig = p->ant;
                p->ant = next;
                p = next;
            }

            antes->sig = fin;
            fin->ant = antes;
            inicio->sig = despues;

            if (despues != nullptr) {
                despues->ant = inicio;
            } else {
                tail = inicio;
            }
        }
        actual = despues;
    }
}

int main() {
    tLista lista;
    int n;
    cin >> n;

    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        lista.append(num);
    }

    lista.revertirPares();
    for (lista.moveToStart(); lista.currPos() < lista.length(); lista.next()) {
        cout << lista.getValue() << " ";
    }
    cout << endl;
    return 0;
}
