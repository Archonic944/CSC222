#include <string>
#include <iostream>

using namespace std;

bool is_letter(char c){
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int main(){
    cout << "Enter a string: " << endl;
    string word;
    int count = 0;
    while(getline(cin, word, ' ')){
       for(int i = 0; i<word.length(); i++){
            char c = word[i];
            if(is_letter(c)){
                count++;
                break;
            }
       }
    }
    return 0;
}