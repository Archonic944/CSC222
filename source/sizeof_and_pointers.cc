#include <iostream>

using namespace std;

float do_shit(float *a){
    (*a)++;
    //return a value
    return *a;
}

int main(){
    int a = 5, *b = &a;
    cout << "Sizes: " << endl;
    cout << sizeof(char) << endl;
    cout << sizeof a << endl;
    cout << sizeof(b) << endl;
    cout << sizeof(char(1)) << endl << endl;

    
    int c[] = {25, 2, 3, 4, 5};
    int* d = &c[0];
    (*d)++;
    cout << *d << endl;

    float hello=5, *hellop = &hello;
    do_shit(hellop);
    cout << hello << endl;
    return 0;
}