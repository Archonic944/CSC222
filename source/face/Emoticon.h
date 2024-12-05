#include <string>
#include <iostream>
#pragma once
using namespace std;

//courtesy of emojidb.org
extern vector<string> FACE_LIST;

struct Emoticon {
    string to_string();
    string getEmotion();
    void setEmotion(string);

    int happiness; //Happiness on a scale of 0-10

    Emoticon(int);
};