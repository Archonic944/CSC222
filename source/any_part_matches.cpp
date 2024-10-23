//
// Created by Cohen, Gabriel on 9/27/24.
//


#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void fill_int(int& any) {
    cin >> any;
}

int main() {
    string s1;
    string s2;
    cout << "Please enter two strings." << endl;
    cin >> s1;
    cin >> s2;
    int len;
    fill_int(len);
    cout << len + 5;
}