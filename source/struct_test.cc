#include <iostream>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

void sleep(int ms){
    this_thread::sleep_for(std::chrono::milliseconds(ms));
}

void typewriter_print(string msg){
    for(int i = 0; i<msg.length(); i++){
        cout << msg[i];
        cout.flush();
        sleep(50);
    }
    cout << endl;
}

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

    if(v.gpa < 4.0){
        typewriter_print("Bad dog!");
        v.gpa++;
        typewriter_print("There, I fixed it. Woo, grade inflation!");
    }else{
        typewriter_print("Good dog!");
    }
    return 0;
}