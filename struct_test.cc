#include <iostream>
#include <string>

using namespace std;

int main(){
    struct DOG {
        string name;
        int age;
        float gpa;
    };

    struct DOG v;
    cin >> v.name;
    cin >> v.age;
    cin >> v.gpa;

    if(v.gpa < 4.0) cout << "Bad dog!" << endl;
    return 0;
}