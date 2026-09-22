#include <iostream>
using namespace std;

template <typename tElem>
class tListaArreglo{
    private:
        int maxSize;                        // tamaño máximo de la lista
        int listSize;                       // tamaño actual de la lista
        int curr;                           // posición actual en el arreglo
        tElem *listArray;                   // arreglo con elementos de la lista
        tElem fail;                         // OPCIONAL: para indicar falla en completación de proceso
    public:
        tListaArreglo(int size, tElem f){            // constructor TDA
            maxSize = size;
            listSize = curr = 0;
            listArray = new tElem[size];
            fail = f;
        }

        ~tListaArreglo(){                   // destructor TDA
            delete[] listArray;
        }

        void clear(){                       // borra todos los elementos de la lista, dejándola vacia
            listSize = curr = 0;
        }  
                          
        int insert(tElem item){             // inserta elemento en posición actual de la lista
            if(listSize >= maxSize) return -1;

            int i;
            for(i = listSize; i > curr; i++){
                listArray[i] = listArray[i-1];
            }
            listArray[i] = item;
            return i;
        }

        int append(tElem item){             // agrega un elemento al final de la lista
            if(listSize >= maxSize) return 0;

            listArray[listSize++] = item;
            return 1;
        }
        
        tElem erase(){                      // borra el elemento actual y retorna su valor
            if(curr < 0 || curr >= listSize) return fail;

            tElem item = listArray[curr];
            for(int i = curr; i < listSize-1; i++){
                listArray[i] = listArray[i+1];
            }

            listSize--;
            return item;
        }
        
        void moveToStart(){                 // mueve la posición actual al comienzo de la lista
            curr = 0;
        }
        
        void moveToEnd(){                   // mueve la posición actual al final de la lista
            curr = listSize;
        }
        
        void moveToPos(int i){              // mueve la posición actual a la posición especificada
            if(i < 0 || i >= listSize) return;
            curr = i;   
        }
        
        void next(){                        // mueve posición actual al siguiente elemento de la lista
            if(curr >= listSize) return;
            curr++;
        }
        
        void prev(){                        // mueve posición actual al elemento anterior de la lista
            if(curr <= 0) return;
            curr--;
        }
        
        int length(){                       // retorna la cantidad de elementos en la lista
            return listSize;
        }
        
        int currPos(){                      // retorna la posición actual en la lista
            return curr;
        }
        
        tElem getValue(){                   // retorna el valor del elemento actual de la lista
            return listArray[curr];
        }
};

/*  ------------------------  */

template <typename tElem>
class tListaEnlazada{
    private:
        struct Nodo{
            tElem info;
            Nodo *sig;

            Nodo(tElem valor, Nodo *ptr = nullptr) : info(valor), sig(ptr) {}
        };

        Nodo *head;                          // nodo inicial de la lista
        Nodo *tail;                          // nodo final de la lista
        Nodo *curr;                          // nodo anterior al actual de la lista
        int listSize;                        // tamaño actual de la lista
        int pos;                             // posición actual en la lista
    public:
        tListaEnlazada(tElem Sentinel){            // constructor TDA
            head = new Nodo(Sentinel);
            tail = curr = head;
            listSize = pos = 0;
        }

        ~tListaEnlazada(){                   // destructor TDA
            clear();
            delete head;
        }

        void clear(){                       // borra todos los elementos de la lista, dejándola vacia
            Nodo *temp = head->sig;
            while(temp != nullptr){
                Nodo *toDelete = temp;
                temp = temp->sig;
                delete toDelete;
            }
            head->sig = nullptr;
            tail = curr = head;
            listSize = pos = 0;
        }  
                          
        int insert(tElem item){             // inserta elemento en posición actual de la lista
            Nodo *temp = curr->sig;
            curr->sig = new Nodo(item, temp);

            if(curr == tail) tail = curr->sig;
            listSize++;
            return pos;
        }

        int append(tElem item){             // agrega un elemento al final de la lista
            Nodo *temp = new Nodo(item);
            tail->sig = temp;
            tail = temp;
            listSize++;
            return 1;
        }
        
        tElem erase(){                      // borra el elemento actual y retorna su valor
            if(curr->sig == nullptr) return tail->info;
            Nodo *toDelete = curr->sig;
            Nodo *aux = curr->sig->sig;
            curr->sig = aux;
            tElem value = toDelete->info;

            if(toDelete == tail) tail = curr;
            delete toDelete;

            listSize--;
            return value;
        }
        
        void moveToStart(){                 // mueve la posición actual al comienzo de la lista
            curr = head;
            pos = 0;
        }
        
