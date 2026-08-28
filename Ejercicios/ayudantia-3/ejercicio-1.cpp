#include "Listas.h"
#include <ctime>
#include <cstdlib>

void mostrarNotas(tListaArreglo<int> &la){
    la.moveToStart();
    cout << "\nNotas:"<< endl;
    for(int i = 0; i < la.length(); i++){
        cout << la.getValue() << endl;
        la.next();
    }
}

int* obtenerNotasReprobadas(tListaArreglo<int> &la, int &size){
    la.moveToStart();
    int temp[50];
    for(int i = 0; i < la.length(); i++){
        if(la.getValue() < 55){
            temp[size] = la.getValue();
            size++;
        }
        la.next();
    }

    int *res = new int[size];
    for(int i = 0; i < size; i++){
        res[i] = temp[i];
    }

    return res;
}

int obtenerPromedioNotas(tListaArreglo<int> &la){
    la.moveToStart();
    int sum = 0;
    for(int i = 0; i < la.length(); i++){
        sum += la.getValue();
        la.next();
    }

    int prom = sum/la.length();
    return prom;
}

int main(){
    tListaArreglo<int> Notas(50, -1);
    for(int i = 0; i < 50; i++){
        int randInt = rand()%101;
        Notas.append(randInt);
        Notas.next();
    }

    mostrarNotas(Notas);

    int size = 0;
    int *reprobadas = obtenerNotasReprobadas(Notas, size);
    cout << "\nNotas reprobadas:" << endl;
    for(int i = 0; i < size; i++){
        cout << reprobadas[i] << endl;
    }

    delete[] reprobadas;

    cout << "\nPromedio de Notas:\n" << obtenerPromedioNotas(Notas) << endl;
}