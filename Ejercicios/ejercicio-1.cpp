#include <iostream>
using namespace std;

int main(){
    int n = 5;
    int arr[5] = {1, 7, 4, 2, 5};
    int even = 0, odd = 0;
    for(int i = 0; i < n; i++){
        if(arr[i]%2 == 0){
            even += arr[i];
        } else {
            odd += arr[i];
        }
    }

    cout << "Suma de pares: " << even << endl;
    cout << "Suma de impares: " << odd << endl;
    return 0;
}