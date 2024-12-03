#include <string>
#include <iostream>
using namespace std;

struct Face {
    string to_string();
    string getEmotion();
    void setEmotion(string);

    int happiness; //Happiness on a scale of 0-10

    Face(int);
};