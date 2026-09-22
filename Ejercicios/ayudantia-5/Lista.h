#include <iostream>
using namespace std;

class tLista {
  private:
    struct Nodo {
        int info;
        Nodo *sig;
        Nodo(int valor, Nodo *ptr = nullptr) : info(valor), sig(ptr) {};
    };

    Nodo *head;
    Nodo *tail;
    Nodo *curr;
    int listSize;
    int pos;

  public:
    tLista() {
        head = new Nodo(0);
        tail = curr = head;
        listSize = pos = 0;
    }

    ~tLista() {
        clear();
        delete head;
    }

    void clear() {
        Nodo *temp = head->sig;
        while (temp != nullptr) {
            Nodo *toDelete = temp;
            temp = temp->sig;
            delete toDelete;
        }
        head->sig = nullptr;
        tail = curr = head;
        listSize = pos = 0;
    }

    int insert(int item) {
        Nodo *temp = curr->sig;
        curr->sig = new Nodo(item, temp);

        if (curr == tail)
            tail = curr->sig;
        listSize++;
        return pos;
    }

    int append(int item) {
        Nodo *temp = new Nodo(item);
        tail->sig = temp;
        tail = temp;
        listSize++;
        return 1;
    }

    int erase() {
        if (curr->sig == nullptr)
            return 0;
        Nodo *toDelete = curr->sig;
        Nodo *aux = curr->sig->sig;
        curr->sig = aux;
        int value = toDelete->info;

        if (toDelete == tail)
            tail = curr;
        delete toDelete;
        listSize--;
        return value;
    }

    void moveToStart() {
        curr = head;
        pos = 0;
    }

    void moveToEnd() {
        curr = tail;
        pos = listSize;
    }

    void moveToPos(int i) {
        if (i < 0 || i >= listSize)
            return;
        curr = head;
        pos = 0;
        for (int j = 0; j < i; j++) {
            curr = curr->sig;
            pos++;
        }
    }

    void next() {
        if (curr == tail)
            return;
        curr = curr->sig;
        pos++;
    }

    void prev() {
        if (curr == head)
            return;
        Nodo *temp = head;
        while (temp->sig != curr) {
            temp = temp->sig;
        }
        curr = temp;
        pos--;
    }

    int length() { return listSize; }

    int currPos() { return pos; }

    int getValue() {
        if (curr->sig == nullptr)
            return -1;
        return curr->sig->info;
    }
};
