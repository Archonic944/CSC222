//
// Created by Cohen, Gabriel on 10/1/24.
//

#include <iostream>
#include <string>

using namespace std;

int occurences(string &str, const char target[], int pos=0) {
    return pos == string::npos ?
        0 :
        1 + occurences(str, target, pos + sizeof(target));
}

int main() {
    string str = "hh ghue bbijehhf e bh fnehh";
    cout << occurences(str, "h") << endl;
}
