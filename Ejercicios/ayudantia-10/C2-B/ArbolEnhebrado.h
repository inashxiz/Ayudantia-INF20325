#include <iostream>
using namespace std;
typedef int tipoElem;


struct tNodoEnhebrado
{
    tipoElem info;
    tNodoEnhebrado *izq;
    tNodoEnhebrado *der;
    tNodoEnhebrado *sgte;
} typedef tNodoEnhebrado;

class ArbolEnhebrado
{
private:
    tNodoEnhebrado *raiz;
    tNodoEnhebrado *cabecera;
    int nElements;
    void destruir(tNodoEnhebrado *a){
        if (a == nullptr)
        return;
        destruir(a->izq);
        destruir(a->der);

        delete a;
    };    

public:
    ArbolEnhebrado(){
        raiz = nullptr;
        cabecera = new tNodoEnhebrado;
    };
    ~ArbolEnhebrado(){
        destruir(raiz);
        raiz = nullptr;
        delete cabecera;
    };
    void insertar(tipoElem x){tNodoEnhebrado *nuevo = new tNodoEnhebrado;
        nuevo->info = x;
        nuevo->izq = nullptr;
        nuevo->der = nullptr;
        nuevo->sgte = nullptr;
        if (raiz == nullptr)
        {
            raiz = nuevo;
            return;
        }

        tNodoEnhebrado *actual = raiz;
        tNodoEnhebrado *padre = nullptr;

        while (actual != nullptr)
        {
            padre = actual;

            if (x < actual->info)
            {
                actual = actual->izq;
            }
            else if (x > actual->info)
            {
                actual = actual->der;
            }
            else
            {
                delete nuevo;
                return;
            }
        }

        if (x < padre->info)
        {
            padre->izq = nuevo;
        }
        else
        {
            padre->der = nuevo;
        }
    };
    void recorrerEnhebrado(){
        if (cabecera == nullptr)
        {
            cout << "[°] Arbol Vacio" << endl;
        }
        tNodoEnhebrado *aux = cabecera->sgte;
        while (aux != nullptr)
        {
            cout << aux->info << " ";
            aux = aux->sgte;
        }
    };
    void enhebrar();
};