#include <iostream>
#include "Fraction.h"

using namespace std;

string Fraction::to_string() {
    return std::to_string(num) + "/" + std::to_string(den);
}

Fraction Fraction::plus(Fraction f) {
    int n = this->num * f.den + f.num * this->den;
    int d = f.den * this->den;
    return Fraction(n, d);
}

Fraction::Fraction(int n, int d) {
    num = n;
    den = d;
}

Fraction::Fraction() {
    num = 0;
    den = 1;
}

Fraction Fraction::minus(Fraction f){
    
}