#include "Lista.h"

int *distancia67(int &size) {
    // parámetro opcional, se usa para printear el resultado en el main

    int n;
    cin >> n;
    size = n;

    tLista lista;
    int *res = new int[n];

    int num, len = 0;
    int *temp = new int[n]; // arreglo temporal en el que se almacenarán los
                            // índices de los 7's
    for (int i = 0; i < n; i++) {
        cin >> num;
        lista.append(num);

        if (num == 7) {
            temp[len] = lista.length() - 1;
            len++;
        }
    }

    if (len == 0) {
        for (int i = 0; i < n; i++) {
            res[i] = -1;
        }

        delete[] temp;
        return res;
    }

    int *sevens = new int[len];
    for (int i = 0; i < len; i++) {
        sevens[i] = temp[i];
    }
    delete[] temp;

    int pos = 0;
    lista.moveToStart();
    for (int i = 0; i < n; i++) {
        if (lista.getValue() != 6) {
            res[i] = -1;
            lista.next();
            continue;
        }

        if (sevens[pos] < i && pos + 1 < len)
            pos++;
        if (pos - 1 < 0)
            res[i] = sevens[pos];
        else {
            if (abs(i - sevens[pos]) < abs(i - sevens[pos - 1]))
                res[i] = sevens[pos];
            else
                res[i] = sevens[pos - 1];
        }
        lista.next();
    }

    delete[] sevens;
    return res;
}

int main() {
    int l;
    int *r = distancia67(l);

    for (int i = 0; i < l; i++) {
        cout << r[i] << " ";
    }
    cout << endl;
    delete[] r;
    return 0;
}
