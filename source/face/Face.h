#include <string>
#include <iostream>
using namespace std;

struct Face {
    string to_string();
    string getEmotion();
    void setEmotion(string emotion);

    string emotion;
};