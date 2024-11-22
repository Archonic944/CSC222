#ifndef TIME_H
#define TIME_H
#include <string>
using namespace std;

struct Time {
    int s;
    Time(int secs);
    Time(int h, int m, int s);
    Time(int h, int m);
    Time();
    string to_string();
};

#endif