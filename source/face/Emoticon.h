#include <string>
#include <iostream>
#pragma once
using namespace std;

//courtesy of emojidb.org


struct Emoticon {
    static vector<string> FACE_LIST;
    string to_string();
    string getEmotion();
    void setEmotion(string);
    void make_happier();
    void make_sadder();

    int happiness; //Happiness on a scale of 0-10

    Emoticon(int);
};