#include <string>

struct Fraction {
    int num;
    int den;

    Fraction(std::string s);
    Fraction(int n, int d);
    Fraction(int n);
    Fraction();

    //NOTE: I decided to implement to_string instead of print because it's easier to test
    std::string to_string();

    Fraction plus(Fraction f);
    Fraction minus(Fraction f);
    Fraction times(Fraction f);
    Fraction divided_by(Fraction f);

    bool operator>(const Fraction& f) const;
    bool operator<(const Fraction& f) const;
    bool operator>=(const Fraction& f) const;
    bool operator<=(const Fraction& f) const;
    bool operator==(const Fraction& f) const;
    bool operator!=(const Fraction& f) const;

    // Comparison operators with integers
    bool operator>(int value) const;
    bool operator<(int value) const;
    bool operator>=(int value) const;
    bool operator<=(int value) const;
    bool operator==(int value) const;
    bool operator!=(int value) const;

    Fraction operator+(const Fraction& f) const;
    Fraction operator*(const Fraction& f) const;
    Fraction operator-(const Fraction& f) const;
    Fraction operator/(const Fraction& f) const;

    bool equals(const Fraction& f) const;
};