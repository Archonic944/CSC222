//
// Created by Cohen, Gabriel on 9/25/24.
//
#include <iostream>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

struct DOG {
    int paws;
    int age;
};

void age_dog(DOG *d) {
    int* p = nullptr;
    p = &d->age;
    (*p)++;
}

void mutate_dog(DOG *d) {
    int* p = 0;
    p = &d->age;
    (*(p-1))++;
}

int main() {
    DOG v = {4, 3};
    cout << "The dog is aging..." << endl;
    age_dog(&v);
    cout << "The dog is now " << v.age << " years old." << endl;
    cout << "The dog is mutating..." << endl;
    mutate_dog(&v);
    cout << "The dog now has " << v.paws << " paws." << endl;
}