        void moveToEnd(){                   // mueve la posición actual al final de la lista
            curr = tail;
            pos = listSize;
        }
        
        void moveToPos(int i){              // mueve la posición actual a la posición especificada
            if(i < 0 || i >= listSize) return;
            curr = head;
            pos = 0;
            for(int j = 0; j < i; j++){
                curr = curr->sig;
                pos++;
            }   
        }
        
        void next(){                        // mueve posición actual al siguiente elemento de la lista
            if(curr == tail) return;
            curr = curr->sig;
            pos++;
        }
        
        void prev(){                        // mueve posición actual al elemento anterior de la lista
            if(curr == head) return;
            Nodo *temp = head;
            while(temp->sig != curr){
                temp = temp->sig;
            }
            curr = temp;
            pos--;
        }
        
        int length(){                       // retorna la cantidad de elementos en la lista
            return listSize;
        }
        
        int currPos(){                      // retorna la posición actual en la lista
            return pos;
        }
        
        tElem getValue(){                   // retorna el valor del elemento actual de la lista
            if(curr->sig == nullptr) return tail->info;
            return curr->sig->info;
        }
};

/*  ------------------------  */

template <typename tElem>
class tListaDobleEnlazada{
    private:
        struct Nodo{
            tElem info;
            Nodo *sig;
            Nodo *ant;

            Nodo(tElem valor, Nodo *siguiente = nullptr, Nodo *anterior = nullptr) : info(valor), sig(siguiente), ant(anterior) {}
        };

        Nodo *head;                          // nodo inicial de la lista
        Nodo *tail;                          // nodo final de la lista
        Nodo *curr;                          // nodo anterior al actual de la lista
        int listSize;                        // tamaño actual de la lista
        int pos;                             // posición actual en la lista
    public:
        tListaDobleEnlazada(tElem Sentinel){            // constructor TDA
            head = new Nodo(Sentinel);
            tail = curr = head;
            listSize = pos = 0;
        }

        ~tListaDobleEnlazada(){                   // destructor TDA
            clear();
            delete head;
        }

        void clear(){                       // borra todos los elementos de la lista, dejándola vacia
            Nodo *temp = head->sig;
            while(temp != nullptr){
                Nodo *toDelete = temp;
                temp = temp->sig;
                delete toDelete;
            }
            head->sig = nullptr;
            tail = curr = head;
            listSize = pos = 0;
        }  
                          
        int insert(tElem item){             // inserta elemento en posición actual de la lista
            Nodo *temp = curr->sig;
            curr->sig = new Nodo(item, temp, curr);
            curr->sig->sig->ant = curr->sig;

            if(curr == tail) tail = curr->sig;
            listSize++;
            return pos;
        }

        int append(tElem item){             // agrega un elemento al final de la lista
            Nodo *temp = new Nodo(item, nullptr, tail);
            tail->sig = temp;
            tail = temp;
            listSize++;
            return 1;
        }
        
        tElem erase(){                      // borra el elemento actual y retorna su valor
            if(curr->sig == nullptr) return tail->info;
            Nodo *toDelete = curr->sig;
            tElem value = toDelete->info;
            Nodo *aux = curr->sig->sig;
            aux->ant = curr;
            curr->sig = aux;

            if(toDelete == tail) tail = curr;
            delete toDelete;

            listSize--;
            return value;
        }
        
        void moveToStart(){                 // mueve la posición actual al comienzo de la lista
            curr = head;
            pos = 0;
        }
        
        void moveToEnd(){                   // mueve la posición actual al final de la lista
            curr = tail;
            pos = listSize;
        }
        
        void moveToPos(int i){              // mueve la posición actual a la posición especificada
            if(i < 0 || i >= listSize) return;
            curr = head;
            pos = 0;
            for(int j = 0; j < i; j++){
                curr = curr->sig;
                pos++;
            }   
        }
        
        void next(){                        // mueve posición actual al siguiente elemento de la lista
            if(curr == tail) return;
            curr = curr->sig;
            pos++;
        }
        
        void prev(){                        // mueve posición actual al elemento anterior de la lista
            if(curr == head) return;
            curr = curr->ant;
            pos--;
        }
        
        int length(){                       // retorna la cantidad de elementos en la lista
            return listSize;
        }
        
        int currPos(){                      // retorna la posición actual en la lista
            return pos;
        }
        
        tElem getValue(){                   // retorna el valor del elemento actual de la lista
            if(curr->sig == nullptr) return tail->info;
            return curr->sig->info;
        }
};