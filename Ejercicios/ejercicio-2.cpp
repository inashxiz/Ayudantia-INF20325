#include <iostream>
#include <string>
#define endl '\n'
using namespace std;


void printArray(char *arr, int size){
    for(int i = 0; i < size; i++){
        cout << arr[i];
    }
    cout << endl;
}

char* append(char *original, string palabra, int n){
    int largo_p = palabra.length();
    int new_size = n + largo_p;
    char *new_p = new char[new_size];

    for(int i = 0; i < n; i++){
        new_p[i] = original[i];
    }

    for(int j = n; j < new_size; j++){
        new_p[j] = palabra[j-n];
    }

    printArray(new_p, new_size);
    return new_p;
}

char* insert(char *og, string pal, int n, int idx){
    int len = pal.length();
    int new_len = n+len;
    char *new_a = new char[new_len];

    for(int i = 0; i < idx; i++){
        new_a[i] = og[i];
    }

    for(int j = idx; j < idx+len; j++){
        new_a[j] = pal[j - idx];
    }

    for(int k = idx+len; k < new_len; k++){
        new_a[k] = og[k-len];
    }

    printArray(new_a, new_len);
    return new_a;
}

int main(){
    char p[] = "hola";
    char *app = append(p, "mundo", 4);
    char *ins = insert(app, " ", 9, 4);

    delete[] app;
    delete[] ins;
    return 0;
}