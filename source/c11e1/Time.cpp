#include "Time.h"
#include <iostream>
#include <string>

using namespace std;

Time::Time(int ss){
    s = ss;
}

Time::Time(int h, int m, int ss){
    s = ss + (m * 60) + (h * 3600);
}

Time::Time(int h, int m){
    s = h * 3600 + m * 60;
}

Time::Time(){
    s = 0;
}

Time Time::operator+(Time &t){
    return Time();
}

string Time::to_string(){
    int m = s/60;
    int h = m/60;
    string s_str = std::to_string(s%60);
    if(s_str.length() == 1) s_str = "0" + s_str;
    string m_str = std::to_string(m%60);
    if(m_str.length() == 1) m_str = "0" + m_str;
    return std::to_string(h) + ":" + m_str + ":" + s_str;
}