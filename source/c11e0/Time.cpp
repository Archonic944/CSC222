#include <iostream>
#include "Time.h"
using namespace std;

Time::Time(int h, int m, double s) {
    hour = h;
    minute = m;
    second = s;
    cout << "Double constructor called" << endl;
}

Time::Time(int h, int m, int s){
    hour = h;
    minute = m;
    second = s;
    cout << "Int constructor called" << endl;
}

Time::Time(double secs) {
    hour = int(secs / 3600.0);
    secs -= hour * 3600.0;
    minute = int(secs / 60.0);
    secs -= minute * 60;
    second = secs;
}

void Time::increment(double secs) {
    second += secs;
    minute += second / 60.0;
    hour += minute / 60;
    second = fmod(second, 60.0);
    minute = fmod(minute, 60.0);
}

void Time::print() const {
    cout << hour << ":" << minute << ":" << second << endl;
}

bool Time::after(const Time& t2) const {
    if (hour > t2.hour) return true;
    if (hour < t2.hour) return false;

    if (minute > t2.minute) return true;
    if (minute < t2.minute) return false;

    return (second > t2.second);
}

Time Time::add(const Time& t2) const {
    return Time(convert_to_seconds() + t2.convert_to_seconds());
}

double Time::convert_to_seconds() const {
    return (hour * 60 + minute) * 60 + second;
}
