#include <iostream>
using namespace std;

int main(){
    int numbers[] = {1, 2, 3, 4, 5, 6, 7};
    int auxiliary;
    for(int i = 0; i < 3; i++) {
        auxiliary = numbers[i];
        numbers[i] = numbers[6 - i];
        numbers[6 - i] = auxiliary;
        for(int i = 0; i < 7; i++) {
            cout << numbers[i] << " ";
        }
        cout << endl;
    }
    for(int i = 0; i < 7; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
}