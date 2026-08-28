#include "Listas.h"
#include <string>

struct Tarea{
    string nombre;
    int prioridad;

    Tarea(){
        nombre = "";
        prioridad = 0;
    }

    Tarea(string n, int p){
        nombre = n;
        prioridad = p;
    }
};

void mostrarTopTareas(tListaEnlazada<Tarea> &lt){
    int top1, top2, top3;
    top1 = top2 = top3 = 100;
    string nombre1, nombre2, nombre3;
    nombre1 = nombre2 = nombre3 = "";
    
    lt.moveToStart();
    for(int i = 0; i < lt.length(); i++){
        if(lt.getValue().prioridad < top1){
            top3 = top2;
            nombre3 = nombre2;

            top2 = top1;
            nombre2 = nombre1;

            top1 = lt.getValue().prioridad;
            nombre1 = lt.getValue().nombre;
        } else if(lt.getValue().prioridad < top2){
            top3 = top2;
            nombre3 = nombre2;

            top2 = lt.getValue().prioridad;
            nombre2 = lt.getValue().nombre;
        } else if(lt.getValue().prioridad < top3){
            top3 = lt.getValue().prioridad;
            nombre3 = lt.getValue().nombre;
        }
        lt.next();
    }

    cout << "\nTop 3 tareas con mayor prioridad: " << endl;
    cout << "1. " << nombre1 << " (Prioridad: " << top1 << ")" << endl;
    cout << "2. " << nombre2 << " (Prioridad: " << top2 << ")" << endl;
    cout << "3. " << nombre3 << " (Prioridad: " << top3 << ")" << endl;
}

void eliminarMayorPrioridad(tListaEnlazada<Tarea> &lt){
    int minPos = 0;
    int minPrio = 100;

    lt.moveToStart();
    for(int i = 0; i < lt.length(); i++){
        if(lt.getValue().prioridad < minPrio){
            minPrio = lt.getValue().prioridad;
            minPos = lt.currPos();
        }
        lt.next();
    }

    lt.moveToPos(minPos);
    string name = lt.erase().nombre;
    cout << "\nTarea eliminada: " << name << " (Prioridad: " << minPrio << ")" << endl;
}

void mostrarTareas(tListaEnlazada<Tarea> &lt){
    lt.moveToStart();
    cout << "\nTareas Pendientes: " << endl;
    for(int i = 0; i < lt.length(); i++){
        cout << "- " << lt.getValue().nombre << " (Prioridad: " << lt.getValue().prioridad << ")" << endl;
        lt.next();
    }
}


int main(){
    Tarea T("Sentinel", 100);
    tListaEnlazada Tasks(T);

    T.nombre = "Cocinar almuerzo";
    T.prioridad = 2;
    Tasks.append(T);

    T.nombre = "Estudiar";
    T.prioridad = 1;
    Tasks.append(T);

    T.nombre = "Limpiar Cocina";
    T.prioridad = 3;
    Tasks.insert(T);

    T.nombre = "Comprar jugo";
    T.prioridad = 4;
    Tasks.append(T);

    mostrarTareas(Tasks);
    mostrarTopTareas(Tasks);
    eliminarMayorPrioridad(Tasks);
    mostrarTareas(Tasks);
    
}