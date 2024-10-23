#include <iostream>
#include <string>

using namespace std;

void fillStr(string &str){ //i just like to use references... as a java user, they are like magic to me
    cout << "Enter a string: " << endl;
    getline(cin, str);
}

int main(){
    string a,b;
    cout << "You will enter two strings.\nThe first one is the source string and the second string is the target string.";
    fillStr(a);
    fillStr(b);
    int occurences = 0;
    int index = 0;
    index = a.find(b, index);
    while(index != string::npos){
        cout << "Found an occurence at index " << index << endl;
        occurences++;
        index = a.find(b, index + b.length());
    }
    cout << "Total found: " << occurences << endl;
    return 0;
}