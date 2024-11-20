#ifndef TIME_H
#define TIME_H

struct Time {
    // instance variables
    int hour, minute;
    double second;

    // constructors
    Time(int h, int m, double s);
    Time(double secs);

    // modifiers
    void increment(double secs);

    // functions
    void print() const;
    bool after(const Time& t2) const;
    Time add(const Time& t2) const;
    double convert_to_seconds() const;
};

#endif